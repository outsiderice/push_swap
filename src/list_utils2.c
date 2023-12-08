/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:33:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/01 20:15:12 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *list)
{
	while (list->head != NULL)
	{
		del_node(list);
	}
}

void	free_stacks(t_list *a, t_list *b)
{
	free_stack(a);
	free_stack(b);
}
