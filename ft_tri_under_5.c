/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_under_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:48:29 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/03 19:37:14 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_tri_3(t_list *tab_a)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = *(int *)(tab_a->content);
	nb1 = *(int *)(tab_a->next->content);
	nb2 = *(int *)(tab_a->next->next->content);
	if (nb0 > nb1 && nb1 < nb2 && nb0 > nb2)
		write(1, "ra\n", 2);
	if (nb0 < nb1 && nb1 > nb2 && nb0 > nb2)
		write(1, "rra\n", 4);
	if (nb0 > nb1 && nb1 > nb2 && nb0 > nb2)
		write(1, "sa\nrra\n", 7);
	if (nb0 > nb1 && nb1 < nb2 && nb0 < nb2)
		write(1, "sa\n", 3);
	if (nb0 < nb1 && nb1 > nb2 && nb0 < nb2)
		write(1, "rra\nsa\n", 7);
}

void	ft_tri_4(t_list *tab_a)
{
	int	nb3;
	int	nb2;
	int	nb1;
	int	nb0;

	nb3 = *(int *)(tab_a->content);
	nb0 = *(int *)(tab_a->next->content);
	nb1 = *(int *)(tab_a->next->next->content);
	nb2 = *(int *)(tab_a->next->next->next->content);
	write(1, "pb\n", 3);
	ft_tri_3(tab_a->next);
	write(1, "pa\n", 3);
	if (nb3 == 1)
		write(1, "sa\n", 3);
	if (nb3 == 2 || (nb3 == 3 && (nb2 == 4 || nb1 == 4 || nb0 == 4)))
		write(1, "rra\nsa\nra\nra", 12);
	if (nb3 >= 4)
		write(1, "ra\n", 3);
}

void	ft_tri_5(t_list *tab_a)
{
	int	nb4;

	nb4 = *(int *)(tab_a->content);
	write(1, "pb\n", 3);
	ft_tri_4(tab_a->next);
	write(1, "pa\n", 3);
	if (nb4 == 0)
		write(1, "rra\n", 4);
	if (nb4 == 1)
		write(1, "rra\nsa\n", 7);
	if (nb4 == 2)
		write(1, "pb\nrra\nsa\npa\n", 12);
	if (nb4 == 3)
		write(1, "rra\nrra\nsa\nra\nra\n", 17);
}

int	ft_tri_under_5(t_list *tab_a, int size)
{
	int	numberone;
	int	numbertwo;

	if (size == 2)
		return (0);
	if (size == 3)
	{
		numberone = *(int *)(tab_a->content);
		numbertwo = *(int *)(tab_a->next->content);
		if (numberone > numbertwo)
			write(1, "ra\n", 3);
		return (0);
	}
	if (size == 4)
		ft_tri_3(tab_a);
	if (size == 5)
		ft_tri_4(tab_a);
	if (size == 6)
		ft_tri_5(tab_a);
	return (0);
}
