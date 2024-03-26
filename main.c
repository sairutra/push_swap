#include "libft/libft.h"
#include "push_swap.h"


int check_stack_a_argument_val(char *test)
{
	int	index;

	index = 0;
	if (test[index] == '-')
		index++;
	while(test[index] != '\0')
	{
		if(!ft_isdigit(test[index++]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int check_stack_a_argument_int(char *test)
{
	char	*cmp;
	int		ret;

	ret = ft_atoi(test);
	cmp = ft_itoa(ret);
	if (cmp == NULL)
	{
		ft_printf("malloc failed in check_stack_a_argument_int\n");
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(test, cmp, ft_strlen(test)))
	{
		free(cmp);
		return (EXIT_FAILURE);
	}
	free(cmp);
	return (EXIT_SUCCESS);
}

int check_stack_a_arguments(char **argv)
{
	int	index;

	index = 0;
	while(argv[index] != NULL)
	{
		if(check_stack_a_argument_val(argv[index]))
			return(EXIT_FAILURE);
		if(check_stack_a_argument_int(argv[index++]))
			return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

int check_stack_a_duplicate(char **argv)
{
	int	oi;
	int	ii;

	oi = 0;
	ii = 1;
	while(argv[oi] != NULL)
	{
		while(argv[ii] != NULL)
		{
			if(!ft_strncmp(argv[oi], argv[ii++], ft_strlen(argv[oi])))
				return(EXIT_FAILURE);
		}
		oi++;
		ii = oi + 1;
	}
	return(EXIT_SUCCESS);
}

void create_stack_a(void)
{

}

void create_stack_b(void)
{

}

int check_stack_a(char **argv)
{
	if (check_stack_a_arguments(argv))
		return(1);
	if (check_stack_a_duplicate(argv))
		return(1);
	return(0);
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

