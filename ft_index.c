/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:29:16 by wmonacho          #+#    #+#             */
/*   Updated: 2021/12/30 12:02:17 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_count(int **tab, int **temp, int argc, char *argv[])
{
	int	i;
	int	count;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		count = 0;
		j = 0;
		while (j < argc - 1)
		{
			if (temp[i] > temp[j++])
				count++;
		}
		tab[i] = count;
		i++;
	}
}

int	*ft_index(int argc, char *argv[])
{
	int	*tab;
	int	*temp;
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int) * argc - 1);
	temp = (int *)malloc(sizeof(int) * argc - 1);
	if (!tab || !temp)
	{
		free (tab);
		free (temp);
		return (-1);
	}
	while (i < argc - 1)
		temp[i] = ft_atoi(argv[i++]);
	ft_count(&tab, &temp, argc, argv);
	free(temp);
	return (tab);
}
/*pour l'index, on transforme tout les char en int grace a atoi dans
un tableau d'int, ensuite on fait une comparaison des nombres
on prend le premier et on l'incrémente quand on trouve un nombre plus petit
que lui (il commence a 1) on fait tout argc (pg si il repasse sur lui
il y sera egal et on sait que grace au check il y aura que lui)*/