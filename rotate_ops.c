/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:21 by keklein           #+#    #+#             */
/*   Updated: 2026/11/13 15:58:25 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate: shift up all elements by one, the first element becomes the last one.

void    ra(t_stack *a)
{
        t_node    *second_a;

        if (!a || a->size < 2)
                return ;
        second_a = a->head->next;
        second_a->prev = NULL;
        a->tail->next = a->head;
        a->head->prev = a->tail;
        a->tail = a->head;
        a->tail->next = NULL;
        a->head = second_a;
        if (a->bench && a->bench->enabled)
        {
                a->bench->ra++;
                a->bench->total_ops++;
        }
        write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
        t_node    *second_b;

        if (!b || b->size < 2)
                return ;
        second_b = b->head->next;
        second_b->prev = NULL;
        b->tail->next = b->head;
        b->head->prev = b->tail;
        b->tail = b->head;
        b->tail->next = NULL;
        b->head = second_b;
        if (b->bench && b->bench->enabled)
	{
		b->bench->rb++;
		b->bench->total_ops++;
	}
        write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
        if (a->bench && a->bench->enabled)
        {
                a->bench->rr++;
                a->bench->total_ops++;
        }
        ra(a);
        rb(b);
}