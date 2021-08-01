# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/08/01 13:45:00 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell
CC			= 	gcc
RM			=	rm -f
CFLAGS		= 	-Wall -Wextra -g3 -fsanitize=address
LIBS		=	-Llibft -lft -lreadline -o 

S_PATH		=	src/
S_SRC		= 	main.c\
				init_shell.c\
				init_prompt.c
S_OBJ		=	$(S_SRC:%.c=$(S_PATH)%.o)

U_PATH		=	src/utils/
U_SRC		= 	error.c\
				free.c\
				utils.c\
				is_valid_name.c
U_OBJ		=	$(U_SRC:%.c=$(U_PATH)%.o)

VECT_PATH	=	src/utils/vector/
VECT_SRC	=	vector_add.c\
				vector_clear.c\
				vector_free.c\
				vector_getvalue.c\
				vector_indexof.c\
				vector_new.c\
				vector_newptr.c\
				vector_realloc.c\
				vector_removeat.c\
				vector_tostrarray.c
VECT_OBJ	=	$(VECT_SRC:%.c=$(VECT_PATH)%.o)

P_PATH		=	src/parsing/
P_SRC		=	commands.c\
				redirects.c\
				tokens.c\
				items.c\
				convert_arg.c
P_OBJ		=	$(P_SRC:%.c=$(P_PATH)%.o)

EXEC_PATH	=	src/executor/
EXEC_SRC	=	execute.c
EXEC_OBJ	=	$(EXEC_SRC:%.c=$(EXEC_PATH)%.o)

BLTIN_PATH	=	src/executor/builtin/
BLTIN_SRC	=	cd.c\
				echo.c\
				env.c\
				exit.c\
				export.c\
				pwd.c\
				unset.c\
				get_builtin.c
BLTIN_OBJ	=	$(BLTIN_SRC:%.c=$(BLTIN_PATH)%.o)

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ) $(U_OBJ) $(BLTIN_OBJ) $(VECT_OBJ) $(EXEC_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) $(LIBS) $(NAME) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I includes/

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
