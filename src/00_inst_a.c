/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_inst_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:27 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:16:02 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int top, char c)
{
	int	i;

	i = 0;
	if (c != '2')
		ft_putstr("sa\n");
	if (top >= 1)
	{
		i = a[top];
		a[top] = a[top - 1];
		a[top - 1] = i;
	}
}

void	pa(int *a, int *s_a, int *b, int *s_b)
{
	ft_putstr("pa\n");
	if (*s_b > -1)
	{
		a[*s_a + 1] = b[*s_b];
		*s_b -= 1;
		*s_a += 1;
	}
}

void	ra(int *a, int s_a, char c)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (s_a + 1));
	if (!temp)
	{
		free (a);
		exit (0);
	}
	temp[0] = a[s_a];
	if (c != '2')
		ft_putstr("ra\n");
	i = s_a;
	while (i > 0)
	{
		temp[i] = a[i - 1];
		i--;
	}
	i = 0;
	while (i <= s_a)
	{
		a[i] = temp[i];
		i++;
	}
	free (temp);
}

void	rra(int *a, int top, char c)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (top + 1));
	if (!temp)
	{
		free (a);
		exit (0);
	}
	i = top;
	if (c != '2')
		ft_putstr("rra\n");
	while (i > 0)
	{
		temp[i -1] = a[i];
		i--;
	}
	temp[top] = a[0];
	i = 0;
	while (i <= top)
	{
		a[i] = temp[i];
		i++;
	}
	free (temp);
}
