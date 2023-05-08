/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_inst_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:33 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:18 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(int *b, int top, char c)
{
	int	i;

	i = 0;
	if (c != '2')
		ft_putstr("sb\n");
	if (top >= 1)
	{
		i = b[top];
		b[top] = b[top - 1];
		b[top - 1] = i;
	}
}

void	pb(int *a, int *s_a, int *b, int *s_b)
{
	ft_putstr("pb\n");
	if (*s_a > -1)
	{
		b[*s_b + 1] = a[*s_a];
		*s_a -= 1;
		*s_b += 1;
	}
}

void	rb(int *b, int top, char c)
{
	int	i;
	int	*temp;

	i = top;
	temp = malloc(sizeof(int) * (top + 1));
	if (!temp)
	{
		free(b);
		exit (0);
	}
	temp[0] = b[top];
	if (c != '2')
		ft_putstr("rb\n");
	while (i > 0)
	{
		temp [i] = b[i - 1];
		i--;
	}
	i = 0;
	while (i <= top)
	{
		b[i] = temp[i];
		i++;
	}
	free (temp);
}

void	rrb(int *b, int top, char c)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (top + 1));
	if (!temp)
	{
		free (b);
		exit (0);
	}
	i = top;
	if (c != '2')
		ft_putstr("rrb\n");
	while (i > 0)
	{
		temp[i - 1] = b[i];
		i--;
	}
	temp[top] = b[0];
	i = 0;
	while (i <= top)
	{
		b[i] = temp[i];
		i++;
	}
	free (temp);
}
