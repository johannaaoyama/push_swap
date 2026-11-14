/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:18 by keklein           #+#    #+#             */
/*   Updated: 2026/11/14 13:50:29 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack *s)
{
	t_node	*secondlast;

	if (!s || s->size < 2)
		return ;
	secondlast = s->tail->prev;
	secondlast->next = NULL;
	s->tail->next = s->head;
	s->head->prev = s->tail;
	s->tail->prev = NULL;
	s->head = s->tail;
	s->tail = secondlast;
}

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rev_rotate_stack(a);
	if (a->bench && a->bench->enabled)
	{
		a->bench->rra++;
		a->bench->total_ops++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rev_rotate_stack(b);
	if (b->bench && b->bench->enabled)
	{
		b->bench->rrb++;
		b->bench->total_ops++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	if (a && a->bench && a->bench->enabled)
	{
		a->bench->rrr++;
		a->bench->total_ops++;
	}
	write(1, "rrr\n", 4);
}
