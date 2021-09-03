/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:18:40 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/03 14:30:11 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	clean_up_tokens(t_command *command)
{
	int		i;
	char	*line;

	i = 0;
	while (command->tokens->items[i])
	{
		line = command->tokens->items[i];
		if (choose_redirect(command, line, i) == 1)
			continue ;
		i++;
	}
}

void	remove_unnecessary_quotes(t_command *command, int i)
{
	char	*new;
	char	*str;

	str = command->tokens->items[i];
	if (!(ft_strncmp(str, "'$", 2)))
		new = ft_substr(str, 1, ft_strlen(str) - 2);
	else
		new = make_new_string_without_quotes(str);
	free(command->tokens->items[i]);
	command->tokens->items[i] = new;
}

char	*make_new_string_without_quotes(char *str)
{
	int		len;
	char	quote;
	char	*new;

	if (str[0] == '"')
		quote = '"';
	else
		quote = '\'';
	len = count_string_length(str, quote);
	new = (char *)ft_calloc(sizeof(char), len + 1);
	strip_string(new, str, quote);
	return (new);
}

char	*strip_string(char *new, char *old, char quote)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (old[i])
	{
		if (old[i] != quote || \
		(old[i] == quote && (old[i - 1] == ' ' || old[i + 1] == ' ')))
		{
			new[j] = old[i];
			j++;
			i++;
			continue ;
		}
		i++;
	}
	return (new);
}

int	count_string_length(char *str, char quote)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (str[i])
	{
		if (str[i] != quote)
			len++;
		else if (str[i] == quote && (str[i - 1] == ' '  || str[i + 1] == ' '))
			len++;
		i++;
	}
	return (len);
}
