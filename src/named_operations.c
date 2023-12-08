/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:44 by amagnell          #+#    #+#             */
/*   Updated: 2023/11/28 18:29:20 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *a)
{
	if (ft_swap(a) == 1)
		ft_printf("sa\n");
}

void	swap_b(t_list *b)
{
	if (ft_swap(b) == 1)
		ft_printf("sb\n");
}

void	super_swap(t_list *a, t_list *b)
{
	if (ft_swap(a) == 1 && ft_swap(b) == 1)
		ft_printf("ss\n");
}

void	push_a(t_list *a, t_list *b)
{
	if (b->head)
	{
		ft_push(b, a);
		ft_printf("pa\n");
	}
}

void	push_b(t_list *a, t_list *b)
{
	if (a->head)
	{
		ft_push(a, b);
		ft_printf("pb\n");
	}
}
