/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:22:18 by jaoyama           #+#    #+#             */
/*   Updated: 2026/08/30 13:18:41 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first two nodes

void    sa(t_stack *a)
{
        t_node    *second;
        void    *temp;

        if (a->size == 0 || a->size == 1)
                return ;
        second = a->head->next;
        temp = second->next;
        second->prev = NULL;
        second->next = a->head;
        a->head = second;
        a->head->next = temp;
}

void    sb(t_stack *b)
{
        t_node    *second;
        void    *temp;

        if (b->size == 0 || b->size == 1)
                return ;
        second = b->head->next;
        temp = second->next;
        second->prev = NULL;
        second->next = b->head;
        b->head = second;
        b->head->next = temp;
}

void    swap(t_stack *a, t_stack *b)
{
        sa(a);
        sb(b);
}

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
        a->head->next = NULL;
        a->tail = a->head;
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
        b->head->next = NULL;
        b->tail = b->head;
        b->head = second_b;
}

void    rr(t_stack *a, t_stack *b)
{
        ra(a);
        rb(b);
}

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
}

void    rrr(t_stack *a, t_stack *b)
{
        rra(a);
        rrb(b);
}

