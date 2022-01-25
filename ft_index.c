/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:29:16 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/25 11:18:37 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_count(int **tab, int *temp, int argc)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	while (i < argc)
	{
		count = 0;
		j = 0;
		while (j < argc)
		{
			if (temp[i] > temp[j])
				count++;
			j++;
		}
		tab[0][i] = count;
		i++;
	}
}

int	*ft_index(int argc, char **argv)
{
	int	*tab;
	int	*temp;
	int	i;
	int	j;

	i = 1;
	tab = (int *)malloc(sizeof(int) * argc - 1);
	temp = (int *)malloc(sizeof(int) * argc - 1);
	if (!tab || !temp)
	{
		free (tab);
		free (temp);
		return (NULL);
	}
	j = 0;
	while (i < argc)
	{
		temp[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	ft_count(&tab, temp, argc);
	free(temp);
	return (tab);
}
/*pour l'index, on transforme tout les char en int grace a atoi dans
un tableau d'int, ensuite on fait une comparaison des nombres
on prend le premier et on l'incrémente quand on trouve un nombre plus petit
que lui (il commence a 1) on fait tout argc (pg si il repasse sur lui
il y sera egal et on sait que grace au check il y aura que lui)*/