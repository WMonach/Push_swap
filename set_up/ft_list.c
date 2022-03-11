/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:31:53 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 11:09:17 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list	*ft_list_a(int numbers_len, int *tab)
{
	int		i;
	t_list	*tab_a;

	i = 0;
	tab_a = NULL;
	while (i < numbers_len)
	{
		ft_lstadd_back(&tab_a, ft_lstnew((void *)&tab[i]));
		if (!tab_a)
			return (NULL);
		i++;
	}
	return (tab_a);
}

t_list	*ft_list_b(void)
{
	t_list	*tab_b;

	tab_b = NULL;
	return (tab_b);
}
