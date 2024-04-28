/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:00 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:08:28 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// maybe also accept + in program, not sure 
// it is mandatory
int	check_stack_argument_val(char *test)
{
	int	index;

	index = 0;
	if (test[index] == '-')
		index++;
	while (test[index] != '\0')
	{
		if (!ft_isdigit(test[index++]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_stack_argument_int(char *test)
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

int	check_stack_arguments(char **argv)
{
	int	index;

	index = 0;
	while (argv[index] != NULL)
	{
		if (check_stack_argument_val(argv[index]))
			return (EXIT_FAILURE);
		if (check_stack_argument_int(argv[index++]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_stack_duplicate(char **argv)
{
	int		oi;
	int		ii;
	size_t	len;

	len = 0;
	oi = 0;
	ii = 1;
	while (argv[oi] != NULL)
	{
		while (argv[ii] != NULL)
		{
			len = ft_strlen(argv[oi]);
			if (len < ft_strlen(argv[ii]))
				len = ft_strlen(argv[ii]);
			if (!ft_strncmp(argv[oi], argv[ii++], len))
			{
				ft_printf("fail: argv-oi%s argv-ii%s\n", argv[oi], argv[--ii]);
				return (EXIT_FAILURE);
			}
		}
		oi++;
		ii = oi + 1;
	}
	return (EXIT_SUCCESS);
}

int	check_stack(char **argv)
{
	if (check_stack_arguments(argv))
	{
		ft_printf("fail arg\n");
		return (1);
	}
	if (check_stack_duplicate(argv))
	{
		ft_printf("fail dup\n");
		return (1);
	}
	return (0);
}
