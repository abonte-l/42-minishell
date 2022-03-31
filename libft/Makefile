NAME		=	libft.a

INC			=	inc/
HEADER		=	$(INC)libft.h

SRC_PATH	=	srcs/

MEM_PATH	=	$(SRC_PATH)mem/
STR_PATH	=	$(SRC_PATH)str/

MEM			=	ft_bzero.c			ft_memcpy.c 		ft_calloc.c \
				ft_realloc.c
				
STR			=	ft_strlen.c			ft_strncmp.c		ft_strdup.c	\
				ft_strdup.c			ft_strtok.c			ft_strcat.c \

OBJ_PATH	=	obj/

OBJ_NAME	+=	$(MEM:.c=.o)
OBJ_NAME	+=	$(STR:.c=.o)

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

all:	$(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\n"
	@echo "Compilation of \033[33;1mLibft\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"


$(OBJ_PATH)%.o:	$(MEM_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(STR_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)
	@echo "\033[33;1mLibft\033[0;1m: objects deleted\033[0m"

fclean: clean
	@$(RM) $(NAME) 
	@echo "\033[33;1mLibft\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re