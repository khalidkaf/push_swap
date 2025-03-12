/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:49:39 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 11:56:39 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compteur_bis(char **str)
{
	int	j;
	int	i;
	int	z;

	j = 0;
	i = 1;
	z = 1;
	while (str[1][j] != '\0')
	{
		if (str[i][j] == ' ')
			z++;
		j++;
	}
	return (z + 1);
}

int	compteur(char *str[], int argc)
{
	int	i;
	int	j;
	int	z;

	z = 0;
	i = 1;
	j = 0;
	if (argc == 2)
	{
		return (compteur_bis(str));
	}
	while (i < argc)
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] == ' ')
				z++;
			j++;
		}
		j = 0;
		i++;
		z++;
	}
	return (z + 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if ((s1[i] != s2[i]) || (!s1[i] || !s2[i]))
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
