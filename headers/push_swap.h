#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "array_list.h"
# include <string.h>
# include <unistd.h>

typedef struct s_stacks{
	t_array_list stack_a;
	t_array_list stack_b;
	void (*sa)(struct s_stacks *this, t_bool print);
	void (*sb)(struct s_stacks *this, t_bool print);
	void (*ss)(struct s_stacks *this);
	void (*pa)(struct s_stacks *this);
	void (*pb)(struct s_stacks *this);
	void (*ra)(struct s_stacks *this, t_bool print);
	void (*rb)(struct s_stacks *this, t_bool print);
	void (*rr)(struct s_stacks *this);
	void (*rra)(struct s_stacks *this, t_bool print);
	void (*rrb)(struct s_stacks *this, t_bool print);
	void (*rrr)(struct s_stacks *this);
	void (*free)(struct s_stacks *this);
	t_bool (*a_is_sorted)(struct s_stacks *this);
	t_bool (*b_is_sorted)(struct s_stacks *this);
	t_bool (*a_is_empty)(struct s_stacks *this);
	t_bool (*b_is_empty)(struct s_stacks *this);
}              t_stacks;


typedef struct s_chunk{
	int *value;
	int index;
	int chunk;
}			t_chunk;
/**
 *  Utils
 * 
 */
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);

void	new_stacks(t_stacks *this);
void	swap_a(t_stacks *this, t_bool print);
void	swap_b(t_stacks *this, t_bool print);
void	swap_a_and_b(t_stacks *this);
void	push_a(t_stacks *this);
void	push_b(t_stacks *this);
void	rotate_a(t_stacks *this, t_bool print);
void	rotate_b(t_stacks *this, t_bool print);
void	rotate_a_and_b(t_stacks *this);
void	reverse_rotate_a(t_stacks *this, t_bool print);
void	reverse_rotate_b(t_stacks *this, t_bool print);
void	reverse_rotate_a_and_b(t_stacks *this);
void	free_stacks(t_stacks *this);


t_bool stack_a_is_sorted(t_stacks *this);
t_bool stack_b_is_sorted(t_stacks *this);
t_bool stack_a_is_empty(t_stacks *this);
t_bool stack_b_is_empty(t_stacks *this);

#endif