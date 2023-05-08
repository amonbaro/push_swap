/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_inst_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:38 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:19 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *a, int s_a, int *b, int s_b)
{
	ft_putstr("ss\n");
	sa(a, s_a, '2');
	sb(b, s_b, '2');
}

void	rr(int *a, int s_a, int *b, int s_b)
{
	ft_putstr("rr\n");
	ra(a, s_a, '2');
	rb(b, s_b, '2');
}

void	rrr(int *a, int s_a, int *b, int s_b)
{
	ft_putstr("rrr\n");
	rra(a, s_a, '2');
	rrb(b, s_b, '2');
}
