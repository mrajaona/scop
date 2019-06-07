NAME		=	scop

GLWF_INC	=	/Users/mrajaona/.brew/Cellar/glfw/3.3/include/

DIR_INC		=	./inc/
DIR_SRC		=	./src/

DIR_MAIN	=	scop/
SRC_MAIN	=	data.c \
				init_ext.c \
				scop.c \
				set_data.c \
				show.c \
				texture.c \
				use_model.c \
				lookat.c \
				perspective.c \
				orthographic.c \
				shader_status.c

SRCS_MAIN	=	$(addprefix	$(DIR_MAIN), $(SRC_MAIN))

DIR_MATRIX	=	matrix/
SRC_MATRIX	=	angle.c \
				coord.c \
				coord_op.c \
				mat4.c \
				mat4_op.c \
				mat4_rotate.c \
				mat4_transform.c \
				mat4_vect_prod.c \
				vector.c \
				vector_op.c

SRCS_MATRIX	=	$(addprefix	$(DIR_MATRIX), $(SRC_MATRIX))

DIR_IMAGE	=	image/
SRC_IMAGE	=	img.c \
				img_bmp.c

SRCS_IMAGE	=	$(addprefix	$(DIR_IMAGE), $(SRC_IMAGE))

DIR_MODEL	=	model/
SRC_MODEL	=	model.c \
				model_shader.c \
				read_model.c \
				read_obj.c \
				read_mtl.c \
				process_model.c \
				list.c

SRCS_MODEL	=	$(addprefix	$(DIR_MODEL), $(SRC_MODEL))

DIR_MORE_INC	=	more/
MORE_INC		=	data_struct.h \
					shader_struct.h \
					model_struct.h \
					glfw_inc.h

MORE_INCS		=	$(addprefix	$(DIR_MORE_INC), $(MORE_INC))

SRC			=	$(SRCS_MAIN) $(SRCS_MATRIX) $(SRCS_IMAGE) \
				$(SRCS_MODEL) $(SRCS_LIGHT)
INC			=	$(SRC:.c=.h) $(MORE_INCS)

INCS		=	$(addprefix $(DIR_INC), $(INC))
SRCS		=	$(addprefix $(DIR_SRC), $(SRC))

DIRS		=	$(DIR_MAIN) \
				$(DIR_MATRIX) \
				$(DIR_IMAGE) \
				$(DIR_MODEL) \
				$(DIR_MORE_INC)
DIRS_INC	=	$(addprefix -I$(DIR_INC), $(DIRS))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror $(DIRS_INC) -I$(GLWF_INC)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(OBJS)
				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) $(OBJS) -L./lib/ -framework OpenGL \
				`pkg-config --static --libs glfw3`
				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) "\033[31m> Directory cleaned\033[0m\n"

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) "\033[31m> Removed executable\033[0m\n"

re		:		fclean all

.PHONY	:		all clean fclean re

.DEFAULT_GOAL	:=	all
