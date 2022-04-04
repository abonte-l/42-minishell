NAME			 =	minishell

INC				=	inc/
HEADER			=	$(INC)minishell.h


SRCS_PATH		=	srcs/
UTIL_PATH 		=	srcs/util/
BUILTINS_PATH	=	srcs/builtins/

SRCS 			=	prompt.c			split.c			get_path.c \
					cmd_exec_env.c		cmd_exec.c		check_builtins.c \
					exec_builtins.c		iz_special_char.c

UTIL			=	free.c				env_2_path.c	dup_envp.c

BUILTINS		=	cmd_cd.c			cmd_echo.c		cmd_env.c \
					cmd_exit.c			cmd_export.c	cmd_pwd.c \
					cmd_unset.c

SRCS_NAME 		=	$(addprefix $(SRCS_PATH),$(SRCS))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g

LIB_DIR			=	libft

LIB				=	$(LIB_DIR)/libft.a

OBJ_PATH		=	obj/

OBJS_NAME		=	$(SRCS:.c=.o)
OBJS_NAME		+=	$(UTIL:.c=.o)
OBJS_NAME		+=	$(BUILTINS:.c=.o)


OBJS			=	$(addprefix $(OBJ_PATH),$(OBJS_NAME))

all: $(LIB) $(NAME)

$(LIB) :
	@make -C $(LIB_DIR)

$(NAME) : $(OBJS)
	@printf "\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) -L.local/lib -lreadline
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(OBJ_PATH)%.o:	$(SRCS_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(UTIL_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(BUILTINS_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

run: all
	@./$(NAME)

leaks: all
	@valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes ./$(NAME)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C $(LIB_DIR) clean
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re run
