BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

SRCS_S		= $(wildcard srcs/server/*.c)

SRCS_C		= $(wildcard srcs/client/*.c)

OBJS_S		= ${SRCS_S:.c=.o}

OBJS_C		= ${SRCS_C:.c=.o}

NAME		= minitalk

HEADERS_S	= srcs/server/

HEADERS_C	= srcs/client/

HEADERS_L	= srcs/libft/

FLAGS		= -Wall -Wextra -Werror

all:		server client

.c.o:		
			@gcc ${FLAGS} -I ${HEADERS_S} -I ${HEADERS_C} -I ${HEADERS_L} -c $< -o ${<:.c=.o} > /dev/null

server:		${OBJS_S}
			@printf "\n$(BLUE)"
			@make -C ${HEADERS_L}
			@printf "\n"
			@printf "$(BLUE)Compiling files..."
			@gcc ${FLAGS} ${OBJS_S} ${HEADERS_L}libft.a -o server
			@printf "$(GREEN)[server done][✔]$(RESET)"
			@printf "\n"

client:		${OBJS_C}
			@printf "$(BLUE)Compiling files..."
			@gcc ${FLAGS} ${OBJS_C} ${HEADERS_L}libft.a -o client
			@printf "$(GREEN)[client done][✔]$(RESET)"
			@printf "\n"

clean:
			@printf "$(RED)\n"
			@printf "clean libft\n"
			@make -C ${HEADERS_L} clean
			@printf "Erase files '.o'\n"
			@rm -rf $(OBJS_S) $(OBJS_C)
			@printf "$(RESET)\n"

fclean:
			@printf "$(RED)\n"
			@printf "fclean libft\n"
			@make -C ${HEADERS_L} fclean
			@printf "Erase files '.o'\n"
			@rm -rf $(OBJS_S) $(OBJS_C)
			@printf "Delete executable file\n"
			@rm -rf server client
			@printf "$(RESET)\n"

re:			fclean all

.PHONY:		clean fclean re all