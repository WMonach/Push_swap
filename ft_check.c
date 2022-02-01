/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:31:04 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/01 16:23:52 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (-1);
}

int	ft_check_int(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
			if (argv[i][j] == '-')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_max_min(int argc, char *argv[])
{
	int		i;
	long	number;

	i = 0;
	while (i < argc - 1)
	{
		number = ft_atoi(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_duplicate(int argc, char *argv[])
{
	int		i;
	int		j;
	long	number;
	long	numberone;

	i = 0;
	while (i < argc - 1)
	{
		number = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc - 1)
		{
			numberone = ft_atoi(argv[j]);
			if (numberone == number && numberone != '"')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check(int argc, char *argv[])
{
	if (argc < 3)
		return (ft_error());
	if (ft_check_int(argc, argv) == -1)
		return (ft_error());
	if (ft_check_max_min(argc, argv) == -1)
		return (ft_error());
	if (ft_check_duplicate(argc, argv) == -1)
		return (ft_error());
	return (0);
}
