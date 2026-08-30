/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keklein <keklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:59:25 by keklein           #+#    #+#             */
/*   Updated: 2026/08/30 18:01:49 by keklein          ###   ########.fr       */
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

void    ss(t_stack *a, t_stack *b)
{
        sa(a);
        sb(b);
}