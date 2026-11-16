/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:08:28 by kevin             #+#    #+#             */
/*   Updated: 2026/11/16 16:55:57 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_str(const char *s)
{
	if (s)
		write(2, s, ft_strlen(s));
}

static void	put_percent(double d)
{
	long	h;

	h = (long)(d * 10000.0 + 0.5);
	ft_putnbr_fd((int)(h / 100), 2);
	write(2, ".", 1);
	if (h % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd((int)(h % 100), 2);
	write(2, "%", 1);
}

static void	put_op(const char *name, int n, char sep)
{
	put_str(name);
	put_str(": ");
	ft_putnbr_fd(n, 2);
	write(2, &sep, 1);
}

static void	put_strategy(t_bench *b)
{
	put_str("[bench] strategy: ");
	if (b->adaptive)
		put_str("Adaptive");
	else if (b->strategy == 1)
		put_str("Simple");
	else if (b->strategy == 2)
		put_str("Medium");
	else
		put_str("Complex");
	if (b->strategy == 1)
		put_str(" / O(n²)");
	else if (b->strategy == 2)
		put_str(" / O(n√n)");
	else
		put_str(" / O(n log n)");
}

void	print_bench(t_bench *b)
{
	put_str("[bench] disorder: ");
	put_percent(b->disorder);
	put_str("\n");
	put_strategy(b);
	put_str("\n[bench] total_ops: ");
	ft_putnbr_fd(b->total_ops, 2);
	put_str("\n[bench] ");
	put_op("sa", b->sa, ' ');
	put_op("sb", b->sb, ' ');
	put_op("ss", b->ss, ' ');
	put_op("pa", b->pa, ' ');
	put_op("pb", b->pb, '\n');
	put_str("[bench] ");
	put_op("ra", b->ra, ' ');
	put_op("rb", b->rb, ' ');
	put_op("rr", b->rr, ' ');
	put_op("rra", b->rra, ' ');
	put_op("rrb", b->rrb, ' ');
	put_op("rrr", b->rrr, '\n');
}

