/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:01:12 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/07 17:52:29 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_numbers(t_list *a, int new_value)
{
	t_node	*current;
	t_node	*to_norm;

	to_norm = a->head;
	while (to_norm != NULL)
	{
		if (to_norm->norm_value == 0 && is_dup(a, to_norm, to_norm->num) == 0)
		{
			current = a->head;
			new_value = 0;
			while (current != NULL)
			{
				if (to_norm->num > current->num)
					new_value++;
				if (current == a->tail)
				{
					to_norm->norm_value = new_value + 1;
				}
				current = current->next;
			}
		}
		to_norm = to_norm->next;
	}
}

int	ordered_check(t_list *a, t_list *b)
{
	int		i;
	t_node	*current;

	current = a->head;
	i = 1;
	while (current->norm_value == i && i <= a->count && current != NULL)
	{
		i++;
		if (current->next != NULL)
			current = current->next;
	}
	if (i == a->count + 1)
	{
		free_stacks(a, b);
		exit (EXIT_SUCCESS);
	}
	return (1);
}

void	sorting(t_list *a, t_list *b)
{
	if (a->count == 2)
		swap_a(a);
	if (a->count == 3)
		sort_three(a, b);
	if (a->count == 4)
	{
		sort_four(a, b);
	}
	if (a->count == 5)
		sort_five(a, b);
	if (a->count > 5)
		radixcal(a, b);
}

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;
	int		i;

	i = 0;
	while (argv[++i] != NULL)
	{
		ft_check_args(argv[i]);
	}
	if (argc < 3)
		return (0);
	initialize_list(&a, argc);
	initialize_list(&b, argc);
	i = 0;
	while (argv[++i])
	{
		new_node(ft_atoi(argv[i]), &a, 0);
	}
	normalize_numbers(&a, 0);
	ordered_check(&a, &b);
	sorting(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
