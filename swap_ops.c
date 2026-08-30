/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:25 by keklein           #+#    #+#             */
/*   Updated: 2026/08/30 19:19:30 by keklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first two nodes

void    sa(t_stack *a)
{
        t_node	*second;
        t_node	*temp;

        if (a->size == 0 || a->size == 1)
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
}

void    sb(t_stack *b)
{
        t_node	*second;
        t_node	*temp;

        if (b->size == 0 || b->size == 1)
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
}

void    ss(t_stack *a, t_stack *b)
{
        sa(a);
        sb(b);
}