/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:23:04 by jaoyama           #+#    #+#             */
/*   Updated: 2026/11/16 16:42:59 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strategy(t_bench *bench, int flag)
{
	bench->adaptive = (flag == 0);
	bench->strategy = flag;
	if (flag == 0)
		bench->strategy = pick_strategy(bench->disorder);
}

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
		else if (is_flag(argv[i], "--bench") == 0)
			bench->enabled = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}

static void	execute_strategy(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->strategy == 1)
		selection_sort(a, b);
	else if (bench->strategy == 2)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
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
	if (i < 0 || !parse_and_validate(&a, argc - i, &argv[i]))
		return (write(2, "Error\n", 6), 1);
	bench.disorder = compute_disorder(&a);
	set_strategy(&bench, strategy);
	if (!is_sorted(&a))
		execute_strategy(&a, &b, &bench);
	if (bench.enabled)
		print_bench(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
