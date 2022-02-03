/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:15:09 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/03 09:52:10 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_swap_a(t_list **tab_a)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_a;
	*tab_a = (*tab_a)->next;
	tempi = ft_lstnew(tmp->content);
	if (!tempi)
		return (-1);
	ft_lstadd_front(tab_a, tempi);
	write(1, "sa\n", 3);
	free(tmp);
	return (0);
}

int	ft_swap_b(t_list **tab_b)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_b;
	*tab_b = (*tab_b)->next;
	tempi = ft_lstnew(tmp->content);
	if (!tempi)
		return (-1);
	ft_lstadd_front(tab_b, tempi);
	write(1, "sb\n", 4);
	free(tmp);
	return (0);
}

/*pour swap, on veut  mettre le 2e element a la premniere place
et le premier a la seconde, ca ressemble un peu a un list sort
pour ce faire on cree un tmp egal a tab_a
on cree une liste tempi que l'on met ensuite au debut de tab_a
et on fait avancer tab_a juste avant*/