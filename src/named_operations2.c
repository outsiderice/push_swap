/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:15 by amagnell          #+#    #+#             */
/*   Updated: 2023/11/28 19:00:28 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list *a)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_list *b)
{
	if (b->head == NULL || b->head->next == NULL)
		return ;
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rev_rotate_a(t_list *a)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_list *b)
{
	if (b->head == NULL || b->head->next == NULL)
		return ;
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}
