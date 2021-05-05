/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 12:17:08 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:45:47 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **split, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_wordslen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	**fill(char **split, const char *s, char c, int words)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_wordslen(s, c);
		split[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (split[i] == NULL)
			return (ft_free(split, i));
		j = 0;
		while (j < len)
		{
			split[i][j] = *s;
			s++;
			j++;
		}
		split[i][j] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split_words(char	const *s, char c, int *total_words)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	split = fill(split, s, c, words);
	*total_words = words;
	return (split);
}
