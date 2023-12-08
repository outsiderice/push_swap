/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:48:27 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/06 18:59:45 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *a, t_list *b)
{
	if (a->head->norm_value == 3)
		rotate_a(a);
	if (a->head->norm_value == 2)
	{
		if (a->tail->norm_value == 3)
			swap_a(a);
		else
			rev_rotate_a(a);
	}
	ordered_check(a, b);
	rev_rotate_a(a);
	swap_a(a);
	ordered_check(a, b);
}

void	sort_last_three(t_list *a)
{
	int	x;
	int	y;
	int	z;

	z = a->count;
	y = z - 1;
	x = y - 1;
	if (a->head->norm_value == z)
		rotate_a(a);
	if (a->head->norm_value == y)
	{
		if (a->tail->norm_value == z)
			swap_a(a);
		else
			rev_rotate_a(a);
	}
	if (a->head->norm_value == x && a->tail->norm_value == y)
	{
		rev_rotate_a(a);
		swap_a(a);
	}
}

void	sort_four(t_list *a, t_list *b)
{
	int	b_count;

	b_count = 0;
	while (b_count != 1)
	{
		if (a->head->norm_value == 1)
		{
			push_b(a, b);
			b_count++;
		}
		else
			rotate_a(a);
	}
	sort_last_three(a);
	push_a(a, b);
	ordered_check(a, b);
}

void	sort_five(t_list *a, t_list *b)
{
	int	b_count;

	b_count = 0;
	while (b_count != 2)
	{
		if (a->head->norm_value == 1 || a->head->norm_value == 2)
		{
			push_b(a, b);
			b_count++;
		}
		else
		{
			rotate_a(a);
		}
	}
	if (b->head->norm_value == 1)
		swap_b(b);
	sort_last_three(a);
	push_a(a, b);
	push_a(a, b);
	ordered_check(a, b);
}

// void print_stack(t_list *a)
// {
// 	t_node *current;

// 	current = a->head;
// 	ft_printf("STACK A ES:\n");
// 	while(current)
// 	{
// 		ft_printf("%d\n", current->norm_value);
// 		current = current->next;
// 	}
// }

void	radixcal(t_list *a, t_list *b)
{
	int	i;
	int	node_count;

	i = 1;
	while (ordered_check(a, b) == 1)
	{
		node_count = 0;
		while (node_count < a->count)
		{
			if (a->head)
			{
				if ((a->head->norm_value & i) == 0)
					push_b(a, b);
				else
					rotate_a(a);
				node_count++;
			}
		}
		return_to_a(a, b);
		i = i << 1;
	}
}
