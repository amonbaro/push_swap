/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_in_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:26:56 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:25 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*c;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = ' ';
	}
	if (!s2)
		return (NULL);
	c = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (NULL);
	while (s1[++i])
		c[i] = s1[i];
	while (s2[j])
		c[i++] = s2[j++];
	c[i] = '\0';
	free (s1);
	return (c);
}

int	check_space(char **c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == ' ' && j == 0)
				return (0);
			if (c[i][j] == ' ' && (c[i][j + 1] == ' ' || c[i][j + 1] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**parc(char **argv, char **temp, int *j)
{
	int		i;
	char	*tab;

	i = 1;
	tab = NULL;
	if (check_space(argv) == 0)
		quit(0, 5, 0);
	while (argv[i])
	{
		tab = ft_strjoin(tab, argv[i++]);
		tab = ft_strjoin(tab, " ");
	}
	temp = ft_split(tab, ' ');
	i = 0;
	free (tab);
	if (!temp)
		exit (0);
	while (temp[i])
		i++;
	*j = i;
	return (temp);
}

void	is_argc_ok(int i)
{
	if (i < 2)
		exit (0);
}
