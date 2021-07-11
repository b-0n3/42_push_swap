/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:05:13 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:05:24 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void init_commands(t_array_list *list)
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

t_bool list_contains(t_array_list commands, char *query)
{
	int len1;
	int len2;
	char *tmp;
	int index;

	index = 0;
	if (query == NULL)
		return (FALSE);
	len1 = ft_strlen(query);
	while(index < (int)commands.index)
	{
		tmp = commands.get(&commands, index);
		if(tmp != NULL)
		{
			len2 = ft_strlen(tmp);
			if (len1 == len2)
				if (ft_memcmp(tmp, query, len2) == 0)
					return (TRUE);
		}
		index++;
	} 
	return (FALSE);
}
int get_query_index(char *query, t_array_list commands)
{
	int len1;
	int len2;
	char *tmp;
	int index;

	index = 0;
	if (query == NULL)
		return (FALSE);
	len1 = ft_strlen(query);
	while(index < (int)commands.index)
	{
		tmp = commands.get(&commands, index);
		if(tmp != NULL)
		{
			len2 = ft_strlen(tmp);
			if (len1 == len2)
				if (ft_memcmp(tmp, query, len2) == 0)
					return index;
		}
		index++;
	} 
	return (-1);
}
t_ex_cmd execute(char *query, t_array_list commands)
{
	int index;

	index = get_query_index(query, commands);
	if (index == 0)
		return &swap_a_cmd;
	if (index == 1)
		return &swap_b_cmd;
	if (index == 2)
		return &swap_a_and_b_cmd;
	if (index == 3)
		return &push_a_cmd;
	if (index == 4)
		return &push_b_cmd;
	if (index == 5)
		return &rotate_a_cmd;
	if (index == 6)
		return &rotate_b_cmd;
	if (index == 7)
		return &rotate_a_and_b_cmd;
	if (index == 8)
		return &reverse_rotate_a_cmd;
	if (index == 9)
		return &reverse_rotate_b_cmd;
	if (index == 10)
		return &reverse_rotate_a_and_b_cmd;
	return NULL;
}

int    sort_the_stack(t_stacks *stacks)
{
	char *query;
	t_array_list commands;
	int i;

	i = 0;
	new_array_list(&commands, 9, sizeof(char *));
	init_commands(&commands);
	while(get_next_line(0, &query))
	{
		i++;
		if (!list_contains(commands, query))
		{
			free(query);
			commands.free(&commands, &free);
			return (255);
		}
		execute(query, commands)(stacks);
		free(query);
		query = NULL;
	}
	commands.free(&commands ,&free);
	if (query != NULL && i == 0)
	{
		free(query);
		return 255;
	}
	free(query);
	return (0);
}

int main(int argc, char **argv)
{
	t_stacks stacks;
	int     exit_code;
	new_stacks(&stacks);
	argc--;
	if (argc == 0)
		exit(0);
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
	exit_code =  sort_the_stack(&stacks);
	if (exit_code != 0)
		ft_putstr("Error\n");
	if (exit_code == 0 && (!stacks.a_is_sorted(&stacks) ||  !stacks.b_is_empty(&stacks)))
	{
		ft_putstr("KO");
		exit_code = 0;
	}
	if (exit_code == 0 &&(stacks.a_is_sorted(&stacks) && stacks.b_is_empty(&stacks)))
		ft_putstr("OK");
	stacks.free(&stacks);
	system("leaks checker");
	exit(exit_code);
}
