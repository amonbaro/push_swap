/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_push_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:31:59 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:29 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_sort_a(t_list *stack, int *k, int j)
{
	int	i;

	i = -1;
	while (*k <= stack->s_b)
	{
		i = find_j(stack->b, stack->s_b, j);
		if (i >= (stack->s_b / 2))
		{
			if (stack->b[stack->s_b] != j)
				rb(stack->b, stack->s_b, '1');
		}
		if (i < (stack->s_b / 2))
		{
			if (stack->b[stack->s_b] != j)
				rrb(stack->b, stack->s_b, '1');
		}
		*k += 1;
	}
}

void	push_sorted_to_a(t_list *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = stack->b[stack->s_b];
	k = stack->s_b;
	while (k + 1)
	{
		i = 0;
		while (i <= stack->s_b)
		{
			if (j < stack->b[i])
				j = stack->b[i];
			i++;
		}
		i = 0;
		loop_sort_a(stack, &i, j);
		pa(stack->a, &stack->s_a, stack->b, &stack->s_b);
		j = stack->b[stack->s_b];
		k--;
	}
}

void	push_sorted_to_b(t_list *stack)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	k = (stack->s_a / 10) + 10;
	while (stack->s_a >= 0)
	{
		if (stack->a[stack->s_a] < k * i)
		{
			pb(stack->a, &stack->s_a, stack->b, &stack->s_b);
			if (stack->b[stack->s_b] < (i * k) - (k / 2))
				rb(stack->b, stack->s_b, '1');
			j++;
		}
		else
		{
			while (stack->a[stack->s_a] >= k * i)
				ra(stack->a, stack->s_a, '1');
		}
		if (j == k * i)
			i++;
	}
}

void	indexing(t_list *stack)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	i = -1;
	j = -1;
	k = 0;
	temp = malloc(sizeof(int) * (stack->s_a + 1));
	while (++j <= stack->s_a)
	{
		i = -1;
		while (++i <= stack->s_a)
			if (stack->a[i] < stack->a[j])
				k++;
		temp[j] = k;
		k = 0;
	}
	free (stack->a);
	stack->a = temp;
}

void	sort(t_list *stack)
{
	indexing(stack);
	push_sorted_to_b(stack);
	push_sorted_to_a(stack);
}
