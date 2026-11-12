#include "push_swap.h"

/*

int     main(void)
{
        int     input[] = {1, 2, 3, 4, -12, -5, 0, -7, 725, 12, 94, -42};
        int     i;
        int     n;
        t_stack   a;
        t_stack   b;
        t_node    *new;

        i = 0;
        n = 12;
        stack_init(&a);
        while(i < n)
        {
                new = new_node(input[i]);
                append_node(&a, new);
                //printf("address of new node: %p\n", new);
                //printf("new node: %d\n", new->value);
                //printf("a head: %d\n", a.head->value);
                //printf("a tail: %d\n", a.tail->value);
                //printf("a size: %zu\n", a.size);
                i++;
        }
	printf("disorder of a is %f\n", compute_disorder(&a));
        sa(&a);
        printf("head after swap a: %d\n", a.head->value);
        //rra(&a);
       // printf("head after r rotate a: %d\n", a.head->value);
        //printf("tail after r rotate a: %d\n", a.tail->value);
        stack_init(&b);
        //new = new_node(8);
        //append_node(&b, new);
        //new = new_node(9);
        //append_node(&b, new);
        //printf("head b: %d\n", b.head->value);
        //printf("tail b: %d\n", b.tail->value);
        //pa(&a, &b);
        //printf("head a after pa: %d\n", a.head->value);
        //printf("size a after pa: %zu\n", a.size);
        //printf("size b after pa: %zu\n", b.size);
		printf("size a before pb: %zu\n", a.size);
        printf("size b before pb: %zu\n", b.size);
        pb(&a, &b);
        //printf("head a after pb: %d\n", a.head->value);
        printf("size a after pb: %zu\n", a.size);
        printf("size b after pb: %zu\n", b.size);
        stack_clear(&a);
        stack_clear(&b);
        return (0);
}
*/
/*
#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	current = stack->head;
	printf("Stack %s (size %zu): ", name, stack->size);
	while (current)
	{
		printf("[%d] -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_stack	a;

	stack_init(&a);

	// Test case: 3, 2, 1 (Worst case scenario)
	append_node(&a, new_node(3));
	append_node(&a, new_node(1));
	append_node(&a, new_node(2));

	printf("--- BEFORE SORT_THREE ---\n");
	print_stack(&a, "A");

	// Run 3-element sorter
	sort_three(&a);

	printf("\n--- AFTER SORT_THREE ---\n");
	print_stack(&a, "A");

	if (is_sorted(&a))
		printf("\nRESULT: SUCCESS! Stack A is sorted.\n");
	else
		printf("\nRESULT: FAILURE! Stack A is not sorted.\n");

	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		strategy;
	// int		bench;
	int		i;

	if (argc < 2)
		return (0);
	strategy = 0; // 0: adaptive, 1: simple, 2: medium, 3: complex
	// bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (is_flag(argv[i], "--simple") == 0)
			strategy = 1;
		else if (is_flag(argv[i], "--medium") == 0)
			strategy = 2;
		else if (is_flag(argv[i], "--complex") == 0)
			strategy = 3;
		// else if (is_flag(argv[i], "--bench") == 0)
		// 	bench = 1;
		i++;
	}

	stack_init(&a);
	stack_init(&b);

	if (!parse_to_stack(argc - (i - 1), &argv[i - 1], &a))
	{
		// free_stacks(&a, &b);
		write(2, "Error\n", 6);
		return (1);
	}

	if (strategy == 1)
		selection_sort(&a, &b);
	else if (strategy == 2)
	{
		//medium 
	}
    else if (strategy == 3)
    {
                //complex
    }
    if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small(&a, &b);
		else if (strategy == 1)
			selection_sort(&a, &b);
		else
			sort_small(&a, &b); 
	}
	stack_clear(&a);
    stack_clear(&b);
	return (0);
}