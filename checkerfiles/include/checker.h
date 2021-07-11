/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:05:32 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:06:01 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"
typedef void	(*t_ex_cmd)(t_stacks *);
void	reverse_rotate_a_cmd(t_stacks *this);
void	reverse_rotate_b_cmd(t_stacks *this);
void	reverse_rotate_a_and_b_cmd(t_stacks *this);
void	push_b_cmd(t_stacks *this);
void	push_a_cmd(t_stacks *this);
void	rotate_a_and_b_cmd(t_stacks *this);
void	rotate_b_cmd(t_stacks *this);
void	rotate_a_cmd(t_stacks *this);
void	swap_a_and_b_cmd(t_stacks *this);
void	swap_b_cmd(t_stacks *this);
void	swap_a_cmd(t_stacks *this);
#endif
