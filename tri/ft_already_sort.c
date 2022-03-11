/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_already_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:53:00 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 13:11:24 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_already_sort(int	*index, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (index[i] > index[i + 1])
			return (0);
		i++;
	}
	return (1);
}
