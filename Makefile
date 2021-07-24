# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/07/24 19:20:25 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell
CC			= 	gcc
RM			=	rm -f
CFLAGS		= 	-Wall -Wextra -g3 -fsanitize=address
LIBS		=	-Llibft -lft -lreadline -o 

S_SRC		= 	main.c
S_PATH		=	src/
S_OBJ		=	$(S_SRC:%.c=$(S_PATH)%.o)

U_SRC		= 	error.c\
				commands.c\
				tokens.c\
				free.c\
				redirects.c
U_PATH		=	src/utils/
U_OBJ		=	$(U_SRC:%.c=$(U_PATH)%.o)

P_SRC		=	parsing.c
P_PATH		=	src/parsing/
P_OBJ		=	$(P_SRC:%.c=$(P_PATH)%.o)

EXEC_PATH	=	src/executor/
EXEC_SRC	=	init_execute.c

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

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ) $(U_OBJ) $(BLTIN_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) $(LIBS) $(NAME) -g3 -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I includes/

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
