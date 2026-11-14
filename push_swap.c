/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:23:04 by jaoyama           #+#    #+#             */
/*   Updated: 2026/11/14 14:17:01 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int argc, char **argv, int *strategy, t_bench *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (is_flag(argv[i], "--simple") == 0)
			*strategy = 1;
		else if (is_flag(argv[i], "--medium") == 0)
			*strategy = 2;
		else if (is_flag(argv[i], "--complex") == 0)
			*strategy = 3;
		else if (is_flag(argv[i], "--adaptive") == 0)
			*strategy = 0;
		if (is_flag(argv[i], "--bench") == 0)
			bench->enabled = 1;
		i++;
	}
	return (i);
}

static void	execute_strategy(t_stack *a, t_stack *b, int strategy, t_bench *bench)
{
	if (strategy == 0)
	{
		bench->strategy_name = "Adaptive";
		// bench->complexity = "O(n sqrt(n))";
		adaptive(a, b, bench);
	}
	else if (strategy == 1)
	{
		bench->strategy_name = "Simple (Selection Sort)";
		bench->complexity = "O(n^2)";
		selection_sort(a, b);
	}
	else if (strategy == 2)
	{
		bench->strategy_name = "Medium (Chunk Sort)";
		bench->complexity = "O(n sqrt(n))";
		chunk_sort(a, b);
	}
	else if (strategy == 3)
	{
		bench->strategy_name = "Complex (Radix Sort)";
		bench->complexity = "O(n log n)";
		radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	int		strategy;
	int		i;

	if (argc < 2)
		return (0);
	init_bench(&bench);
	strategy = 0;
	i = parse_flags(argc, argv, &strategy, &bench);
	stack_init(&b);
	a.bench = &bench;
	b.bench = &bench;
	if (!parse_and_validate(&a, argc - i, &argv[i]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	bench.disorder = compute_disorder(&a);
	if (!is_sorted(&a))
		execute_strategy(&a, &b, strategy, &bench);
	if (bench.enabled)
		print_bench(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}





/* notes on push_swap program logic:

edge case 3-5 elements in stack a

else if (!is_sorted(a))
        {
                if (a->size <= 5)
                        sort_small(a, b);
                else
                        complex_sort(a, b);
        }

// // benchmarks to stderr
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

void    push_swap(t_stack *a)
{
	// 1. If no parameters are specified, the program must not display anything and give the prompt back.
        // 2. parsing & validation:
        // parse_and_validate(); // proceed or return "Error \n"
        if argc == 2
                split string by whitespace, then proceed with "for each element"
        if argc > 2, go through arguments one by one,
                check each -> is it whitespace? -> split // this is to catch the edge case input "1" "4" "-5" "1 2 3" "-42"                        for each element: is it numeric? -> if yes -> atol -> within INT MIN/MAX? -> if yes -> duplicate? -> if no -> into array & proceed with next element
        // -> we have array int *valid_input
        // 3. create doubly linked list from integer array *valid_input
        // -> we have a t_stack *a;
	// after parse_and_validate, checking the disorder is possible: printf("disorder of a is %f\n", compute_disorder(&a));
        // 4. if algo not specified, go adaptive -> decide based on disorder
}
*/
