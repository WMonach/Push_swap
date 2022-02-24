/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:31:04 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/24 13:18:22 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_push_swap.h"

char	**ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (NULL);
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

	*size = ft_nbr_words(argv[1], ' ') + 1;
	tab = ft_split(argv[1], ' ');
	return (tab);
}

int	ft_check_int(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
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

char	**ft_check(int *size, char **argv)
{
	char	**tab;

	tab = argv;
	if (*size < 2)
		return (ft_error());
	if (*size == 2)
	{
		tab = ft_check_quote(tab, size);
		if (tab == NULL)
			return (ft_error());
	}
	else
	{
		tab = ft_delete_ex(argv, size);
		if (tab == NULL)
			return (ft_error());
	}
	if (ft_check_int(*size, tab) == -1)
		return (ft_error());
	if (ft_check_max_min(*size, tab) == 0)
		return (ft_error());
	if (ft_check_duplicate(*size, tab) == 0)
		return (ft_error());
	return (tab);
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