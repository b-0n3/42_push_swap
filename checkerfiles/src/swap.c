/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:07:21 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:07:23 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_cmd(t_stacks *this)
{
	if (this != NULL)
		this->sa(this, FALSE);
}

void	swap_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->sb(this, FALSE);
}

void	swap_a_and_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->ss(this, FALSE);
}
