/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:29:40 by kevin             #+#    #+#             */
/*   Updated: 2026/09/01 13:59:04 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_stack *a)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = a->head;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_position;

	min_position = get_min_position(a);
	if (min_position <= (int)a->size / 2)
	{
		while (min_position-- > 0)
			ra(a);
	}
	else
	{
		while (min_position++ < (int)a->size)
			rra(a);
	}
	pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}