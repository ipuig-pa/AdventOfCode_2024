NAME = d1

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	d1.c \

OBJECTS = $(SOURCES:.c=.o)
HEADER = d1.h

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ../ft_printf
FT_PRINTF= $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -lftprintf -lft -o $(NAME)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF): $(LIBFT)
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re