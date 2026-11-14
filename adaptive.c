/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:11:43 by johannaaoya       #+#    #+#             */
/*   Updated: 2026/11/14 14:15:54 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	if (compute_disorder(a) < 0.2)
	{
        selection_sort(a, b); 
		bench->complexity = "O(n^2)";
	}
	else if (compute_disorder(a) < 0.5)
	{
        chunk_sort(a, b);
		bench->complexity = "O(n sqrt (n))";
	}
    else if (compute_disorder(a) >= 0.5)
    {
		radix_sort(a, b);
		bench->complexity = "O(n log n)";
	}
}
