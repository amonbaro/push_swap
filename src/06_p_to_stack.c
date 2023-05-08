/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_p_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:28:35 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:25 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *str, t_list *stack, char **c)
{
	int			i;
	long long	j;
	long long	k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] == '0' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			quit(stack, 1, c);
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + ((long long)str[i] - 48);
		i++;
	}
	return (j * k);
}

void	param_to_stack(t_list *stack, char **c, int j)
{
	int			i;
	long long	k;

	i = 0;
	stack->s_b = -1;
	stack->a = malloc(sizeof(int) * j);
	stack->b = malloc(sizeof(int) * j);
	if (!stack->a || !stack->b)
		quit(stack, 1, c);
	while (c[i])
	{
		k = ft_atoi(c[i], stack, c);
		if (k > 2147483647 || k < -2147483648)
			quit(stack, 1, c);
		stack->a[j - i - 1] = (int)k;
		i++;
	}
	stack->s_a = i - 1;
}
