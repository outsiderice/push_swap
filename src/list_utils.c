/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:55 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/07 17:47:41 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_list(t_list *list, int argc)
{
	list->count = argc - 1;
	list->head = NULL;
	list->tail = NULL;
}

t_node	*new_node(int num, t_list *list, int norm_value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node) * 1);
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->num = num;
	new_node->norm_value = norm_value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		new_node->prev = list->tail;
		list->tail->next = new_node;
		list->tail = new_node;
	}
	return (new_node);
}

t_node	*add_first(int num, t_list *list, int norm_value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node) * 1);
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->num = num;
	new_node->norm_value = norm_value;
	new_node->next = list->head;
	new_node->prev = NULL;
	list->head->prev = new_node;
	list->head = new_node;
	return (new_node);
}

void	del_node(t_list *list)
{
	t_node	*to_del;

	to_del = list->head;
	if (to_del == NULL)
		return ;
	list->head = to_del->next;
	if (list->head != NULL)
		list->head->prev = NULL;
	free(to_del);
}
