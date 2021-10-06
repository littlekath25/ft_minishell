/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffjoin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 15:18:44 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/06 11:17:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

static void	st_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

static char	*st_allocate(char *buff, int append_len)
{
	char	*new_buff;

	if (buff != NULL)
		append_len += ft_strlen(buff);
	new_buff = ft_calloc(1, append_len + 1);
	if (!new_buff)
		shell_exit(err_malloc);
	if (buff != NULL)
	{
		st_strcpy(new_buff, buff);
		ft_bzero(buff, 1024);
	}
	return (new_buff);
}

static void	st_append(char *buff, char *start, int len)
{
	int	i;

	while (*buff)
		buff++;
	i = 0;
	while (i < len)
	{
		buff[i] = start[i];
		i++;
	}
}

/*
	Joins together the buffer (if not NULL) and the string pointed to by
	start, until (not including) end.
 */
char	*buffjoin(char *buffer, char *start, char *end)
{
	char	*new_buff;

	new_buff = st_allocate(buffer, end - start);
	st_append(new_buff, start, end - start);
	return (new_buff);
}
