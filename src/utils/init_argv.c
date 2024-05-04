/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:43:17 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 18:51:14 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	**init_argv(char **argv, int argc)
{
	char	**ret;
	int		index;

	index = 0;
	ret = NULL;
	if (argc == 2)
		ret = ft_split(argv[0], ' ');
	if (argc > 2)
	{
		ret = malloc(sizeof(char *) * (argc));
		while (argc != 1)
		{
			ret[index] = ft_strdup(argv[index]);
			index++;
			argc--;
		}
		ret[index] = NULL;
	}
	return (ret);
}
