/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 08:55:28 by kevin             #+#    #+#             */
/*   Updated: 2026/09/01 13:07:36 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	pairs;
	t_node	*cur;
	t_node	*nxt;

	if (!a || a->size < 2) 
		return (0.0);
	mistakes = 0;
	pairs = 0;
	cur = a->head;
	while(cur)
	{
        nxt = cur->next;
        while(nxt)
        {
            pairs++;
            if (cur->value > nxt->value)
                mistakes++;
            nxt = nxt->next;
        }
        cur = cur->next;
	}
    if (pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)pairs);
}