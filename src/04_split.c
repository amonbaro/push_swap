/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:32:48 by amonbaro          #+#    #+#             */
/*   Updated: 2023/05/08 08:11:21 by amonbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_p(char **p)
{
	free (p);
	return (NULL);
}

static char	*skip(char *s, char c)
{
	while (s && *s == c)
		s++;
	return (s);
}

static int	bigstr(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	smallstr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**p;

	i = 0;
	j = bigstr(s, c);
	p = malloc(sizeof(char *) * (j + 1));
	if (!p || !s)
		return (NULL);
	while (i < j)
	{
		s = skip(s, c);
		len = smallstr(s, c);
		p[i] = malloc(sizeof(char) * (len + 1));
		if (!p[i])
			return (free_p(p));
		k = 0;
		while (k < len)
			p[i][k++] = *s++;
		p[i++][k] = '\0';
	}
	p[i] = NULL;
	return (p);
}
