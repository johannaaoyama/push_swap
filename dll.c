/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:15:55 by johannaaoya       #+#    #+#             */
/*   Updated: 2026/11/15 17:59:43 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *x)
{
	x->head = NULL;
	x->tail = NULL;
	x->size = 0;
}

t_node	*new_node(int v)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = v;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// append new node to the tail:

void	append_node(t_stack *x, t_node *new)
{
	if (!x->head)
	{
		x->head = new;
		x->tail = new;
		x->size = 1;
	}
	else
	{
		new->prev = x->tail;
		new->next = NULL;
		x->tail->next = new;
		x->tail = new;
		x->size = (x->size) + 1;
	}
}

// free memory & clear stack

void	stack_clear(t_stack *x)
{
	t_node	*current;
	t_node	*next;

	current = x->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	x->head = NULL;
	x->tail = NULL;
	x->size = 0;
}
