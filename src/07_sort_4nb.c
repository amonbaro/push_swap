/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_4nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:29:22 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:26 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(int *k, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (k[i] < k[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	sort_4nb(t_list *stack, int i)
{
	if (i == 3)
	{
		if (check_if_sorted(stack->a, stack->s_a) != 0)
			sa(stack->a, stack->s_a, '1');
		return ;
	}
	while (check_if_sorted(stack->a, stack->s_a) != 0)
	{
		if (stack->a[stack->s_a] > stack->a[(stack->s_a) - 1])
		{
			sa(stack->a, stack->s_a, '1');
			if (check_if_sorted(stack->a, stack->s_a) != 0)
				rra(stack->a, stack->s_a, '1');
		}
		else
			rra(stack->a, stack->s_a, '1');
	}
}
