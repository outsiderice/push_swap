/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:49:09 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/08 21:21:28 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				num;
	int				norm_value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	int						count;
	struct s_node			*head;
	struct s_node			*tail;
}							t_list;

/*	PUSH_SWAP	*/
void	normalize_numbers(t_list *a, int new_value);
int		ordered_check(t_list *a, t_list *b);
void	sorting(t_list *a, t_list *b);

/*	SORTING UTILS	*/
void	sort_three(t_list *a, t_list *b);
void	sort_last_three(t_list *a);
void	sort_four(t_list *a, t_list *b);
void	sort_five(t_list *a, t_list *b);
void	radixcal(t_list *a, t_list *b);

/*	LIST_UTILS	*/
void	initialize_list(t_list *list, int argc);
t_node	*new_node(int num, t_list *list, int norm_value);
t_node	*add_first(int num, t_list *list, int norm_value);
void	del_node(t_list *list);
void	free_stacks(t_list *a, t_list *b);
void	free_stack(t_list *list);

/*	PARSING_UTILS	*/
void	ft_check_args(char *arg);
int		is_dup(t_list *a, t_node *current, int number);

/*	STACK_OPERATIONS	*/
int		ft_swap(t_list *list);
void	ft_push(t_list *src, t_list *dst);
void	ft_rotate(t_list *list);
void	ft_rev_rotate(t_list *list);
void	return_to_a(t_list *a, t_list *b);

/*	NAMED_OPERATIONS	*/
void	swap_a(t_list *a);
void	swap_b(t_list *b);
void	super_swap(t_list *a, t_list *b);
void	push_a(t_list *a, t_list *b);
void	push_b(t_list *a, t_list *b);
void	rotate_a(t_list *a);
void	rotate_b(t_list *b);
void	rev_rotate_a(t_list *a);
void	rev_rotate_b(t_list *b);
void	rad_rotate(t_list *a, t_list *b);
void	rad_rev_rotate(t_list *a, t_list *b);
#endif
