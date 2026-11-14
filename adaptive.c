/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johannaaoyama <johannaaoyama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:11:43 by johannaaoya       #+#    #+#             */
/*   Updated: 2026/11/14 12:11:46 by johannaaoya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack *a, t_stack *b)
        {
                if (compute_disorder(a) < 0.2)
		{
			printf("selected simple\n");
               		selection_sort(a, b); 
		}
		else if (compute_disorder(a) < 0.5)
		{
			printf("selected medium\n");
                      	chunk_sort(a, b);
		}
                else if (compute_disorder(a) >= 0.5)
                {
			printf("selected complex\n");
		        radix_sort(a, b); // change this to complex
        	}
	}
