/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:21 by keklein           #+#    #+#             */
/*   Updated: 2026/08/30 19:24:10 by keklein          ###   ########.fr       */
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
        a->head->next = NULL;
        a->head = second_a;
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
        b->head->next = NULL;
        b->head = second_b;
}

void    rr(t_stack *a, t_stack *b)
{
        ra(a);
        rb(b);
}