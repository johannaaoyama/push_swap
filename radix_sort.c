/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johannaaoyama <johannaaoyama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:22:28 by johannaaoya       #+#    #+#             */
/*   Updated: 2026/11/14 12:59:14 by johannaaoya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int		bit;
	size_t	n;
	size_t	i;

	assign_index(a);	// replace with O(n log n) ranking first
	bit = 0;
	while ((a->size > 0) && (1 << bit) < (int)a->size)
	{
		n = a->size;
		i = 0;
		while (i < n)
		{
			if (((a->head->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
