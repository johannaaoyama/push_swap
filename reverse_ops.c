/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:18 by keklein           #+#    #+#             */
/*   Updated: 2026/08/31 08:39:16 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate: shift down all elements by one. last element becomes the first one.

void    rra(t_stack *a)
{
        t_node    *secondlast_a;

        if (!a || a->size < 2)
                return ;
        secondlast_a = a->tail->prev;
        secondlast_a->next = NULL;
        a->tail->next = a->head;
        a->head->prev = a->tail;
        a->tail->prev = NULL;
        a->head = a->tail;
        a->tail = secondlast_a;
        write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
        t_node    *secondlast_b;

        if (!b || b->size < 2)
                return ;
        secondlast_b = b->tail->prev;
        secondlast_b->next = NULL;
        b->tail->next = b->head;
        b->head->prev = b->tail;
        b->tail->prev = NULL;
        b->head = b->tail;
        b->tail = secondlast_b;
        write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
        rra(a);
        rrb(b);
        write(1, "rrr\n", 4);
}