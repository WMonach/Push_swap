/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:29:16 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/26 13:24:31 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		*ft_count(int *temp, int numbers_count)
{
	int	i;
	int	count;
	int	j;
	int *tab;
	
	i = 0;	
	tab = (int *)malloc(sizeof(int) * (numbers_count));
	
	if (tab == NULL)
	{
		free (tab);
		return (NULL);
	}

	while (i < numbers_count)
	{
		count = 0;
		j = 0;
		while (j < numbers_count)
		{
			if (temp[i] > temp[j])
				count++;
			j++;
		}
		tab[i] = count;
		i++;
	}
	
	free(temp);
	return (tab);
}

int	*ft_index(int argc, char **argv)
{
	int	*temp;
	int	i;
	int	j;
	
	i = 1;
	temp = (int *)malloc(sizeof(int) * (argc - 1));
	if (!temp)
	{
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
	return (ft_count(temp, argc - 1));
}
/*pour l'index, on transforme tout les char en int grace a atoi dans
un tableau d'int, ensuite on fait une comparaison des nombres
on prend le premier et on l'incrémente quand on trouve un nombre plus petit
que lui (il commence a 1) on fait tout argc (pg si il repasse sur lui
il y sera egal et on sait que grace au check il y aura que lui)*/