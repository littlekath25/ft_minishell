/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 12:40:32 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/30 13:51:37 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_token
{
	struct s_token	*next;
	char			*data;
}	t_token;

typedef struct s_command
{
	int					outfd;
	int					infd;
	char				*command;
	t_token				*tokens;
	struct s_command	*next;
}	t_command;

typedef struct s_tree
{
	t_command		*commands;
	struct s_tree	*next;
}	t_tree;

typedef struct s_shell
{
	char	**env;
	char	**paths;
	t_tree	*trees;
}	t_shell;

void	error_and_exit(int error);

#endif