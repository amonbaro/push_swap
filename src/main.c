/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:04:06 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:15:40 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	stack;
	char	**temp;

	temp = NULL;
	is_argc_ok(argc);
	temp = parc(argv, temp, &argc);
	if (check_if_num(temp) == 0)
		quit(&stack, 1, temp);
	param_to_stack(&stack, temp, argc++);
	if (check_repeat(stack.a, stack.s_a) == 0)
		quit(&stack, 1, 0);
	if (check_if_sorted(stack.a, stack.s_a) == 0)
		quit(&stack, 0, 0);
	if (argc >= 3 && argc <= 6)
	{
		if (argc <= 4)
			sort_4nb(&stack, argc);
		if (argc > 4)
			sort_6nb(&stack, argc);
		quit(&stack, 0, 0);
	}
	sort(&stack);
	quit(&stack, 2, temp);
	return (0);
}
