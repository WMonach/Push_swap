/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:14:35 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/04 17:20:00 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_rotate_a(t_list **tab_a)
{
	void	*tmp;
	t_list	*newlist;

	tmp = (*tab_a)->content;
	*tab_a = (*tab_a)->next;
	newlist = ft_lstnew(tmp);
	if (newlist == NULL)
		return (-1);
	ft_lstadd_back(tab_a, newlist);
	write(1, "ra\n", 3);
	free(newlist);
	return (0);
}

int	ft_rotate_b(t_list **tab_b)
{
	void	*tmp;
	t_list	*newlist;

	tmp = (*tab_b)->content;
	*tab_b = (*tab_b)->next;
	newlist = ft_lstnew(tmp);
	if (newlist == NULL)
		return (-1);
	ft_lstadd_back(tab_b, newlist);
	write(1, "rb\n", 3);
	free(newlist);
	return (0);
}
