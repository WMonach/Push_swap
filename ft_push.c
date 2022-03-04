/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:10:20 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/03 10:13:19 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_a;
	*tab_a = (*tab_a)->next;
	tempi = ft_lstnew(tmp->content);
	if (!tempi)
		return (-1);
	ft_lstadd_front(tab_b, tempi);
	write(1, "pb\n", 3);
	free(tmp);
	return (0);
}

int	ft_push_a(t_list **tab_a, t_list **tab_b)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_b;
	*tab_b = (*tab_b)->next;
	tempi = ft_lstnew(tmp->content);
	if (!tempi)
		return (-1);
	ft_lstadd_front(tab_a, tempi);
	write(1, "pa\n", 3);
	free(tmp);
	return (0);
}

/*prendre le premier element d'une liste et la rajouter a a debut de l'autre
liste, comme rotate il faut creer une liste tmp*/