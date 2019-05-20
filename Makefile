NAME		=	scop

DIR_INC		=	./inc/
DIR_SRC		=	./src/

DIR_MAIN	=	scop/
SRC_MAIN	=	arrays.c \
				data.c \
				img.c \
				img_bmp.c \
				init_ext.c \
				scop.c \
				set_data.c \
				shader.c \
				show.c \
				texture.c

SRCS_MAIN	=	$(addprefix	$(DIR_MAIN), $(SRC_MAIN))

DIR_MATRIX	=	matrix/
SRC_MATRIX	=	angle.c \
				coord.c \
				coord_op.c \
				lookat.c \
				mat4.c \
				mat4_op.c \
				mat4_rotate.c \
				mat4_transform.c \
				mat4_vect_prod.c \
				perspective.c \
				vector.c \
				vector_op.c

SRCS_MATRIX	=	$(addprefix	$(DIR_MATRIX), $(SRC_MATRIX))

DIR_MORE_INC	=	scop/
MORE_INC		=	data_struct.h \
					shader_struct.h

MORE_INCS		=	$(addprefix	$(DIR_MORE_INC), $(MORE_INC))

SRC			=	$(SRCS_MAIN) $(SRCS_MATRIX)
INC			=	$(SRC:.c=.h) $(MORE_INCS)

INCS		=	$(addprefix $(DIR_INC), $(INC))
SRCS		=	$(addprefix $(DIR_SRC), $(SRC))

DIRS		=	$(DIR_MAIN) $(DIR_MATRIX)
DIRS_INC	=	$(addprefix -I$(DIR_INC), $(DIRS))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror $(DIRS_INC) -I./lib

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(OBJS)
				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) $(OBJS) -lGLEW -lGLU -lGL -lSOIL \
				`pkg-config --static --libs glfw3`
				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) "\033[31m> Directory cleaned\033[0m\n"

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) "\033[31m> Removed executable\033[0m\n"

re		:		fclean all

submodule	:
				git submodule update --init --recursive

.PHONY	:		all clean fclean re \
				submodule

.DEFAULT_GOAL	:=	all
