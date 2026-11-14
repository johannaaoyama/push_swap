/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:21 by keklein           #+#    #+#             */
/*   Updated: 2026/11/14 13:49:50 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	second = s->head->next;
	second->prev = NULL;
	s->tail->next = s->head;
	s->head->prev = s->tail;
	s->tail = s->head;
	s->tail->next = NULL;
	s->head = second;
}

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_stack(a);
	if (a->bench && a->bench->enabled)
	{
		a->bench->ra++;
		a->bench->total_ops++;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_stack(b);
	if (b->bench && b->bench->enabled)
	{
		b->bench->rb++;
		b->bench->total_ops++;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (a && a->bench && a->bench->enabled)
	{
		a->bench->rr++;
		a->bench->total_ops++;
	}
	write(1, "rr\n", 3);
}
