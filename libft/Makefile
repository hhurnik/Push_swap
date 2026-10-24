Library    = libft
files      := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c  ft_tolower.c ft_toupper.c

Compiler   = gcc
CmpFlags   = -Wall -Wextra -Werror
OUTN       = $(Library).a

# Substitute '.c' with '.o' to create object file names
OFILES     = $(files:.c=.o)
NAME       = $(OUTN)

# Compile each source file into object files
%.o: %.c
	$(Compiler) $(CmpFlags) -c $< -o $@

$(NAME): $(OFILES)
	ar -rc $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(OUTN)

re: fclean all

.PHONY: all clean fclean re
