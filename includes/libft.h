/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 18:46:35 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/08 14:20:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define MAX_FD 10000

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				get_next_line(int fd, char **line);

void			ft_bzero(void *buf, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_calloc(size_t blocks, size_t size);
void			*ft_memset(void *buf, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *buf, int c, size_t len);
void			ft_free_split(char **split);

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t len);

char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *big, const char *small, size_t len);
char			*ft_strdup(const char *str1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strtrim(char const *str, char const *set);
char			**ft_split(char	const *s, char c);
char			**ft_split_words(char	const *s, char c, int *total_words);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*buffjoin(char *buffer, char *start, char *end);

int				ft_atoi(const char *str);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_memcmp(const void *str1, const void *str2, size_t len);
int				ft_strncmp(const char *str1, const char *str2, size_t len);
int				ft_strncmp_rev(const char *str1, const char *str2, size_t len);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

double			ft_atof(const char *str);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

void			*ft_realloc(void *ptr, size_t size);
void			*ft_realloc_double(void *src, int srcsize);
int				ft_split_count(char **splits);
char			ft_strcontains(char *str, char c);

#endif
