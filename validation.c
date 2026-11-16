/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:25:07 by kevin             #+#    #+#             */
/*   Updated: 2026/11/16 16:55:54 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	has_duplicates(t_stack *a)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = a->head;
	while (current_node)
	{
		next_node = current_node->next;
		while (next_node)
		{
			if (current_node->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}

int	is_valid_int_len(char *str, int len)
{
	int	i;

	i = 0;
	if (len <= 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == len)
		return (0);
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->adaptive = 0;
	bench->strategy = 0;
	bench->disorder = 0.0;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}
