/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:31:04 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/15 17:01:28 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}

int	ft_check_quote(char *argv[])
{
	int	i;

	i = 1;
	while (argv[2][i] != '"' )
	{
		if (ft_isdigit(argv[2][i]) == 0)
			return (0);
		i++;
		if (argv[2][i] == '"')
			return (0);
		if (argv[2][i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
			if (argv[i][j] == '-')
				return (0);
		}
		i++;
	}
	return (1);
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
			return (0);
		i++;
	}
	return (1);
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check(int argc, char *argv[])
{
	if (argc < 2)
		return (ft_error());
	printf("1\n");
	if (argc == 3 && argv[2][0] == '"')
	{
		if ((ft_check_quote(argv)) == -1)
			return (ft_error());
	}
	printf("1\n");
	if (ft_check_int(argc, argv) == -1)
		return (ft_error());
	printf("1\n");
	if (ft_check_max_min(argc, argv) == 0)
		return (ft_error());
	printf("1\n");
	if (ft_check_duplicate(argc, argv) == 0)
		return (ft_error());
	return (1);
}

/*
la faut que je fasse un check si arg = "1 2 3 4 5 6"
if '"' while ( if num OK els KO and if ' ' OK els KO) tant que '"'
arg = "1 2 3 4" 5 6 7
algo de theo
pour 5 a 100
envoie en tranche de 12 dans b
et de 12 q 24 dans b puis rb etc
continuer jusqua ne plus rien avoir dans a
ensuite retrier on prend 100 puis 99 etc
*/