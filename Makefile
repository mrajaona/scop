NAME		=	scop

DIR_INC		=	./inc/
INC			=	

DIR_SRC		=	./src/

DIR_MAIN	=	./
SRC_MAIN	=	tuto.c
SRCS_MAIN	=	$(addprefix	$(DIR_MAIN), $(SRC_MAIN))

SRC			=	$(SRCS_MAIN)

INCS		=	$(addprefix $(DIR_INC), $(INC))
SRCS		=	$(addprefix $(DIR_SRC), $(SRC))

OBJS		=	$(SRCS:.cpp=.o)

CFLAGS		=	-Wall -Wextra -Werror -I$(DIR_INC)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(INCLUDE) $(OBJ)
				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) $(OBJS) \
				`pkg-config --static --libs glfw3`
				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) "\033[31m> Directory cleaned\033[0m\n"

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) "\033[31m> Removed executable\033[0m\n"

re		:		fclean all

linux-setup	:
				sudo apt update
				sudo apt upgrade
				sudo apt install libx11-dev
				sudo apt install xorg-dev libglu1-mesa-dev

linux-lib	:
				cd glfw
				cmake glfw
				cd -
				make -C glfw
				sudo make -C glfw install

macos-setup	:
				xcode-select --install
				brew reinstall cmake
				brew reinstall glfw3

submodule	:
				git submodule update --init --recursive

.PHONY	:		all clean fclean re \
				linux-setup macos-setup install-lib submodule

.DEFAULT_GOAL	:=	all
