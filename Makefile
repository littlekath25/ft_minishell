# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/06/29 13:19:43 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
CC		= 	gcc
RM		=	rm -f
FLAGS	= 	-Wall -Wextra -Werror
LIBS	=	-Llibft -lft -o

S_SRC	= 	main.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

P_SRC	=	parsing.c
P_PATH	=	src/parsing/
P_OBJ	=	$(P_SRC:%.c=$(P_PATH)%.o)

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) $(LIBS) $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all