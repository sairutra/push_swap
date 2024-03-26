#include "libft/libft.h"


int check_stack_a(char **argv)
{
	int	index;

	index = 0;
	while(argv[index] != NULL)
	{
		if(!ft_strncmp(argv[index], "0", 2))
		{
			index++;
			continue;
		}
		if(!ft_atoi(argv[index++]))
			return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

void create_stack_a(void)
{

}

void create_stack_b(void)
{

}


int main (int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_stack_a(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return(0);
}

