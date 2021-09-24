/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/24 13:39:14 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtin.h"
# include "vector.h"
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_quotes
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
}	t_quotes;

typedef enum e_error_states
{
	GENERAL_ERROR,
	MISUSE_BUILTIN,
	CANNOT_EXECUTE,
	COMMAND_NOT_FOUND,
	INVALID_ARG,
	FATAL_ERROR,
	TERMINATED,
	OUT_OF_RANGE
}	t_error_states;

typedef enum e_states
{
	DULL,
	IN_WORD,
	IN_DOUBLE,
	IN_SINGLE,
	IN_PIPE,
	DONE,
	ERROR
}	t_states;

typedef enum e_errorz
{
	err_args = 1,
	err_malloc,
	err_pipe,
	err_fork,
	err_exit
}	t_error;

typedef struct s_tokens
{
	int		size;
	int		allocated;
	char	**items;
}	t_tokens;

typedef struct s_parsing
{
	char			*ptr;
	char			*start;
	enum e_states	state;
	char			*delimiters;
	int				argc;
}	t_parsing;

typedef struct s_command
{
	struct s_command	*pipe;
	int					in_fd;
	int					out_fd;
	int					append;
	char				*delimiter;
	t_tokens			*tokens;
}	t_command;

typedef struct s_shell
{
	t_command			*cmd;
	t_vector			*env_list;
	char				***environ;
	t_error_states		error_state;
	t_command			*dest;
}	t_shell;

t_shell		*g_shell;

typedef struct s_envvar
{
	char	*key;
	char	*value;
	t_bool	is_append;
}	t_envvar;

void		shell_exit(int error);
void		print_tokens(void);

void		init_shell(char **env);
void		init_prompt(void);
void		init_command(t_command *new);
t_parsing	*create_new_info(char *line);

// COMMAND FUNCTIONS
void		read_command(void);
int			create_commands_list(char *line);
t_command	*create_new_command(void);
void		create_new_command_and_tokens(t_command **dest);
void		add_new_command(char *line);
void		add_back_command(t_command **dest, t_command *new);
void		delete_one_command(t_command **src, t_command *node);

// TOKEN FUNCTIONS
t_tokens	*create_new_token(void);
int			create_new_pipe(t_parsing *info, t_command *dest);
void		make_new_token(t_parsing *info);
void		dull_functions(t_parsing *info);
void		double_functions(t_parsing *info);
void		single_functions(t_parsing *info);
void		pipe_functions(t_parsing *info);
void		word_functions(t_parsing *info);
int			fill_in_tokens(t_parsing *info);
void		delete_redirect_token(char **pointers, int i);

// ITEM FUNCTIONS
void		make_new_item(t_parsing *info, t_tokens *tokens);
int			check_if_makes_new_item(t_parsing *info, t_tokens *tokens);
void		expand_items(t_tokens *tokens);
char		*delete_all_quotes(char *str);
void		convert_arg(t_command *command, int i);
char		*get_value(char *line);

// FREE FUNCTIONS
void		free_command_and_tokens(void);
void		free_command(void);
void		free_pipes(void);

// Executor
void		init_executor(void);

// UTILS
t_bool		is_valid_key(char *var);
t_bool		is_valid_key_l(char *var, unsigned int l);
void		activate_signals(void);
void		deactivate_signals(void);
int			count_size_without_quotes(char *str);
char		*copy_str_without_quotes(char *new, char *str);

#endif
