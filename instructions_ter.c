/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:30:02 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 11:58:07 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_tab *tab_a, int *tablen_a)
{
	int		i;
	t_tab	tmp;

	i = 1;
	tmp = tab_a[*tablen_a - 1];
	while (i < *tablen_a)
	{
		tab_a[*tablen_a - i] = tab_a[*tablen_a - i - 1];
		i++;
	}
	tab_a[0] = tmp;
	printf("rra\n");
}

void	rrb(t_tab *tab_b, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	tmp = tab_b[*tablen_b - 1];
	while (i < *tablen_b)
	{
		tab_b[*tablen_b - i] = tab_b[*tablen_b - i - 1];
		i++;
	}
	tab_b[0] = tmp;
	printf("rrb\n");
}

void	rrr(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b)
{
	int		i;
	t_tab	tmp;

	i = 0;
	tmp = tab_a[*tablen_a - 1];
	while (i < *tablen_a)
	{
		tab_a[*tablen_a - i - 1] = tab_a[*tablen_a - i - 2];
		i++;
	}
	tab_a[0] = tmp;
	i = 0;
	tmp = tab_b[*tablen_b - 1];
	while (i < *tablen_b)
	{
		tab_b[*tablen_b - i - 1] = tab_b[*tablen_b - i - 2];
		i++;
	}
	tab_b[0] = tmp;
	printf("rrr\n");
}

// int	condi(char c, char d, char e, int i)
// {
// 	if(e == 'a')
// 		return (0);
// 	if ((c < '0' || c > '9') && c != ' '
// 		&& c != '+' && c != '-')
// 	{
// 		// printf("Error\n");
// 		return (0);
// 	}
// 	if (((c >= '0' && c <= '9') || c == '-'
// 			|| c == '+') && (d == ' ' || i == 0))
// 	{
// 		// if (ft_atoi(argv[i] + (long)j) > 2147483647 || ft_atoi(argv[i]
// 		// 		+ (long)j) == -2147483649)
// 		// {
// 		// 	printf("Error\n");
// 		// 	return (0);
// 		// }
// 		return (1);
// 	}
// 	else
// 	return (1);
// }
int	condi(char c, char d, char e, int i)
{
	if (d == ' ' || i != 0)
		return (0);
	if ((c < '0' || c > '9') && (c != '+' && c != '+'))
		return (0);
	if (e != ' ' && e != '\0' && e != '0' && e != '1' && e != '2' && e != '3'
		&& e != '4' && e != '5' && e != '6' && e != '7' && e != '8' && e != '9')
		return (0);
	else
		return (1);
}
