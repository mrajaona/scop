NAME		=	scop

DIR_INC		=	./inc/
INC			=	tuto.h

DIR_SRC		=	./src/

DIR_MAIN	=	./
SRC_MAIN	=	tuto.c \
				vertex_buffer_objects.c \
				shader_program.c \
				vertex_array_objects.c
SRCS_MAIN	=	$(addprefix	$(DIR_MAIN), $(SRC_MAIN))

SRC			=	$(SRCS_MAIN)

INCS		=	$(addprefix $(DIR_INC), $(INC))
SRCS		=	$(addprefix $(DIR_SRC), $(SRC))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I$(DIR_INC)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(OBJS)
				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) $(OBJS) -lGLEW -lGLU -lGL \
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
