/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:40:56 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 12:05:19 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_tab
{
	int		number;
	int		index;
}			t_tab;

typedef struct s_compteur
{
	int		i;
	int		j;
	int		count;
	int		copy;
}			t_compteur;

typedef struct s_main
{
	int		i;
	int		j;
	long	tmp;
	char	**str;
	int		nbr;
}			t_main;

size_t		ft_strlen(const char *s);

int			only_numbers(char *str);

int			countwords(char *s, char c);

char		**ft_split(char *s, char c);

int			ft_isalnum(int c);

int			only_numbers(char *str);

int			compteur_bis(char **str);

int			compteur(char *str[], int argc);

int			ft_strcmp(const char *s1, const char *s2);

long		ft_atoi(const char *nptr);

void		sa(t_tab *tab_a, int *tablen_a);

void		sb(t_tab *tab_b, int *tablen_b);

void		ss(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b);

void		pa(t_tab **tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b);

void		pb(t_tab *tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b);

void		ra(t_tab *tab_a, int *tablen_a);

void		rb(t_tab *tab_b, int *tablen_b);

void		rr(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b);

void		rra(t_tab *tab_a, int *tablen_a);

void		rrb(t_tab *tab_b, int *tablen_b);

void		rrr(t_tab *tab_a, t_tab *tab_b, int *tablen_a, int *tablen_b);

int			checkdoublon(t_tab *tab_a, int *tablen_a);

void		tri_three(t_tab **tab_a, int *tablen_a);

void		tri_four(t_tab **tab_a, t_tab **tab_b, int *tablen_a,
				int *tablen_b);

void		rra_pa(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b);

void		tri_five_bis(t_tab **tab_a, t_tab **tab_b, int *tablen_a,
				int *tablen_b);

void		tri_five(t_tab **tab_a, t_tab **tab_b, int *tablen_a,
				int *tablen_b);

void		tri_sup_cinq(t_tab **tab_a, t_tab **tab_b, int *tablen_a,
				int *tablen_b);

int			checker(t_tab *tab_a, int *tablen_a);

void		tri(t_tab **tab_a, t_tab **tab_b, int *tablen_a, int *tablen_b);

void		tri_index(t_tab **tab_a, int *tablen_a);

int			condi(char c, char d, char e, int i);

int			compteur_bis(char **str);

int			compteur(char *str[], int argc);

int			ft_strcmp(const char *s1, const char *s2);

int			mep_tab(char *argv[], int argc, t_tab **tab_a, int *tablen_a);

void		free_split(char **tab);

char		**spliter(char *str);

int			mep_tab_args(char *argv[], int argc, t_tab **tab_a, int *tablen_a);

#endif