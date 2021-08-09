/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_arg.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 13:37:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/08/09 13:39:18 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_value(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	line = delete_all_quotes(line);
	while (line[i] != '=')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	free(line);
	return (tmp);
}

void	convert_arg(t_command *command, int i)
{
	char	*arg;
	char	*value;
	int		index;

	arg = command->tokens->items[i];
	index = vector_indexof(g_shell->env_list, arg + 1);
	if (index == -1)
	{
		free(command->tokens->items[i]);
		command->tokens->items[i] = ft_strdup(" ");
		return ;
	}
	else
		value = get_value(vector_getvalue(g_shell->env_list, index));
	free(command->tokens->items[i]);
	command->tokens->items[i] = value;
}
