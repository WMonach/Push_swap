/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:10:20 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 11:57:37 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	void	*tmp;

	tmp = (*tab_a)->next;
	(*tab_a)->next = *tab_b;
	*tab_b = *tab_a;
	*tab_a = tmp;
	write(1, "pb\n", 3);
	return (1);
}

int	ft_push_a(t_list **tab_a, t_list **tab_b)
{
	void	*tmp;

	tmp = (*tab_b)->next;
	(*tab_b)->next = *tab_a;
	*tab_a = *tab_b;
	*tab_b = tmp;
	write(1, "pa\n", 3);
	return (1);
}

/*prendre le premier element d'une liste et la rajouter a a debut de l'autre
liste, comme rotate il faut creer une liste tmp*/