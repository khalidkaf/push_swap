/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:32:26 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 12:11:43 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mep_tab(char *argv[], int argc, t_tab **tab_a, int *tablen_a)
{
	t_main	count;

	count.i = 1;
	*tab_a = malloc(compteur(argv, argc) * sizeof(t_tab));
	if (!tab_a)
		return (0);
	while (argv[count.i])
	{
		if (!only_numbers(argv[count.i]))
			return (printf("Error\n"), 0);
		count.tmp = ft_atoi(argv[count.i]);
		if (count.tmp > 2147483647 || count.tmp < -2147483648 || (count.tmp == 0
				&& (!ft_strcmp(argv[count.i], "0") && !ft_strcmp(argv[count.i],
						"-0") && !ft_strcmp(argv[count.i], "+0"))))
			return (printf("Error\n"), 0);
		(*tab_a)[*tablen_a].number = count.tmp;
		(*tab_a)[*tablen_a].index = *tablen_a;
		(*tablen_a) = (*tablen_a) + 1;
		count.i++;
	}
	return (1);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

char	**spliter(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	return (tab);
}

int	mep_tab_args(char *argv[], int argc, t_tab **tab_a, int *tablen_a)
{
	t_main	count;

	count.i = 0;
	*tab_a = malloc(argc * (sizeof(t_tab) + 1));
	if (!tab_a)
		return (0);
	while (argv[count.i])
	{
		if (!only_numbers(argv[count.i]))
			return (printf("Error\n"), 0);
		count.tmp = ft_atoi(argv[count.i]);
		if (count.tmp > 2147483647 || count.tmp < -2147483648 || (count.tmp == 0
				&& (!ft_strcmp(argv[count.i], "0") && !ft_strcmp(argv[count.i],
						"-0") && !ft_strcmp(argv[count.i], "+0"))))
			return (printf("Error\n"), 0);
		(*tab_a)[*tablen_a].number = count.tmp;
		(*tab_a)[*tablen_a].index = *tablen_a;
		(*tablen_a)++;
		count.i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_main	count;
	t_tab	*tab_a;
	int		tablen_a;
	int		tablen_b;
	t_tab	*tab_b;

	count.nbr = compteur(argv, argc);
	if (argc == 1 || (argv[1][0] == '\0') || count.nbr == 0)
		return (0);
	tablen_a = 0;
	if (argc == 2)
	{
		count.str = spliter(argv[1]);
		if (!mep_tab_args(count.str, count.nbr, &tab_a, &tablen_a))
			return (free_split(count.str), free(tab_a), 0);
		free_split(count.str);
	}
	else if (!mep_tab(argv, argc, &tab_a, &tablen_a))
		return (free(tab_a), 0);
	tri_index(&tab_a, &tablen_a);
	if (checker(tab_a, &tablen_a) == 0 || checkdoublon(tab_a, &tablen_a) == 1)
		return (free(tab_a), 1);
	tablen_b = 0;
	tab_b = malloc(0 * sizeof(t_tab));
	return (tri(&tab_a, &tab_b, &tablen_a, &tablen_b), free(tab_a), 1);
}

// COMMANDE POUR TESTER DEPUIS LE TERMINAL
// ./push_swap $(shuf -i 1-1000 -n 100)

// int	main(int argc, char *argv[])
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	t_tab	*tab_a;
// 	long	tmp;
// 	int		tablen_a;
// 	int		z;
// 	int		tablen_b;
// 	t_tab	*tab_b;

// 	z = 0;
// 	i = 1;
// 	j = 0;
// 	k = 0;
// 	if (argc < 2 || argv[1][0] == '\0')
// 	{
// 		return (1);
// 	}
// 	while (argv[i])
// 	{
// 		while (j < (int)ft_strlen(argv[i]))
// 		{
// 			if (argv[i][j] == 0)
// 				i++;
// 			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
// 				&& argv[i][j] != '+' && argv[i][j] != '-')
// 			{
// 				printf("Error\n");
// 				return (1);
// 			}
// 			if (((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'
// 					|| argv[i][j] == '+') && (argv[i][j - 1] == ' ' || j == 0))
// 			{
// 				if (ft_atoi(argv[i] + (long)j) > 2147483647 || ft_atoi(argv[i]
// 						+ (long)j) == -2147483649)
// 				{
// 					printf("Error\n");
// 					return (0);
// 				}
// 				tmp = ft_atoi(argv[i] + (long)j);
// 				if (tmp > 2147483647 || tmp < -2147483648)
// 				{
// 					printf("Error\n");
// 					return (0);
// 				}
// 				if (tmp < -2147483648)
// 				{
// 					printf("Error\n");
// 				}
// 				j++;
// 				k++;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	tab_a = malloc(k * sizeof(t_tab));
// 	if (!tab_a)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	k = 0;
// 	i = 0;
// 	j = 0;
// 	while (argv[i])
// 	{
// 		while (j < (int)ft_strlen(argv[i]))
// 		{
// 			if (argv[i][j] == 0)
// 				i++;
// 			if (((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'
// 					|| argv[i][j] == '+') && (argv[i][j - 1] == ' ' || j == 0))
// 			{
// 				tmp = ft_atoi(argv[i] + j);
// 				if (tmp > 2147483647 || tmp < -2147483648)
// 				{
// 					printf("Error\n");
// 					return (0);
// 				}
// 				tab_a[k].number = tmp;
// 				tab_a[k].index = k;
// 				j++;
// 				k++;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	tablen_a = k;
// 	tri_index(&tab_a, &tablen_a);
// 	if (checker(tab_a, &tablen_a) == 0)
// 	{
// 		return (1);
// 	}
// 	if (checkdoublon(tab_a, &tablen_a) == 1)
// 	{
// 		return (1);
// 	}
// 	tablen_b = 0;
// 	tab_b = malloc(0 * sizeof(t_tab));
// 	if (tablen_b > 0)
// 		tab_b = malloc(sizeof(t_tab) * tablen_b);
// 	z = 0;
// 	while (z < tablen_a)
// 	{
// 		z++;
// 	}
// 	z = 0;
// 	while (z < tablen_b)
// 	{
// 		z++;
// 	}
// 	tri(&tab_a, &tab_b, &tablen_a, &tablen_b);
// 	z = 0;
// 	if (tab_a)
// 		free(tab_a);
// 	if (tab_b)
// 		free(tab_b);
// }