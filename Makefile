NAME		=	tuto

SRC			=	src/tuto.cpp

OBJS		=	$(SRC:.cpp=.o)

CC			=	/usr/bin/clang++
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(INCLUDE) $(OBJ)
				$(CC) `pkg-config --cflags glfw3` \
				-o $(NAME) src/tuto.cpp \
				`pkg-config --static --libs glfw3` \
				-std=c++11 -lpthread
				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJ)
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
				@$(ECHO) "GLFW : install XCode + CMake"
				brew install glfw3

.PHONY	:		all clean fclean re\
				linux-setup macos-setup install-lib

.DEFAULT_GOAL	:=	all
