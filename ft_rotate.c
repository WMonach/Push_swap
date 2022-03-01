/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:14:35 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/01 13:45:38 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_rotate_a(t_list **tab_a)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_a;
	*tab_a = (*tab_a)->next;
	tempi = ft_lstnew(tmp->content);
	if (tempi == NULL)
		return (-1);
	ft_lstadd_back(tab_a, tempi);
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rotate_b(t_list **tab_b)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_b;
	*tab_b = (*tab_b)->next;
	tempi = ft_lstnew(tmp->content);
	if (tempi == NULL)
		return (-1);
	ft_lstadd_back(tab_b, tempi);
	write(1, "rb\n", 3);
	return (0);
}
