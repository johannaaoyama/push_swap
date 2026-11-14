/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johannaaoyama <johannaaoyama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:22:02 by jaoyama           #+#    #+#             */
/*   Updated: 2026/11/14 23:01:40 by johannaaoya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// structs node and stack

typedef struct s_node {
        int     value;
        int     index;
        struct s_node *prev;
        struct s_node *next;
} t_node;

typedef struct s_bench {
    int     enabled;
    double  disorder;
    char    *strategy_name;
    char    *complexity;
    int     total_ops;
    int     sa;
    int     sb;
    int     ss;
    int     pa;
    int     pb;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
} t_bench;

typedef struct s_span {
        size_t	lo;
        size_t	mid;
        size_t  hi;
} t_span;

typedef struct s_stack {
        t_node *head;
        t_node *tail;
        size_t  size;
        t_bench *bench;
} t_stack;

// benchmark
void    init_bench(t_bench *bench);
void    print_bench(t_bench *bench);

// dll (doubly linked lists) functions
void    stack_init(t_stack *x);
t_node  *new_node(int v);
void    append_node(t_stack *x, t_node *new);
void    stack_clear(t_stack *x);

// disorder.c
double  compute_disorder(t_stack *a);

// ops (operations) functions

// swap the first two nodes
void    sa(t_stack *a);
void    sb(t_stack *b);

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

// assign_index.c
void    assign_index(t_stack *a);

// helper functions
int     ft_isdigit(int digit);
size_t  ft_strlen(const char *s);
long    ft_atol(const char *str);
long    ft_atol_len(char *str, int len);
void    ft_putnbr_fd(int n, int fd);

// validation
int     is_flag(char *s1, char *s2);
int     is_number(const char *str);
int     has_duplicates(t_stack *a);
int     is_valid_int(const char *str);
int     is_valid_int_len(char *str, int len);

// sorting algorithms
void    chunk_sort(t_stack *a, t_stack *b);
void    adaptive(t_stack *a, t_stack *b, t_bench *bench);
void    radix_sort(t_stack *a, t_stack *b);

// selection_sort.c
int     get_position(t_stack *a, int target_index);
void    selection_sort(t_stack *a, t_stack *b);

// Functions to parse by length
int     parse_and_validate(t_stack *a, int count, char **args);
void    ft_putstr_fd(char *s, int fd);

#endif // PUSH_SWAP_H