/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoyama <jaoyama@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:22:02 by jaoyama           #+#    #+#             */
/*   Updated: 2026/08/25 18:22:12 by jaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

// structs node and stack

typedef struct s_node {
        int     value;
        int     index;
        struct s_node *prev;
        struct s_node *next;
} t_node;

typedef struct s_stack {
        t_node *head;
        t_node *tail;
        size_t  size; // no. of elements of the list
} t_stack;

// dll (doubly linked lists) functions

void    stack_init(t_stack *x);
t_node    *new_node(int v);
void    append_node(t_stack *x, t_node *new);
void    stack_clear(t_stack *x);

// ops (operations) functions

// swap the first two nodes

void    sa(t_stack *a);
void    sb(t_stack *b);
void    swap(t_stack *a, t_stack *b);

// push element at top of b & put it at the top of a, do nothing if b is empty. and vice versa.

void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

// rotate: shift up all elements by one, the first element becomes the last one.

void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);

// reverse rotate: shift down all elements by one. last element becomes the first one.

void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif // PUSH_SWAP_H
