/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:21:41 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:46:10 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cleanline(char **arr, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (arr[fd][len] != '\n')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_substr(arr[fd], 0, len);
		tmp = ft_strdup(arr[fd] + len + 1);
		if (tmp == NULL || *line == NULL)
			return (-1);
		free(arr[fd]);
		arr[fd] = tmp;
	}
	return (1);
}

static int	putline(char **arr, int fd, char **line)
{
	*line = ft_strdup(arr[fd]);
	if (*line == NULL)
		return (-1);
	free(arr[fd]);
	return (0);
}

static int	shortreturn(char **line, int bytes, char **arr, int fd)
{
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && arr[fd] == NULL)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
	}
	return (0);
}

static int	processline(int fd, char **arr, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes;

	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes < 0 || (bytes == 0 && arr[fd] == NULL))
		return (shortreturn(line, bytes, arr, fd));
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(arr[fd], buff);
			if (tmp == NULL)
				return (-1);
			free(arr[fd]);
			arr[fd] = tmp;
		}
		if (ft_strchr(arr[fd], '\n'))
			return (cleanline(arr, fd, line));
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (putline(arr, fd, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*arr[MAX_FD];

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	else if (arr[fd] != NULL && ft_strchr(arr[fd], '\n'))
		return (cleanline(arr, fd, line));
	return (processline(fd, arr, line));
}
