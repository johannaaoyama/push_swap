/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:25 by keklein           #+#    #+#             */
/*   Updated: 2026/11/18 13:31:31 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_node	*second;
	t_node	*temp;

	if (!s || s->size < 2)
		return ;
	second = s->head->next;
	temp = second->next;
	second->prev = NULL;
	second->next = s->head;
	s->head->prev = second;
	s->head->next = temp;
	if (temp)
		temp->prev = s->head;
	else
		s->tail = s->head;
	s->head = second;
}

void	sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	swap_stack(a);
	if (a->bench && a->bench->enabled)
	{
		a->bench->sa++;
		a->bench->total_ops++;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	swap_stack(b);
	if (b->bench && b->bench->enabled)
	{
		b->bench->sb++;
		b->bench->total_ops++;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	swap_stack(a);
	swap_stack(b);
	if (a && a->bench && a->bench->enabled)
	{
		a->bench->ss++;
		a->bench->total_ops++;
	}
	write(1, "ss\n", 3);
}
