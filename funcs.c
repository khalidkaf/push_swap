/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:14:19 by kkafmagh          #+#    #+#             */
/*   Updated: 2025/03/12 11:55:53 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

long	ft_atoi(const char *str)
{
	long	res;
	long	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i])
	{
		if (!ft_isnum(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		if (str[i] == '-' || str[i] == '+')
		{
			if (i >= 1 && ft_isnum(str[i - 1]))
				return (0);
			if (!ft_isnum(str[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
