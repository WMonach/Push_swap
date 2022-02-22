/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:03:22 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/22 17:11:24 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

void	print_stack(t_list **stack);
void	print_tab(int *tab, int size);
void	ft_push_me(t_list **tab_a, t_list **tab_b, int location, int mod);
void	ft_tri_2(t_list **tab_a);
int		*ft_index(int argc, char **argv);
char	**ft_check(int *size, char **argv);
int		ft_push_b(t_list **tab_a, t_list **tab_b);
int		ft_push_a(t_list **tab_a, t_list **tab_b);
t_list	*ft_list_a(int argc, int *tab);
t_list	*ft_list_b(void);
int		ft_setradix(t_list *tab_a, t_list *tab_b, int argc);
int		ft_rotate_a(t_list **tab_a);
int		ft_rotate_b(t_list **tab_b);
int		ft_swap_a(t_list **tab_a);
int		ft_swap_b(t_list **tab_b);
int		ft_reverserotate_a(t_list **tab_a);
int		ft_reverserotate_b(t_list **tab_b);
int		ft_tri_under_5(t_list *tab_a, t_list *tab_b, int size);
void	print_argv(char **tab, int size);

#endif