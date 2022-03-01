/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:29:16 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/01 10:18:46 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*ft_free(int *str)
{
	if (str)
		free(str);
	return (NULL);
}

int	*ft_count(int *temp, int numbers_count)
{
	int	i;
	int	count;
	int	j;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (numbers_count + 1));
	if (tab == NULL)
		return (ft_free(tab));
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

int	*ft_index(int argc, char **tab)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = (int *)malloc(sizeof(int) * (argc));
	if (temp == NULL)
		return (ft_free(temp));
	j = 0;
	while (i < argc)
	{
		temp[j] = ft_atoi(tab[i]);
		i++;
		j++;
	}
	return (ft_count(temp, argc));
}
/*
faudrait que j'arrive a mettre ./push_swap dans mon tab aussi
*/