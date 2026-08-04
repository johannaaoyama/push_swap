#include "push_swap.h"

// doubly linked lists:
struct representing the numbers
{
prev:
next:
index:
value:
}

struct representing the stack
{
top:
bottom:
size: // no. of elements of the list a
}

void	push_swap(t_struct list_a)
{

	// 1. If no parameters are specified, the program must not display anything and give the prompt back.
	// 2. check if list_a is valid -> proceed with function below; else return (1);
	validate_a(list_a); // proceed or return "Error \n"
	
	// 3. if algo not specified, go adaptive -> decide based on disorder
	{
		disorder = calc_disorder(list_a);
		if (--simple == true || (disorder < 0.2 && --medium == false && --complex == false))
			simple(list_a);
			// return: ft_printf(ops) and send benchmarks to stderr; or Error
			// benchmarks to stderr
			int i == 0;
			while (i <= 4)
				write(2, arr[i], ft_strlen(arr[i]));
				write(2, "\n", 1);
 
			// benchmark output array
			a = ft_printf("Disorder: %d", disorder);
			"name" "complexity class"
			total # of ops: ops_count(a)
			operation types count: type_count(a)

			// if (--bench == true)
				ft_printf(stderr);
		if (––medium == true || (disorder < 0.5 && disorder >= 0.2))
			medium(list_a);
		if (--complex == true || disorder >= 0.5)
			complex(list_a);
	}

void	simple(a)
{
	// print the ops separated by \n, use write or rather ft_printf here?
	write(1, ops, sizeof(ops));
}
