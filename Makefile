NAME		=	scop

GLWF_INC	=	/Users/mrajaona/.brew/Cellar/glfw/3.3/include/

DIR_INC		=	./inc/
INC			=	common.h \
				error.h \
				exit.h \
				gl_loader.h \
				glfw.h \
				img_loader.h \
				matrix.h \
				object.h \
				scop.h \
				shader.h \
				show.h \
				texture.h

DIR_SRC		=	./src/

DIR_MAIN	=	./
SRC_MAIN	=	exit.c \
				scop.c \
				glfw_init.c \
				texture.c \
				show.c
SRCS_MAIN	=	$(addprefix	$(DIR_MAIN), $(SRC_MAIN))

DIR_OBJECT	=	./objects/
SRC_OBJECT	=	vertex_buffer_objects.c \
				vertex_array_objects.c \
				element_array_buffer.c
SRCS_OBJECT	=	$(addprefix	$(DIR_OBJECT), $(SRC_OBJECT))

DIR_SHADER	=	./shader/
SRC_SHADER	=	shader_program.c
SRCS_SHADER	=	$(addprefix	$(DIR_SHADER), $(SRC_SHADER))

DIR_MATRIX	=	./matrix/
SRC_MATRIX	=	matrix.c
SRCS_MATRIX	=	$(addprefix	$(DIR_MATRIX), $(SRC_MATRIX))

SRC			=	$(SRCS_MAIN) $(SRCS_OBJECT) $(SRCS_SHADER) $(SRCS_MATRIX)

INCS		=	$(addprefix $(DIR_INC), $(INC))
SRCS		=	$(addprefix $(DIR_SRC), $(SRC))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I$(DIR_INC) -I$(GLWF_INC) -I./lib

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(OBJS)

				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) $(OBJS) -L./lib/ -lSOIL -lGLEW -framework OpenGL \
				`pkg-config --static --libs glfw3`

				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) "\033[31m> Directory cleaned\033[0m\n"

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) "\033[31m> Removed executable\033[0m\n"

re		:		fclean all

setup	:
				xcode-select --install
				brew reinstall cmake
				brew reinstall glfw3

submodule	:
				git submodule update --init --recursive

.PHONY	:		all clean fclean re \
				setup submodule

.DEFAULT_GOAL	:=	all

#	export DYLD_LIBRARY_PATH="~/.brew/Cellar/glfw/3.3/lib:$DYLD_LIBRARY_PATH"
#	export PATH="~/.brew/Cellar/glfw/3.3/include/:$PATH"