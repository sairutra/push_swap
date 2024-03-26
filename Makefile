include sources.mk

LIBFT.A = libft.a

LIBFT.H = libft.h

LIBFT = libft

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(LIBFT.A)
	@$(CC) $(CFLAGS) $(SOURCES) libft.a -o $(NAME)  

$(LIBFT.A): 
	@$(MAKE) -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT.A) ./

clean:
	@$(MAKE) -C $(LIBFT) clean
	rm -rf *.o
	rm -rf *.a

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	rm -rf push_swap

re: fclean all

