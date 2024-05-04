/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:43:17 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:55:56 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char ** init_argv(char **argv, int argc)
{
	char **ret;
	int		index;

	index = 0;
	ret = NULL;
	if (argc == 2)
	{
		ret = ft_split(argv[0], ' ');
	}
	else
	{
		ret = malloc(sizeof(char) * (argc - 1));
		while (argc != 1)
		{
			ret[index] = ft_strdup(argv[index]);
			index++;
			argc--;
		}
	}
	return (ret);
}
