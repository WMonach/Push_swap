/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:31:04 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/04 15:44:36 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_push_swap.h"

char	**ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (NULL);
}

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

static char	**ft_malloc_ws(char const	*str, char charset, char **tab, int j)
{
	int	i;
	int	wlen;

	i = 0;
	while (str[i])
	{
		wlen = 0;
		while (str[i] == charset && str[i])
			i++;
		while (str[i] != charset && str[i])
		{
			i++;
			wlen++;
		}
		tab[j] = (char *)malloc(sizeof(char) * (wlen + 1));
		tab[j][wlen] = '\0';
		if (tab[j] == NULL)
			return (NULL);
		while (str[i] == charset && str[i])
			i++;
	}
	return (tab);
}

char	**ft_delete_ex(char **argv, int *size)
{
	char	**tab;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (*size));
	while (i < *size)
	{
		tab = ft_malloc_ws(argv[i], ' ', tab, j);
		if (tab == NULL)
			return (NULL);
		tab[j] = argv[i];
		i++;
		j++;
	}
	tab[j] = NULL;
	*size = j;
	return (tab);
}

static int	ft_nbr_words(char const	*str, char charset)
{
	int	nbrw;
	int	i;

	nbrw = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == charset && str[i])
		{
			i++;
		}
		if (str[i] != charset && str[i])
			nbrw++;
		while (str[i] != charset && str[i])
		{
			i++;
		}
	}
	return (nbrw);
}

char	**ft_check_quote(char **argv, int *size)
{
	char	**tab;

	*size = ft_nbr_words(argv[1], ' ');
	if (*size == 2)
		return (NULL);
	tab = ft_split(argv[1], ' ');
	return (tab);
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
		return (ft_error());
	if (*size == 2)
	{
		tab = ft_check_quote(argv, size);
		if (tab == NULL)
			return (ft_error());
	}
	else
	{
		tab = ft_delete_executable(argv, size);
		if (tab == NULL)
			return (ft_error());
	}
	if (ft_check_int(*size, tab) == 0)
		return (ft_error());
	if (ft_check_max_min(*size, tab) == 0)
		return (ft_error());
	if (ft_check_duplicate(*size, tab) == 0)
		return (ft_error());
	return (tab);
}
