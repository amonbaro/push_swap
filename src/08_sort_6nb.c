/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sort_6nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:30:44 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:28 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_j(int *k, int top, int j)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (j == k[i])
			return (i);
		i++;
	}
	return (-1);
}

int	find_i(int *k, int top, int j)
{
	int	i;

	i = top;
	while (i >= 0)
	{
		if (k[i] == j)
			return (i);
		i--;
	}
	return (-1);
}

int	find_small(int *k, int top)
{
	int	i;
	int	j;

	i = top;
	j = k[top];
	while (i >= 0)
	{
		if (j > k[i])
			j = k[i];
		i--;
	}
	return (j);
}

void	push_to_b(t_list *stack)
{
	int	i;

	i = find_i(stack->a, stack->s_a, find_small(stack->a, stack->s_a));
	if (i == stack->s_a)
	{
		pb(stack->a, &stack->s_a, stack->b, &stack->s_b);
		return ;
	}
	if (i < stack->s_a / 2)
		while (stack->a[stack->s_a] != find_small(stack->a, stack->s_a))
			rra(stack->a, stack->s_a, '1');
	else
		while (stack->a[stack->s_a] != find_small(stack->a, stack->s_a))
			ra(stack->a, stack->s_a, '1');
	pb(stack->a, &stack->s_a, stack->b, &stack->s_b);
}

void	sort_6nb(t_list *stack, int i)
{
	push_to_b(stack);
	if (i == 6)
		push_to_b(stack);
	sort_4nb(stack, 4);
	pa(stack->a, &stack->s_a, stack->b, &stack->s_b);
	if (i == 6)
		pa(stack->a, &stack->s_a, stack->b, &stack->s_b);
}
