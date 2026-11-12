/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:23:04 by jaoyama           #+#    #+#             */
/*   Updated: 2026/09/02 12:00:01 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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






/* notes on push_swap program logic:

void    push_swap(t_stack *a)
{
	// 1. If no parameters are specified, the program must not display anything and give the prompt back.
        if (argc == 1)
                return ; // give back the prompt

        // 2. parsing & validation:
        // parse_and_validate(); // proceed or return "Error \n"
        if argc == 2
                split string by whitespace, then proceed with "for each element"

        if argc > 2, go through arguments one by one,
                check each -> is it whitespace? -> split // this is to catch the edge case input "1" "4" "-5" "1 2 3" "-42"
                        for each element: is it numeric? -> if yes -> atol -> within INT MIN/MAX? -> if yes -> duplicate? -> if no -> into array & proceed with next element

        // -> we have array int *valid_input

        // 3. create doubly linked list from integer array *valid_input
        // -> we have a t_stack *a;

        // 4. if algo not specified, go adaptive -> decide based on disorder
        {
                disorder = calc_disorder(a);
                if (--simple == true || (disorder < 0.2 && --medium == false && --complex == false))
                        simple(a);
                        // return: ft_printf(ops) and send benchmarks to stderr; or Error
                        // benchmarks to stderr
                        int i = 0;
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
                        medium(a);
                if (--complex == true || disorder >= 0.5)
                        complex(a);
        }
}
*/
