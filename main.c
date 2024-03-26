#include "src/shared/push_swap.h"

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
