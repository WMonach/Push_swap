/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:08 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/01 16:56:40 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_list		*tab_b;
	int			*tmp;
	char		**tab;

	printf("argc=%d\n", argc);
	tab = ft_check(&argc, argv);
	printf("argc=\n");
	if (tab == NULL)
		return (0);
	tmp = ft_index(argc, tab);
	if (ft_already_sort(tmp, argc) == 1)
		return (0);
	tab_a = ft_list_a(argc, tmp);
	tab_b = ft_list_b();
	argc = ft_lstsize(tab_a);
	if (argc < 6)
	{
		ft_tri_under_5(tab_a, tab_b, argc);
		return (0);
	}
	ft_setradix(tab_a, tab_b, argc);
	return (0);
}

/*
il faut que j'envoie tab_a et tab_b a setradix.
pour ca je dois creer la list b et recuperer la list a
pour creer tab_b je dois//
*/
