# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/05/05 15:58:47 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
CC		= 	gcc
RM		=	rm -f
FLAGS	= 	-Wall -Wextra -Werror -I includes/
LIBS	=	-Llibft -lft -o

H_FILES	= 	libft.h
H_PATH	=	includes/

S_SRC	= 	main.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

P_SRC	=	parsing.c
P_PATH	=	src/parsing/
P_OBJ	=	$(P_SRC:%.c=$(P_PATH)%.o)

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft && make
	$(CC) $(OBJ_FILES) $(LIBS) $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME) && cd libft && make fclean

re: fclean all