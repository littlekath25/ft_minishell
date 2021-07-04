SRC		= *.c
BUILTIN	= builtin/*.c
FTDIR	= ../../libft

all: libft $(SRC) $(BUILTIN)
	gcc $(SRC) $(BUILTIN) -L../../libft -lft

libft:
	$(MAKE) all -C $(FTDIR)