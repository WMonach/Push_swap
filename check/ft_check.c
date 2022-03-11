/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:31:04 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 10:36:23 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	nb;
	int		i;
	long	minus;

	i = 0;
	nb = 0;
	minus = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	nb = nb * minus;
	return (nb);
}

int	ft_check_int(int size, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '-')
				j++;
			if (ft_isdigit(tab[i][j]) == 0)
				return (0);
			j++;
			if (tab[i][j] == '-')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_max_min(int size, char **tab)
{
	int		i;
	long	number;

	i = 0;
	while (i < size)
	{
		number = ft_atoi_long(tab[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int size, char **tab)
{
	int		i;
	int		j;
	long	number;
	long	numberone;

	i = 0;
	while (i < size)
	{
		number = ft_atoi(tab[i]);
		j = i + 1;
		while (j < size)
		{
			numberone = ft_atoi(tab[j]);
			if (numberone == number)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_check(int *size, char **argv)
{
	char	**tab;

	if (*size < 2)
		return (NULL);
	if (*size == 2)
	{
		tab = ft_check_quote(argv, size);
		if (tab == NULL)
			return (ft_error(tab));
	}
	else
	{
		tab = ft_remove_executable(argv, size);
		if (tab == NULL)
			return (ft_error(tab));
	}
	if (ft_check_int(*size, tab) == 0)
		return (ft_error(tab));
	if (ft_check_max_min(*size, tab) == 0)
		return (ft_error(tab));
	if (ft_check_duplicate(*size, tab) == 0)
		return (ft_error(tab));
	return (tab);
}
