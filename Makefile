NAME		= 	minishell
CC			= 	clang
RM			=	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

RLINCL		=	-I ~/.brew/opt/readline/include
RLLIB		=	-L ~/.brew/opt/readline/lib -lreadline

LIBS		=	-Llibft -lft $(RLLIB)

S_PATH		=	src/
S_SRC		= 	main.c\
				init_shell.c\
				init_prompt.c\
				signals.c\
				heredoc.c
S_OBJ		=	$(S_SRC:%.c=$(S_PATH)%.o)

U_PATH		=	src/utils/
U_SRC		= 	error.c\
				free.c\
				utils.c\
				read_line.c
U_OBJ		=	$(U_SRC:%.c=$(U_PATH)%.o)

VECT_PATH	=	src/utils/vector/
VECT_SRC	=	vector_add.c\
				vector_clear.c\
				vector_free.c\
				vector_getvalue.c\
				vector_indexof.c\
				vector_new.c\
				vector_newptr.c\
				vector_realloc.c\
				vector_removeat.c\
				vector_tostrarray.c
VECT_OBJ	=	$(VECT_SRC:%.c=$(VECT_PATH)%.o)

P_PATH		=	src/parsing/
P_SRC		=	create.c\
				tokens.c\
				expand.c\
				expand_variable.c\
				checkers.c\
				states.c\
				redirects.c\
				redirects2.c
P_OBJ		=	$(P_SRC:%.c=$(P_PATH)%.o)

EXEC_PATH	=	src/executor/
EXEC_SRC	=	execute.c\
				exec_bin.c\
				exec_retval.c\
				redirect.c
EXEC_OBJ	=	$(EXEC_SRC:%.c=$(EXEC_PATH)%.o)

BLTIN_PATH	=	src/executor/builtin/
BLTIN_SRC	=	cd.c\
				echo.c\
				env.c\
				exit.c\
				export.c\
				export_b.c\
				export_print.c\
				pwd.c\
				unset.c\
				get_builtin.c\
				envvar_utils.c
BLTIN_OBJ	=	$(BLTIN_SRC:%.c=$(BLTIN_PATH)%.o)

OBJ_FILES = $(L_OBJ) $(P_OBJ) $(S_OBJ) $(U_OBJ) $(BLTIN_OBJ) $(VECT_OBJ) $(EXEC_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) -o $(NAME) $(CFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I includes/ $(RLINCL)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
