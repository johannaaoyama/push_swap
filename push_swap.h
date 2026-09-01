/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:22:02 by jaoyama           #+#    #+#             */
/*   Updated: 2026/09/01 15:06:00 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
        size_t  size;
	int	hi;
	int	lo;
} t_stack;

// dll (doubly linked lists) functions

void    stack_init(t_stack *x);
t_node    *new_node(int v);
void    append_node(t_stack *x, t_node *new);
void    stack_clear(t_stack *x);
double     compute_disorder(t_stack *a);

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

//utils.c
void	assign_index(t_stack *a);
int	get_position(t_stack *a, int target_index);
int	is_sorted(t_stack *a);
void	selection_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);

//disorder calculation
double	compute_disorder(t_stack *a);

//helper functions
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isdigit(int digit);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);

//validation
int	is_flag(char *s1, char *s2);
int     is_number(const char *str);
int     has_duplicates(t_stack *a);
int	is_valid_int(const char *str);
int	parse_to_stack(int argc, char **argv, t_stack *a);
// sort_small
int	get_min_position(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

#endif // PUSH_SWAP_H
