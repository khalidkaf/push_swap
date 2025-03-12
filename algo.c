/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:48:07 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 12:24:38 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_tab *tab_a, int *tablen_a)
{
	int	i;

	if (!*tablen_a || !tab_a)
		return (1);
	i = 1;
	while (i < *tablen_a && tab_a[i - 1].index < tab_a[i].index)
		i++;
	if (i == *tablen_a)
	{
		return (0);
	}
	return (1);
}

int	checkdoublon(t_tab *tab_a, int *tablen_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < *tablen_a)
	{
		while (j < *tablen_a)
		{
			if (tab_a[i].number == tab_a[j].number)
			{
				printf("Error");
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	tri_three(t_tab **tab_a, int *tablen_a)
{
	int	max;
	int	min;
	int	i;

	if (!*tablen_a || !tab_a)
		return ;
	max = (*tab_a)[0].number;
	min = (*tab_a)[0].number;
	i = -1;
	while (++i < *tablen_a)
	{
		if ((*tab_a)[i].number < min)
			min = (*tab_a)[i].number;
		if ((*tab_a)[i].number > max)
			max = (*tab_a)[i].number;
	}
	while (checker(*tab_a, tablen_a) != 0)
	{
		if ((*tab_a)[2].number == max)
			sa(*tab_a, tablen_a);
		else if ((*tab_a)[0].number == min || (*tab_a)[1].number == max)
			rra(*tab_a, tablen_a);
		else if ((*tab_a)[0].number == max)
			ra(*tab_a, tablen_a);
	}
}

void	tri_four(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	int	max;
	int	min;
	int	i;

	max = (*tab_a)[0].number;
	min = (*tab_a)[0].number;
	i = -1;
	while (++i < *tablen_a)
	{
		if ((*tab_a)[i].number < min)
			min = (*tab_a)[i].number;
	}
	if ((*tab_a)[1].number == min)
		ra(*tab_a, tablen_a);
	if ((*tab_a)[2].number == min)
	{
		ra(*tab_a, tablen_a);
		ra(*tab_a, tablen_a);
	}
	if ((*tab_a)[3].number == min)
		rra(*tab_a, tablen_a);
	pb(*tab_a, tab_b, tablen_a, tablen_b);
	tri_three(tab_a, tablen_a);
	pa(tab_a, *tab_b, tablen_a, tablen_b);
}

void	rra_pa(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	rra(*tab_a, tablen_a);
	pa(tab_a, *tab_b, tablen_a, tablen_b);
}
