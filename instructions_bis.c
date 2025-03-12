/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:28:57 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/08 12:37:51 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_tab *tab_a, int *tablen_a)
{
	int		i;
	t_tab	tmp;

	i = 0;
	tmp = tab_a[0];
	while (i < *tablen_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[*tablen_a - 1] = tmp;
	printf("ra\n");
}

void	rb(t_tab *tab_b, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	tmp = tab_b[0];
	while (i < *tablen_b)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[*tablen_b - 1] = tmp;
	printf("rb\n");
}

void	rr(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	tmp = tab_a[0];
	while (i < *tablen_a)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[*tablen_a - 1] = tmp;
	tmp = tab_b[0];
	i = 0;
	while (i < *tablen_b)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[*tablen_b - 1] = tmp;
	printf("rr\n");
}
