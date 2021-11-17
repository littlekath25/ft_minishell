/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 12:12:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "vector.h"
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <termios.h>

# define BUFFER 1024
# define HEREDOC_FNAME ".heredoc"
# define FORK_MAX 256

typedef struct s_dict
{
	char	*key;
	int		(*f)(char **argv);
}	t_dict;

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
	GENERAL_ERROR = 1,
	MISUSE_BUILTIN = 2,
	CANNOT_EXECUTE = 126,
	COMMAND_NOT_FOUND = 127,
	INVALID_ARG = 128,
	OUT_OF_RANGE = 256
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
	err_exit,
	err_open,
	err_pwd
}	t_error;

typedef struct s_tokens
{
	int		size;
	int		allocated;
	char	**items;
}	t_tokens;

typedef enum e_redirects
{
	rdr_input,
	rdr_output,
	rdr_append,
	rdr_heredoc
}	t_rdrs;

typedef struct s_rdr
{
	struct s_rdr	*next;
	t_rdrs			type;
	char			*fname;
}	t_redirect;

typedef struct s_command
{
	struct s_command	*pipe;
	int					in_fd;
	int					out_fd;
	t_tokens			*tokens;
	t_redirect			*redirects;
}	t_command;

typedef struct s_parsing
{
	char			*ptr;
	t_command		*current_cmd;
	enum e_states	state;
	int				i;
	int				size;
	char			*buffer;
}	t_parsing;

typedef struct s_heredoc
{
	struct s_heredoc	*next;
	char				*delimiter;
}	t_heredoc;

typedef struct s_shell
{
	int					io_fds[2];
	int					returnstatus;
	t_command			*cmd;
	t_vector			*env_list;
	char				***environ;
	t_error_states		error_state;
	t_parsing			*info;
	t_heredoc			*heredocs;
	struct termios		dfl_attr;
}	t_shell;

t_shell		*g_shell;

typedef struct s_envvar
{
	char	*key;
	char	*value;
	t_bool	is_append;
}	t_envvar;

void		shell_exit(int error);
void		print_perror(char *prefix);
void		print_err_syntax(void);

void		init_shell(char **env);
void		init_prompt(void);
void		init_command(t_command *new);
void		handle_heredoc(t_command *cmd);
void		heredoc_addnew(char *delimiter);

// CREATE FUNCTIONS
t_parsing	*create_new_info(char *line);
void		create_new_command_and_tokens(t_command **dest);
t_bool		create_commands_list(char *line);
void		create_new_pipe(t_parsing *info);

// PARSE FUNCTIONS
void		make_new_token(t_parsing *info);
t_bool		dull_functions(t_parsing *info);
void		double_functions(t_parsing *info);
void		single_functions(t_parsing *info);
t_bool		pipe_functions(t_parsing *info);
t_bool		word_functions(t_parsing *info);
t_bool		fill_in_tokens(t_parsing *info);
t_bool		end_of_token(t_parsing *info);
t_bool		convert_variable(t_parsing *info);
void		variable_checker(t_parsing *info);
t_bool		is_redirect(t_parsing *info);
void		copy_to_buffer(t_parsing *info);
void		expand_buffer(t_parsing *info);

// ITEM FUNCTIONS
void		expand_items(t_tokens *tokens);
t_bool		set_redirects(t_parsing *info);
int			iterate_tokens(int ret, char *token);
char		*get_filename(t_parsing *info);

// FREE FUNCTIONS
void		free_command_and_tokens(void);

// Executor
void		init_executor(void);
int			exec_bin(t_command *cmd);
void		wait_and_set_returnvalue(int pid);
t_bool		handle_redirects(t_command *cmd);
void		close_unused_fds(t_command *cmd);

// UTILS
t_bool		is_valid_key(char *var);
t_bool		is_valid_key_l(char *var, unsigned int l);
void		activate_signals(void);
void		deactivate_signals(void);
void		print_error_token(char token);
void		clean_up_tokens(char **pointers, int i);
char		*read_line(char *prompt);

// BUILTIN
void		*get_builtin(const char *key);
int			env_list_indexof(t_vector *vect, char *key);
void		export_print(void);
char		*split_key(char *arg, t_bool *is_append);
char		*get_new_arg(t_envvar var);

int			_cd_(char **argv);
int			_echo_(char **argv);
int			_env_(char **argv);
int			_exit_(char **argv);
int			_export_(char **argv);
int			_pwd_(char **argv);
int			_unset_(char **argv);

#endif
