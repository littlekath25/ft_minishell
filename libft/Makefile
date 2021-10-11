# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/10/08 14:51:43 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
AR =		ar
H_FILES = 	libft.h
CC = 		clang
RM =		rm -f
CFLAGS = 	-Wall -Wextra -Werror -I ../includes/
O_FILES = 	$(SRC:.c=.o)
SRC = 		ft_atoi.c\
			ft_atof.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_free_split.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_split_words.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_strcmp.c\
			ft_strncmp_rev.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			ft_split_count.c\
			ft_realloc.c\
			ft_realloc_double.c\
			buffjoin.c\
			ft_strcontains.c

OBJ_FILES = $(O_FILES)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) rcs $(NAME) $(O_FILES)

%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(O_FILES) $(BO_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
