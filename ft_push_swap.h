/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:03:22 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/21 15:35:46 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

int		*ft_index(int argc, char **argv);
int		ft_check(int argc, char **argv);
int		ft_push_b(t_list **tab_a, t_list **tab_b);
int		ft_push_a(t_list **tab_a, t_list **tab_b);
t_list	*ft_list_a(int argc, char **tab);
t_list	*ft_list_b(void);
int		ft_setradix(t_list **tab_a, t_list **tab_b, int argc);
int		ft_rotate_a(t_list **tab_a);
int		ft_rotate_b(t_list **tab_b);
int		ft_swap_a(t_list **tab_a);
int		ft_swap_b(t_list **tab_b);
int		ft_reverserotate_a(t_list **tab_a);
int		ft_reverserotate_b(t_list **tab_b);

#endif