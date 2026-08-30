/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:28 by keklein           #+#    #+#             */
/*   Updated: 2026/08/30 18:00:37 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// push element at top of b & put it at the top of a, do nothing if b is empty. and vice versa.

void    pa(t_stack *a, t_stack *b)
{
        t_node    *second_b;

        if (!a || !b || !b->head || b->size == 0)
            return ;
        second_b = b->head->next;
		if(a->head)
			a->head->prev = b->head;
		else
			a->tail = b->head;
		b->head->next = a->head;
        a->head = b->head;
		if(second_b)
			second_b->prev = NULL;
		else
			b->tail = NULL;
        b->head = second_b;
        b->size--;
        a->size++;
		
}

void    pb(t_stack *a, t_stack *b)
{
        t_node    *second_a;

        if (!b || !a || !a->head || a->size == 0)
            return ;
		second_a = a->head->next;
        if (b->head)
			b->head->prev = a->head;
		else
			b->tail = a->head;
		a->head->next = b->head;
        b->head = a->head;
		if(second_a)
        	second_a->prev = NULL;
		else
			a->tail = NULL;      
        a->head = second_a;
		a->size--;
        b->size++;
}