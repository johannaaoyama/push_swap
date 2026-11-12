#include "push_swap.h"

void	adaptive(t_stack *a, t_stack *b)
        {
                if (compute_disorder(a) < 0.2)
		{
			printf("selected simple\n");
               		selection_sort(a, b); 
		}
		else if (compute_disorder(a) < 0.5)
		{
			printf("selected medium\n");
                      	chunk_sort(a, b);
		}
                else if (compute_disorder(a) >= 0.5)
                {
			printf("selected complex\n");
		        chunk_sort(a, b); // change this to complex
        	}
	}
