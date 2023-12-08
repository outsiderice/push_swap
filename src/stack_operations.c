/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:35:02 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/04 15:56:41 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list *list)
{
	t_node	*past_head;
	t_node	*swap;

	if (list && list->head != list->tail)
	{
		swap = list->head->next;
		past_head = list->head;
		past_head->prev = swap;
		past_head->next = swap->next;
		swap->next = past_head;
		swap->prev = NULL;
		list->head = swap;
		list->head->next = past_head;
		return (1);
	}
	return (0);
}

void	ft_push(t_list *src, t_list *dst)
{
	if (dst->head == NULL)
		new_node(src->head->num, dst, src->head->norm_value);
	else
		add_first(src->head->num, dst, src->head->norm_value);
	del_node(src);
}

void	ft_rotate(t_list *list)
{
	t_node	*new_head;
	t_node	*new_tail;

	new_tail = list->head;
	new_head = list->head->next;
	new_tail->next = NULL;
	new_head->prev = NULL;
	list->head = new_head;
	list->tail->next = new_tail;
	new_tail->prev = list->tail;
	list->tail = new_tail;
}

void	ft_rev_rotate(t_list *list)
{
	t_node	*new_head;
	t_node	*new_tail;

	new_head = list->tail;
	new_tail = list->tail->prev;
	new_head->next = list->head;
	new_head->prev = NULL;
	new_tail->next = NULL;
	list->head = new_head;
	list->tail = new_tail;
}

void	return_to_a(t_list *a, t_list *b)
{
	while (b->head != NULL)
		push_a(a, b);
}
