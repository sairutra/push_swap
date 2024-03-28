include src/shared/sources.mk

LIBFT.A = libft.a

LIBFT.H = libft.h

LIBFT = src/shared/libft

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(LIBFT.A)
	@$(CC) $(CFLAGS) $(SOURCES) $(LIBFT)/$(LIBFT.A) -fsanitize=address -o $(NAME)  

$(LIBFT.A): 
	@$(MAKE) -C $(LIBFT) all

clean:
	@$(MAKE) -C $(LIBFT) clean
	rm -rf *.o
	rm -rf *.a

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	rm -rf push_swap

re: fclean all

