/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:54 by amagnell          #+#    #+#             */
/*   Updated: 2023/12/07 17:50:28 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	while (arg[i] >= '0' && arg[i] <= '9' && arg[i])
		i++;
	if (i != len || ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	return ;
}

int	is_dup(t_list *a, t_node *current, int number)
{
	t_node	*to_compare;

	to_compare = a->head;
	while (to_compare != NULL)
	{
		if (to_compare != current && to_compare->num == number)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			exit (EXIT_FAILURE);
		}
		to_compare = to_compare->next;
	}
	return (0);
}
