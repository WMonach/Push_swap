/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:44:23 by will              #+#    #+#             */
/*   Updated: 2022/02/01 16:26:30 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head != NULL)
	{
		printf("stack=%d\n", *(int *)(head->content));
		head = head->next;
	}
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab=%d\n", tab[i]);
		i++;
	}
}
