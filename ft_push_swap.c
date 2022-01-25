/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:08 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/25 13:09:30 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_list		*tab_b;
	int			*tmp;
/*	int			i;
	int			j;

	i = 1;
	j = 0;
	printf("%d\n", argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			printf("%c\n", argv[i][j]);
			j++;
		}
		i++;
	}*/
	if (ft_check(argc, (char **)argv) == -1)
		return (0);
	tmp = ft_index(argc, argv);
	tab_a = ft_list_a(argc, tmp);
	tab_b = ft_list_b();
	ft_setradix(&tab_a, &tab_b, argc);
	printf("HA%d\n", 1);
	return (0);
}

/*
il faut que j'envoie tab_a et tab_b a setradix.
pour ca je dois creer la list b et recuperer la list a
pour creer tab_b je dois
*/
