#include "push_swap.h"

int     main(void)
{
        int     input[] = {1, 2, 3, 4, 5};
        int     i;
        int     n;
        t_stack   a;
        t_stack   b;
        t_node    *new;

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
        sa(&a);
        printf("head after swap a: %d\n", a.head->value);
        rra(&a);
        printf("head after r rotate a: %d\n", a.head->value);
        printf("tail after r rotate a: %d\n", a.tail->value);
        stack_init(&b);
        new = new_node(8);
        append_node(&b, new);
        new = new_node(9);
        append_node(&b, new);
        printf("head b: %d\n", b.head->value);
        printf("tail b: %d\n", b.tail->value);
        pa(&a, &b);
        printf("head a after pa: %d\n", a.head->value);
        printf("size a after pa: %zu\n", a.size);
        printf("size b after pa: %zu\n", b.size);
        pb(&a, &b);
        printf("head a after pb: %d\n", a.head->value);
        printf("size a after pb: %zu\n", a.size);
        printf("size b after pb: %zu\n", b.size);
        stack_clear(&a);
        stack_clear(&b);
        return (0);
}
