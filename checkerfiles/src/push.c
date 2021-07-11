/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:06:15 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:06:20 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->pb(this, FALSE);
}

void	push_a_cmd(t_stacks *this)
{
	if (this != NULL)
		this->pa(this, FALSE);
}
