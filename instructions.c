/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:01:16 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/11 08:43:57 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tab *tab_a, int *tablen_a)
{
	int		i;
	t_tab	tmp;

	i = 0;
	if (*tablen_a < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_a);
	}
	else
	{
		tmp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = tmp;
	}
	printf("sa\n");
}

void	sb(t_tab *tab_b, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	if (*tablen_b < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_b);
	}
	else
	{
		tmp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = tmp;
	}
	printf("sb\n");
}

void	ss(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	if (*tablen_a < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_a);
	}
	else if (*tablen_b < 2)
	{
		printf("il n y a que %d arguments, il en faut au moins 2 !!!\n",
			*tablen_b);
	}
	else
	{
		tmp = tab_a[0];
		tab_a[0] = tab_a[1];
		tab_a[1] = tmp;
		tmp = tab_b[0];
		tab_b[0] = tab_b[1];
		tab_b[1] = tmp;
	}
	printf("ss\n");
}

void	pa(t_tab **tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b)
{
	int		taille;
	int		i;
	t_tab	*tab_tmp;

	if (*tablen_b == 0)
		return ;
	taille = *tablen_a;
	i = -1;
	*tablen_a = taille + 1;
	tab_tmp = malloc(sizeof(t_tab) * taille);
	while (++i < taille)
		tab_tmp[i] = (*tab_a)[i];
	if (*tab_a)
		free(*tab_a);
	*tab_a = malloc(sizeof(t_tab) * (*tablen_a));
	(*tab_a)[0] = tab_b[0];
	i = -1;
	while (++i < taille)
		(*tab_a)[i + 1] = tab_tmp[i];
	i = -1;
	while (++i < *tablen_b - 1)
		tab_b[i] = tab_b[i + 1];
	*tablen_b = *tablen_b - 1;
	free(tab_tmp);
	printf("pa\n");
}

void	pb(t_tab *tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	int		taille;
	int		i;
	t_tab	*tab_tmp;

	if (*tablen_a == 0)
		return ;
	taille = *tablen_b;
	i = -1;
	*tablen_b = taille + 1;
	tab_tmp = malloc(sizeof(t_tab) * taille);
	while (++i < taille)
		tab_tmp[i] = (*tab_b)[i];
	if (*tab_b)
		free(*tab_b);
	*tab_b = malloc(sizeof(t_tab) * (*tablen_b));
	(*tab_b)[0] = tab_a[0];
	i = -1;
	while (++i < taille)
		(*tab_b)[i + 1] = tab_tmp[i];
	i = -1;
	while (++i < *tablen_a - 1)
		tab_a[i] = tab_a[i + 1];
	*tablen_a = *tablen_a - 1;
	free(tab_tmp);
	printf("pb\n");
}
