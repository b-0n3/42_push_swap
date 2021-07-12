/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:57:07 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/12 16:57:10 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_commands(t_array_list *list)
{
	list->push(list, ft_strdup("sa"), sizeof(char *));
	list->push(list, ft_strdup("sb"), sizeof(char *));
	list->push(list, ft_strdup("ss"), sizeof(char *));
	list->push(list, ft_strdup("pa"), sizeof(char *));
	list->push(list, ft_strdup("pb"), sizeof(char *));
	list->push(list, ft_strdup("ra"), sizeof(char *));
	list->push(list, ft_strdup("rb"), sizeof(char *));
	list->push(list, ft_strdup("rr"), sizeof(char *));
	list->push(list, ft_strdup("rra"), sizeof(char *));
	list->push(list, ft_strdup("rrb"), sizeof(char *));
	list->push(list, ft_strdup("rrr"), sizeof(char *));
}

void	check_mate(t_stacks stacks, int *exit_code)
{
	if (*exit_code != 0)
		ft_putstr("Error\n");
	if (*exit_code == 0 && (!stacks.a_is_sorted(&stacks)
			|| !stacks.b_is_empty(&stacks)))
	{
		ft_putstr("KO\n");
		*exit_code = 0;
	}
	if (*exit_code == 0 && (stacks.a_is_sorted(&stacks)
			&& stacks.b_is_empty(&stacks)))
		ft_putstr("OK\n");
}

void	push_args(int argc, char **argv, t_stacks *stacks)
{
	while (argc > 0)
	{
		if (stacks->stack_a.push(&stacks->stack_a,
				new_chunk(ft_newnb(argv[argc]), stacks->stack_a.index)
				, sizeof(t_chunk *)) == FALSE)
		{
			ft_putstr("Error\n");
			stacks->free(stacks);
			exit(255);
		}
		argc--;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			exit_code;

	argc--;
	if (argc == 0)
		exit(0);
	new_stacks(&stacks);
	push_args(argc, argv, &stacks);
	if (check_deplicate(stacks))
	{
		ft_putstr("Error\n");
		stacks.free(&stacks);
		exit(255);
	}
	exit_code = sort_the_stack(&stacks);
	check_mate(stacks, &exit_code);
	stacks.free(&stacks);
	exit(exit_code);
}
