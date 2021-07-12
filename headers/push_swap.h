/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:07:43 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:07:50 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "array_list.h"
# include "utils.h"

typedef struct s_stacks
{
	t_array_list	stack_a;
	t_array_list	stack_b;
	void			(*sa)(struct s_stacks *this, t_bool print);
	void			(*sb)(struct s_stacks *this, t_bool print);
	void			(*ss)(struct s_stacks *this, t_bool print);
	void			(*pa)(struct s_stacks *this, t_bool print);
	void			(*pb)(struct s_stacks *this, t_bool print);
	void			(*ra)(struct s_stacks *this, t_bool print);
	void			(*rb)(struct s_stacks *this, t_bool print);
	void			(*rr)(struct s_stacks *this, t_bool print);
	void			(*rra)(struct s_stacks *this, t_bool print);
	void			(*rrb)(struct s_stacks *this, t_bool print);
	void			(*rrr)(struct s_stacks *this, t_bool print);
	void			(*free)(struct s_stacks *this);
	t_bool			(*a_is_sorted)(struct s_stacks *this);
	t_bool			(*b_is_sorted)(struct s_stacks *this);
	t_bool			(*a_is_empty)(struct s_stacks *this);
	t_bool			(*b_is_empty)(struct s_stacks *this);
}	t_stacks;

typedef struct s_chunk
{
	int		*value;
	int		index;
	int		chunk;
	void	(*free)(void *this);
	void	(*print)(struct s_chunk *this);
}	t_chunk;	
t_chunk	*new_chunk(int *value, int index);
int		chunk_compare(void *v1, void *v2);
void	print_chunk(t_chunk *this);
void	*clone_chunk(void *item);
void	free_chunk(void *this);
void	new_stacks(t_stacks *this);
void	swap_a(t_stacks *this, t_bool print);
void	swap_b(t_stacks *this, t_bool print);
void	swap_a_and_b(t_stacks *this, t_bool print);
void	push_a(t_stacks *this, t_bool print);
void	push_b(t_stacks *this, t_bool print);
void	rotate_a(t_stacks *this, t_bool print);
void	rotate_b(t_stacks *this, t_bool print);
void	rotate_a_and_b(t_stacks *this, t_bool print);
void	reverse_rotate_a(t_stacks *this, t_bool print);
void	reverse_rotate_b(t_stacks *this, t_bool print);
void	reverse_rotate_a_and_b(t_stacks *this, t_bool print);
void	free_stacks(t_stacks *this);
void	push_to_b(t_stacks *stacks, int nb, int chunk_n);
void	push_to_a(t_stacks *stacks, int nb, int chunk_n);	
t_chunk	*filter_first_chunk_and_get_pivot(
			t_array_list stack, t_array_list *clone);

void	clone_a_first_chunks_and_sort_it(
			t_stacks *stacks, t_array_list *clone,
			int current_chunk);
void	clone_b_first_chunks_and_sort_it(
			t_stacks *stacks, t_array_list *clone,
			int current_chunk);
t_bool	check_deplicate(t_stacks stacks);
int		*ft_newnb(char *number);
void	print_stacks(t_stacks stacks);
void	sort_stacks(t_stacks *stacks);
t_bool	stack_a_is_sorted(t_stacks *this);
t_bool	stack_b_is_sorted(t_stacks *this);
t_bool	stack_a_is_empty(t_stacks *this);
t_bool	stack_b_is_empty(t_stacks *this);
void	sort_tree(t_stacks *stacks, t_bool is_a);
#endif
