/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:03:22 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/17 13:36:50 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

/*debug*/

void	print_stack(t_list *stack);
void	print_tab(int *tab, int size);
void	print_argv(char **tab, int size);

/*tri*/

void	ft_push_me(t_list **tab_a, t_list **tab_b, int location, int mod);
void	ft_tri_2(t_list **tab_a);
int		ft_tri_under_5(t_list **tab_a, t_list **tab_b, int size);
int		ft_setradix(t_list **tab_a, t_list *tab_b, int argc);
int		ft_already_sort(int	*index, int size);

/*check*/

char	**ft_check(int *size, char **argv);
long	ft_atoi_long(const char *str);
char	**ft_check_quote(char **argv, int *size);
char	**ft_remove_executable(char **argv, int *size);
int		*ft_count(int **temp, int numbers_count);
int		ft_check_int(int size, char **tab);
int		ft_check_max_min(int size, char **tab);
int		ft_check_duplicate(int size, char **tab);

/*set_up*/

int		*ft_index(int argc, char **argv);
t_list	*ft_list_a(int argc, int *tab);
t_list	*ft_list_b(void);
int		*ft_index(int size, char **tab);

/*operations*/

int		ft_push_b(t_list **tab_a, t_list **tab_b);
int		ft_push_a(t_list **tab_a, t_list **tab_b);
int		ft_rotate_a(t_list **tab_a);
int		ft_rotate_b(t_list **tab_b);
int		ft_swap_a(t_list **tab_a);
int		ft_swap_b(t_list **tab_b);
int		ft_reverserotate_a(t_list **tab_a);
int		ft_reverserotate_b(t_list **tab_b);

/*free*/

void	ft_free_list(t_list *list_a);
void	ft_free_tab(char **tab);
char	**ft_error(char **tab);
int		ft_free_shorcutlist(char **tab, int *tmp, t_list *tab_a);
int		ft_free_shorcut(char **tab, int *tmp);

#endif