/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:08:28 by kevin             #+#    #+#             */
/*   Updated: 2026/11/16 09:57:51 by kevin            ###   ########.fr       */
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

void	print_bench(t_bench *b)
{
	put_str("[bench] disorder: ");
	put_percent(b->disorder);
	put_str("\n[bench] strategy: ");
	put_str(b->strategy_name);
	put_str(" / ");
	put_str(b->complexity);
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
