#include <stdio.h>
#include <stdlib.h>

// tiny ops functiions to manipulate 2 doubly linked lists a and b

// struct representing the numbers

typedef struct Node {
	int	value;
	int	index;
	struct Node *prev;
	struct Node *next;
} Node;

// struct representing the stack

typedef struct stack {
	Node *head;
	Node *tail;
	size_t	size; // no. of elements of the list
} stack;


// initiate stack, initiate Node, populate the Node with integers given as input and append nodes to the stack

void	stack_init(stack *x)
{
	//stack *x = malloc(sizeof(stack));
	//if (!x)	
	//	return (NULL);
	x->head = NULL;
	x->tail = NULL;
	x->size = 0;
	//return (x);
}

Node	*new_node(int v)
{
	Node 	*node;

	node = (Node *)malloc(sizeof(Node));
	if (!node)
		return (0);
	node->value = v;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// append new node to the tail:
 
void	append_node(stack *a, Node *new)
{
	if (!a->head)
	{
		a->head = new;
		a->tail = new;
		a->size = 1; // replace this with a function for calculating list size 
	}
	else
	{
		new->prev = a->tail;
		new->next = NULL; 
		a->tail->next = new;
		a->tail = new;
		a->size = (a->size) + 1;
	}
}

void	stack_clear(stack *x)
{
	Node *current;
	Node *next;

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

// operations functions

// swap the first two nodes

void	sa(stack *a)
{
	Node	*second;
	void	*temp;

	if (a->size == 0 || a->size == 1)
		return ;
	second = a->head->next;
	temp = second->next;
	second->prev = NULL;
	second->next = a->head;
	a->head = second;
	a->head->next = temp;
}

void	sb(stack *b)
{
	Node	*second;
	void	*temp;

	if (b->size == 0 || b->size == 1)
                return ;
        second = b->head->next;
        temp = second->next;
        second->prev = NULL;
        second->next = b->head;
        b->head = second;
        b->head->next = temp;
}

void	swap(stack *a, stack *b)
{
	sa(a);
	sb(b);
}

// push element at top of b & put it at the top of a, do nothing if b is empty. and vice versa.

void	pa(stack *a, stack *b)
{
	Node	*second_b;

	if (!b)
		return ;
	second_b = b->head->next;
	a->head->prev = b->head;
	b->head->next = a->head;
	second_b->prev = NULL;
	b->size = b->size - 1;
	a->size = a->size + 1;
}

void    pb(stack *a, stack *b)
{       
        Node    *second_a;

        if (!a)
                return ;
        second_a = a->head->next;
        b->head->prev = a->head;
        a->head->next = b->head;
        second_a->prev = NULL;
	a->size = a->size - 1;
	b->size = b->size + 1;
}

// rotate: shift up all elements by one, the first element becomes the last one.

void	ra(stack *a)
{
	Node	*second_a;

	if (!a)
		return ;
	second_a = a->head->next;
	second_a->prev = NULL;
	a->head->next = NULL;
	a->head = a->tail;
	a->tail->next = a->head;
}

void    rb(stack *b)
{
        Node    *second_b;

        if (!b)
                return ;
        second_b = b->head->next;
        second_b->prev = NULL;
        b->head->next = NULL;
        b->head = b->tail;
        b->tail->next = b->head;
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}

// reverse rotate: shift down all elements by one. last element becomes the first one.

void	rra(stack *a)
{
        Node    *secondlast_a;

        if (!a)
                return ;
        secondlast_a = a->tail->prev;
        secondlast_a->next = NULL;
	a->tail->prev = NULL;
        a->tail->next = a->head;
        a->head->prev = a->tail;
}

void    rrb(stack *b)
{
        Node    *secondlast_b;

        if (!b)
                return ;
        secondlast_b = b->tail->prev;
        secondlast_b->next = NULL;
        b->tail->prev = NULL;
        b->tail->next = b->head;
        b->head->prev = b->tail;
}

void    rrr(stack *a, stack *b)
{
        rra(a);
        rrb(b);
}

int	main(void)
{
	int	input[] = {1, 2, 3, 4, 5};
	int	i;
	int	n;
	stack	a;
	stack	b;
	Node	*new;

	i = 0;
	n = 5;
	stack_init(&a);
	while(i < n)
	{
		new = new_node(input[i]);
		append_node(&a, new);
		printf("address of new node: %p\n", new);
		//printf("new node: %d\n", new->value);
		printf("a head: %d\n", a.head->value);
		printf("a tail: %d\n", a.tail->value);
		printf("a size: %zu\n", a.size);
		i++; 
	}
	/*sa(a);
	printf("head after swap a: %d\n", a->head->value);
	ra(a);
	printf("head after rotate a: %d\n", a->head->value);*/
	stack_init(&b);
	new = new_node(8);
	append_node(&b, new);
	new = new_node(9);
	append_node(&b, new);
	printf("head b: %d\n", b.head->value);
	printf("tail b: %d\n", b.tail->value);
	stack_clear(&a);
	return (0);
}
