/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:33:52 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:15:59 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_list *stack, int i, char **c)
{
	if (i == 1 || i == 5)
		ft_putstr("Error\n");
	if (i != 2 && i != 5)
	{
		free (stack->a);
		free (stack->b);
		if (c)
			free (c);
	}
	exit (0);
}

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	check_repeat(int *k, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (k[i] == k[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_num(char **c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!c || !*c)
		return (0);
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (j == 0 && (c[i][j] == '-' || c[i][j] == '+'))
				j++;
			if (c[i][j] < '0' || c[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
