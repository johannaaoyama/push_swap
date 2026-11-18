/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 08:55:28 by kevin             #+#    #+#             */
/*   Updated: 2026/11/18 11:53:27 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	pairs;
	t_node	*cur;
	t_node	*nxt;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	pairs = 0;
	cur = a->head;
	while (cur)
	{
		nxt = cur->next;
		while (nxt)
		{
			pairs++;
			if (cur->value > nxt->value)
				mistakes++;
			nxt = nxt->next;
		}
		cur = cur->next;
	}
	return ((double)mistakes / (double)pairs);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

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
