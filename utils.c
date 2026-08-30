/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 14:52:48 by keklein           #+#    #+#             */
/*   Updated: 2026/08/30 16:53:11 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_node    	*current_node;
	t_node    	*next_node;
	int			i;

	if (!a || !a->head)
		return ;
	current_node = a->head;
	while (current_node)
	{
		i = 0;
		next_node = a->head;
		while(next_node)
		{
			if (current_node->value > next_node->value)
				i++;
			next_node = next_node->next;
		}
		current_node->index = i;
		current_node = current_node->next;
	}
}

int		is_sorted(t_stack *a)
{
	t_node *current;

	if (!a || !a->head)
		return (1);
	current = a->head;
	while (current->next)
	{
		if (current->value > current->next->value)
		return (0);
		current = current->next;
	}
	return (1);
}

//how to know whether to use ra or rra
int		get_position(t_stack *a, int target_index)
{
	t_node	*current;
	int		position;

	position = 0;
	current = a->head;
	while (current)
	{
		if (current->index == target_index)
		{
			return position;
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

	target_index = 0;
	while (a->size > 0)
	{
		position = get_position(a, target_index);
		// Step 1: Bring element to top based on pos
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