/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:51:34 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 10:54:53 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

char	**ft_error(char **tab)
{
	ft_putstr_fd("Error\n", 1);
	ft_free_tab(tab);
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
		tab[j][wlen] = '\0';
		if (tab[j] == NULL)
			return (NULL);
		while (str[i] == charset && str[i])
			i++;
	}
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

char	**ft_remove_executable(char **argv, int *size)
{
	char	**tab;
	int		j;
	int		k;
	int		i;

	j = 0;
	i = 1;
	tab = (char **)malloc(sizeof(char *) * (*size));
	while (i < *size)
	{
		tab = ft_malloc_ws(argv[i], ' ', tab, j);
		if (tab == NULL)
			return (NULL);
		k = 0;
		while (argv[i][k] != '\0')
		{
			tab[j][k] = argv[i][k];
			k++;
		}
		tab[j++][k] = '\0';
		i++;
	}
	tab[j] = NULL;
	*size = j;
	return (tab);
}
