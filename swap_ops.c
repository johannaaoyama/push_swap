/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:25 by keklein           #+#    #+#             */
/*   Updated: 2026/11/13 15:59:21 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first two nodes

void    sa(t_stack *a)
{
        t_node	*second;
        t_node	*temp;

        if (!a || a->size == 1)
                return ;
        second = a->head->next;
        temp = second->next;
        second->prev = NULL;
        second->next = a->head;
	a->head->prev = second;
        a->head->next = temp;
	if (temp)
		temp->prev = a->head;
	else
		a->tail = a->head; // if there are only 2 elements, the tail changes
        a->head = second;
        if (a->bench && a->bench->enabled)
	{
		a->bench->sa++;
		a->bench->total_ops++;
	}
        write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
        t_node	*second;
        t_node	*temp;

        if (!b || b->size == 1)
                return ;
        second = b->head->next;
        temp = second->next;
        second->prev = NULL;
        second->next = b->head;
	b->head->prev = second;
        b->head->next = temp;
	if (temp)
		temp->prev = b->head;
	else
		b->tail = b->head;
        b->head = second;
        if (b->bench && b->bench->enabled)
	{
		b->bench->sb++;
		b->bench->total_ops++;
	}
        write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
        if (a->bench && a->bench->enabled)
	{
		a->bench->ss++;
		a->bench->total_ops++;
	}
        sa(a);
        sb(b);
}