Library    = push_swap

OUTN       = $(Library).a
EXEC       = push_swap  # This is the name of your executable

files      :=  instruct.c instruct2.c instruct3.c parse.c parse2.c parse3.c parse4.c sort_234.c target_b.c target_a.c push_swap.c push_swap2.c costs.c
OFILES     = $(files:.c=.o)

Compiler   = gcc
CmpFlags   = -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

NAME       = $(OUTN)

# All steps to compile push_swap
all: $(EXEC)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(Compiler) $(CmpFlags) -c $< -o $@

$(EXEC): $(OFILES) $(LIBFT)  # Create the executable
	$(Compiler) $(CmpFlags) -o $(EXEC) $(OFILES) $(LIBFT)  # Link object files into the executable

$(NAME): $(OFILES) $(LIBFT)  # Ensure libft.a is built before creating push_swap.a
	ar -rc $(OUTN) $(OFILES) $(LIBFT)
	ranlib $(OUTN)

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean  # Clean libft files

fclean: clean
	rm -f $(EXEC)  # Remove the final executable
	rm -f $(OUTN)
	$(MAKE) -C $(LIBFT_DIR) fclean  # Clean libft.a

re: fclean all

.PHONY: all clean fclean re
