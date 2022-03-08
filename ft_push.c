/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:10:20 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/04 17:20:25 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	ft_push_b(t_list **tab_a, t_list **tab_b)
// {
// 	t_list	*tmp;
// 	t_list	*tempi;

// 	tmp = *tab_a;
// 	*tab_a = (*tab_a)->next;
// 	tempi = ft_lstnew(tmp->content);
// 	if (!tempi)
// 		return (-1);
// 	ft_lstadd_front(tab_b, tempi);
// 	write(1, "pb\n", 3);
// 	free(tmp);
// 	return (0);
// }

int	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	void	*tmp;
	t_list	*newlist;

	print_stack(*tab_a);
	tmp = (*tab_a)->content;
	*tab_a = (*tab_a)->next;
	newlist = ft_lstnew(tmp);
	if (!newlist)
		return (-1);
	ft_lstadd_front(tab_b, newlist);
	write(1, "pb\n", 3);
	free(newlist);
	print_stack(*tab_a);
	printf("\n");
	return (1);
}

int	ft_push_a(t_list **tab_a, t_list **tab_b)
{
	void	*tmp;
	t_list	*newlist;

	tmp = (*tab_b)->content;
	*tab_b = (*tab_b)->next;
	newlist = ft_lstnew(tmp);
	if (!newlist)
		return (-1);
	ft_lstadd_front(tab_a, newlist);
	write(1, "pa\n", 3);
	free(newlist);
	return (1);
}

/*prendre le premier element d'une liste et la rajouter a a debut de l'autre
liste, comme rotate il faut creer une liste tmp*/