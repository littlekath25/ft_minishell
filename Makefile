# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/07/23 14:32:30 by katherine     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
CC		= 	gcc
RM		=	rm -f
FLAGS	= 	-Wall -Wextra -g3
LIBS	=	-Llibft -lft -lreadline -o 

S_SRC	= 	main.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

U_SRC	= 	error.c\
			commands.c\
			tokens.c
U_PATH	=	src/utils/
U_OBJ	=	$(U_SRC:%.c=$(U_PATH)%.o)

P_SRC	=	parsing.c
P_PATH	=	src/parsing/
P_OBJ	=	$(P_SRC:%.c=$(P_PATH)%.o)

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ) $(U_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) $(LIBS) $(NAME) -g3

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all