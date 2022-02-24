/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:31:53 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/24 10:43:54 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

/*pour realiser ma liste il faudrait que je fasse une boucle qui cree
une liste pour chaque content et que je fasse avancer ma liste jusqu'a
argc - 1 pour la faire terminer par NULL
pour ce faire je cree ma liste, je cast tab[i] en void
A faire: la liste B avec just list->content == NULL*/