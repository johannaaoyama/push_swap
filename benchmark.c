/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:08:28 by kevin             #+#    #+#             */
/*   Updated: 2026/11/14 13:59:55 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_header(t_bench *bench)
{
	write(2, "--- BENCHMARK REPORT ---\n", 25);
	write(2, "Strategy: ", 10);
	ft_putstr_fd(bench->strategy_name, 2);
	write(2, "\n", 1);
	write(2, "Complexity Class: ", 18);
	ft_putstr_fd(bench->complexity, 2);
	write(2, "\n", 1);
	write(2, "Initial Disorder: ", 18);
	ft_putnbr_fd((int)(bench->disorder * 100.0), 2);
	write(2, "%\n", 2);
	write(2, "Total Operations: ", 18);
	ft_putnbr_fd(bench->total_ops, 2);
	write(2, "\n", 1);
}

static void	print_bench_swaps_pushes(t_bench *bench)
{
	write(2, "Ops breakdown -> sa: ", 21);
	ft_putnbr_fd(bench->sa, 2);
	write(2, ", sb: ", 6);
	ft_putnbr_fd(bench->sb, 2);
	write(2, ", ss: ", 6);
	ft_putnbr_fd(bench->ss, 2);
	write(2, "\n", 1);
	write(2, "               -> pa: ", 21);
	ft_putnbr_fd(bench->pa, 2);
	write(2, ", pb: ", 6);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);
}

static void	print_bench_rotates(t_bench *bench)
{
	write(2, "               -> ra: ", 21);
	ft_putnbr_fd(bench->ra, 2);
	write(2, ", rb: ", 6);
	ft_putnbr_fd(bench->rb, 2);
	write(2, ", rr: ", 6);
	ft_putnbr_fd(bench->rr, 2);
	write(2, "\n", 1);
	write(2, "               -> rra: ", 22);
	ft_putnbr_fd(bench->rra, 2);
	write(2, ", rrb: ", 7);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, ", rrr: ", 7);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n------------------------\n", 26);
}

void	print_bench(t_bench *bench)
{
	print_bench_header(bench);
	print_bench_swaps_pushes(bench);
	print_bench_rotates(bench);
}

void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->disorder = 0.0;
	bench->strategy_name = NULL;
	bench->complexity = NULL;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}