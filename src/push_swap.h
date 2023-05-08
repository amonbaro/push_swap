/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:05:14 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:15:41 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stab
{
	int	*a;
	int	*b;
	int	s_a;
	int	s_b;
}	t_list;

// 00_inst_a.c
void		sa(int *a, int top, char c);
void		pa(int *a, int *s_a, int *b, int *s_b);
void		ra(int *a, int s_a, char c);
void		rra(int *a, int top, char c);

// 01_inst_b.c
void		sb(int *b, int top, char c);
void		pb(int *a, int *s_a, int *b, int *s_b);
void		rb(int *b, int top, char c);
void		rrb(int *b, int top, char c);

// 02_inst_ab.c
void		ss(int *a, int s_a, int *b, int s_b);
void		rr(int *a, int s_a, int *b, int s_b);
void		rrr(int *a, int s_a, int *b, int s_b);

// 03_utils.c
void		quit(t_list *stack, int i, char **c);
void		ft_putstr(char *c);
int			check_repeat(int *k, int top);
int			check_if_num(char **c);

// 04_split.c
char		**ft_split(char *s, char c);

// 05_in_tab.c
int			ft_strlen(char *c);
char		*ft_strjoin(char *s1, char *s2);
int			check_space(char **c);
char		**parc(char **argv, char **temp, int *j);
void		is_argc_ok(int i);

// 06_p_to_stack.c
long long	ft_atoi(char *str, t_list *stack, char **c);
void		param_to_stack(t_list *stack, char **c, int j);

// 07_sort_4nb.c
int			check_if_sorted(int *k, int top);
void		sort_4nb(t_list *stack, int i);

// 08_sort_6nb.c
int			find_j(int *k, int top, int j);
int			find_i(int *k, int top, int j);
int			find_small(int *k, int top);
void		push_to_b(t_list *stack);
void		sort_6nb(t_list *stack, int i);

// 09_push_sort.c
void		loop_sort_a(t_list *stack, int *k, int j);
void		push_sorted_to_a(t_list *stack);
void		push_sorted_to_b(t_list *stack);
void		indexing(t_list *stack);
void		sort(t_list *stack);

#endif
