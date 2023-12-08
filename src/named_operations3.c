/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:45:43 by amagnell          #+#    #+#             */
/*   Updated: 2023/11/28 19:03:55 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rad_rotate(t_list *a, t_list *b)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	if (b->head == NULL || b->head->next == NULL)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

void	rad_rev_rotate(t_list *a, t_list *b)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	if (b->head == NULL || b->head->next == NULL)
		return ;
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
