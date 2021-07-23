SRC		= *.c
VECTOR	= ../utils/vector/*.c
BUILTIN	= builtin/*.c
FTDIR	= ../../libft

all: libft $(SRC) $(BUILTIN)
	gcc $(SRC) $(VECTOR) $(BUILTIN) -L../../libft -lft

libft:
	$(MAKE) all -C $(FTDIR)