#include "push_swap.h"

// initiate stack, initiate & allocate memory for node, populate nodes with integers given as input, append nodes to the stack, then free memory that was allocated for nodes to clear the stack

void    stack_init(t_stack *x)
{
        x->head = NULL;
        x->tail = NULL;
        x->size = 0;
	x->hi = 0;
	x->lo = 0;
}

t_node    *new_node(int v)
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

void    append_node(t_stack *x, t_node *new)
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
	if (new->value < x->lo)
		x->lo = new->value;
	if (new->value > x->hi)
		x->hi = new->value;
}

// free memory & clear stack

void    stack_clear(t_stack *x)
{
        t_node *current;
        t_node *next;

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
	x->hi = 0;
	x->lo = 0;
}

// compute disorder

double	compute_disorder(t_stack *x)
{
	int	mistakes;
	int	pairs;
	t_node	*cur;
	t_node	*nxt;

	if (!x || !x->head || !x->tail) 
		return (0);
	mistakes = 0;
	pairs = 0;
	cur = x->head;
	nxt = x->head->next;
	while(nxt != NULL)
	{
		if (cur->value > nxt->value)
			mistakes++;
		pairs++;
                printf("cur val: %d\n", cur->value);
                printf("next val: %d\n", nxt->value);
                printf("pairs: %d\n", pairs);
                printf("mistakes: %d\n", mistakes);
		cur = cur->next;
		nxt = nxt->next;
	}
	return ((double)mistakes / (double)pairs);
}
