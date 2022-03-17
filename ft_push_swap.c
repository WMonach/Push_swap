/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:08 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/17 14:02:18 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_check_index(int *size, char **argv, int *tmp, char ***tab)
{
	*tab = ft_check(size, argv);
	if (tab == NULL)
		return (NULL);
	tmp = ft_index(*size, *tab);
	if (*size == 2)
	{
		ft_free_shorcut(*tab, tmp);
		return (NULL);
	}
	if (ft_already_sort(tmp, *size) == 1 || tmp == NULL)
	{
		ft_free_shorcut(*tab, tmp);
		return (NULL);
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_list		*tab_b;
	int			*tmp;
	char		**tab;
	int			size;

	size = argc;
	tmp = NULL;
	tmp = ft_check_index(&size, argv, tmp, &tab);
	if (tmp == NULL)
		return (0);
	tab_a = ft_list_a(size, tmp);
	tab_b = ft_list_b();
	if (tab_a == NULL)
		return (ft_free_shorcut(tab, tmp));
	if (size < 6)
	{
		ft_tri_under_5(&tab_a, &tab_b, size);
		ft_free_shorcutlist(tab, tmp, tab_a);
		return (0);
	}
	ft_setradix(&tab_a, tab_b, size);
	ft_free_shorcutlist(tab, tmp, tab_a);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_list		*tab_a;
// 	t_list		*tab_b;
// 	int			*tmp;
// 	char		**tab;
// 	int			size;

// 	size = argc;
// 	tab = ft_check(&size, argv);
// 	if (tab == NULL)
// 		return (-1);
// 	tmp = ft_index(size, tab);
// 	if (size == 2)
// 	{
// 		ft_free_tab(tab);
// 		free(tmp);
// 		return (-1);
// 	}
// 	if (ft_already_sort(tmp, size) == 1 || tmp == NULL)
// 	{
// 		ft_free_tab(tab);
// 		free(tmp);
// 		return (-1);
// 	}
// 	tab_a = ft_list_a(size, tmp);
// 	tab_b = ft_list_b();
// 	if (tab_a == NULL)
// 	{
// 		ft_free_tab(tab);
// 		free(tmp);
// 		return (-1);
// 	}
// 	if (size < 6)
// 	{
// 		ft_tri_under_5(&tab_a, &tab_b, size);
// 		ft_free_tab(tab);
// 		free(tmp);
// 		ft_free_list(tab_a);
// 		return (0);
// 	}
// 	ft_setradix(tab_a, tab_b, size);
// 	ft_free_tab(tab);
// 	free(tmp);
// 	ft_free_list(tab_a);
// 	return (0);
// }
