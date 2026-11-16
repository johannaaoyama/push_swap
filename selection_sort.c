/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 14:52:48 by keklein           #+#    #+#             */
/*   Updated: 2026/11/16 09:58:12 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//how to know whether to use ra or rra
int	get_position(t_stack *a, int target_index)
{
	t_node	*current;
	int		position;

	position = 0;
	current = a->head;
	while (current)
	{
		if (current->index == target_index)
		{
			return (position);
		}
		position++;
		current = current->next;
	}
	return (0);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	target_index;
	int	position;

	assign_index(a);
	target_index = 0;
	while (a->size > 0)
	{
		position = get_position(a, target_index);
		if (position <= (int)a->size / 2)
			while (a->head->index != target_index)
				ra(a);
		else
			while (a->head->index != target_index)
				rra(a);
		pb(a, b);
		target_index++;
	}
	while (b->size > 0)
		pa(a, b);
}
