/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:07:08 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:07:14 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_cmd(t_stacks *this)
{
	if (this != NULL)
		this->ra(this, FALSE);
}

void	rotate_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->rb(this, FALSE);
}

void	rotate_a_and_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->rr(this, FALSE);
}
