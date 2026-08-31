/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:25 by keklein           #+#    #+#             */
/*   Updated: 2026/08/31 08:36:55 by kevin            ###   ########.fr       */
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
        write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
        sa(a);
        sb(b);
        write(1, "ss\n", 3);
}