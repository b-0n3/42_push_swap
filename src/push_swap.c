/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:12:25 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:12:27 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	new_stacks(&stacks);
	argc--;
	while (argc > 0)
	{
		if (stacks.stack_a.push(&stacks.stack_a,
				new_chunk(ft_newnb(argv[argc]), stacks.stack_a.index)
				, sizeof(t_chunk *)) == FALSE)
		{
			ft_putstr("Error\n");
			stacks.free(&stacks);
			exit(255);
		}
		argc--;
	}
	if (check_deplicate(stacks))
	{
		ft_putstr("Error\n");
		stacks.free(&stacks);
		exit(255);
	}
	sort_stacks(&stacks);
	stacks.free(&stacks);
}
