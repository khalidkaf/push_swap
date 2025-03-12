/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:10:42 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/11 17:43:17 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_five_bis(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	while (*tablen_b > 0)
	{
		if ((*tab_b)[0].index == 5)
		{
			pa(tab_a, *tab_b, tablen_a, tablen_b);
			ra(*tab_a, tablen_a);
		}
		else if ((*tab_b)[0].index == 4)
		{
			rra_pa(tab_a, tab_b, tablen_a, tablen_b);
		}
		else if ((*tab_b)[0].index == 3)
		{
			rra(*tab_a, tablen_a);
			rra_pa(tab_a, tab_b, tablen_a, tablen_b);
		}
		else if ((*tab_b)[0].index == 2)
		{
			ra(*tab_a, tablen_a);
			pa(tab_a, *tab_b, tablen_a, tablen_b);
		}
		else if ((*tab_b)[0].index == 1)
			pa(tab_a, *tab_b, tablen_a, tablen_b);
	}
}

void	tri_five(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	pb(*tab_a, tab_b, tablen_a, tablen_b);
	tri_four(tab_a, tab_b, tablen_a, tablen_b);
	tri_five_bis(tab_a, tab_b, tablen_a, tablen_b);
	while ((*tab_a)[0].index != 1)
		rra(*tab_a, tablen_a);
}

void	tri_index(t_tab **tab_a, int *tablen_a)
{
	int	i;
	int	j;
	int	k;

	if (!*tablen_a || !tab_a)
		return ;
	i = 0;
	j = 0;
	k = *tablen_a;
	i = 0;
	while (i < *tablen_a)
	{
		while (j < *tablen_a)
		{
			if ((*tab_a)[i].number < (*tab_a)[j].number)
			{
				k--;
			}
			(*tab_a)[i].index = k;
			j++;
		}
		k = *tablen_a;
		j = 0;
		i++;
	}
}

void	tri_sup_cinq(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	t_compteur	compteur;

	compteur.copy = *tablen_a;
	compteur.i = 0;
	compteur.j = 0;
	compteur.count = 0;
	while (checker(*tab_a, tablen_a) != 0 || *tablen_b > 0)
	{
		compteur.i = 0;
		while (compteur.i < compteur.copy)
		{
			if ((((*tab_a)[0].index >> compteur.j) % 2) == 0)
				pb(*tab_a, tab_b, tablen_a, tablen_b);
			else if ((((*tab_a)[0].index >> compteur.j) % 2) == 1)
				ra(*tab_a, tablen_a);
			compteur.i++;
			compteur.count++;
		}
		while (*tablen_b > 0)
		{
			pa(tab_a, *tab_b, tablen_a, tablen_b);
			compteur.count++;
		}
		compteur.j++;
	}
}

// void	tri_sup_cinq(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
// {
// 	t_compteur	compteur;

// 	compteur.i = 0;
// 	compteur.j = 0;
// 	compteur.count = 0;
// 	while (checker(*tab_a, tablen_a) == 1 || *tablen_b > 0)
// 	{
// 		compteur.i = 0;
// 		while (compteur.i < *tablen_a)
// 		{
// 			if ((((*tab_a)[0].index >> compteur.j) % 2) == 0)
// 				pb(*tab_a, tab_b, tablen_a, tablen_b);
// 			else if ((((*tab_a)[0].index >> compteur.j) % 2) == 1)
// 				ra(*tab_a, tablen_a);
// 			compteur.i++;
// 			compteur.count++;
// 		}
// 		while (*tablen_b > 0)
// 		{
// 			pa(tab_a, *tab_b, tablen_a, tablen_b);
// 			compteur.count++;
// 		}
// 		compteur.j++;
// 	}
// }

void	tri(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b)
{
	int	i;
	int	copy;
	int	j;
	int	count;

	i = 0;
	copy = *tablen_a;
	j = 0;
	count = 0;
	tri_index(tab_a, tablen_a);
	if (*tablen_a <= 3)
		tri_three(tab_a, tablen_a);
	else if (*tablen_a == 4)
		tri_four(tab_a, tab_b, tablen_a, tablen_b);
	else if (*tablen_a == 5)
		tri_five(tab_a, tab_b, tablen_a, tablen_b);
	else
		tri_sup_cinq(tab_a, tab_b, tablen_a, tablen_b);
	free(*tab_b);
}
