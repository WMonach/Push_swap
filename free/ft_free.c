/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:30:02 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 10:35:47 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free((tab)[i]);
		i++;
	}
	free(tab);
}

void	ft_free_list(t_list *list_a)
{
	t_list	*tempi;
	t_list	*temple;

	if (!(list_a))
		return ;
	tempi = list_a;
	temple = list_a;
	while (tempi)
	{
		temple = temple->next;
		free(tempi);
		tempi = temple;
	}
	free(tempi);
	list_a = NULL;
}

int	ft_free_shorcut(char **tab, int *tmp)
{
	ft_free_tab(tab);
	free(tmp);
	return (-1);
}

int	ft_free_shorcutlist(char **tab, int *tmp, t_list *tab_a)
{
	ft_free_tab(tab);
	free(tmp);
	ft_free_list(tab_a);
	return (0);
}
