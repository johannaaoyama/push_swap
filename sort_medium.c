/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:01:14 by kevin             #+#    #+#             */
/*   Updated: 2026/11/12 12:03:05 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_position(t_stack *b)
{
	t_node	*current;
	int		max_val;
	int		max_pos;
	int		i;

	current = b->head;
	max_val = current->value;
	max_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;
	int	max_pos;

	assign_index(a);
	chunk_size = 15;
	i = 0;
	while (a->size > 0)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->head->index <= i + chunk_size)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
	while (b->size > 0)
	{
		max_pos = get_max_position(b);
		if (max_pos <= (int)b->size / 2)
			while (b->head != get_node_at(b, max_pos))
				rb(b);
		else
			while (b->head != get_node_at(b, max_pos))
				rrb(b);
		pa(a, b);
	}
}