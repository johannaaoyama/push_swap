/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:10:30 by johannaaoya       #+#    #+#             */
/*   Updated: 2026/11/16 16:09:01 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *arr, int *tmp, t_span s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = s.lo;
	j = s.mid;
	k = s.lo;
	while (i < s.mid && j < s.hi)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i < s.mid)
		tmp[k++] = arr[i++];
	while (j < s.hi)
		tmp[k++] = arr[j++];
	k = s.lo;
	while (k < s.hi)
	{
		arr[k] = tmp[k];
		k++;
	}
}

static void	merge_sort(int *arr, int *tmp, size_t lo, size_t hi)
{
	t_span	s;

	if (hi - lo < 2)
		return ;
	s.lo = lo;
	s.mid = lo + (hi - lo) / 2;
	s.hi = hi;
	merge_sort(arr, tmp, s.lo, s.mid);
	merge_sort(arr, tmp, s.mid, s.hi);
	merge(arr, tmp, s);
}

static int	*sort_array(t_stack *a)
{
	int		*sorted;
	int		*tmp;
	t_node	*cur;
	size_t	i;

	sorted = malloc(sizeof(int) * a->size);
	tmp = malloc(sizeof(int) * a->size);
	if (!sorted || !tmp)
	{
		free(sorted);
		free(tmp);
		return (NULL);
	}
	i = 0;
	cur = a->head;
	while (cur)
	{
		sorted[i++] = cur->value;
		cur = cur->next;
	}
	merge_sort(sorted, tmp, 0, a->size);
	free(tmp);
	return (sorted);
}

static void	assign_ranks(t_stack *a, const int *sorted)
{
	t_node	*cur;
	size_t	lo;
	size_t	mid;
	size_t	hi;

	cur = a->head;
	while (cur)
	{
		lo = 0;
		hi = a->size;
		while (lo < hi)
		{
			mid = lo + (hi - lo) / 2;
			if (sorted[mid] < cur->value)
				lo = mid + 1;
			else
				hi = mid;
		}
		cur->index = (int)lo;
		cur = cur->next;
	}
}

void	assign_index(t_stack *a)
{
	int	*sorted;

	if (!a || !a->head)
		return ;
	sorted = sort_array(a);
	if (!sorted)
		return ;
	assign_ranks(a, sorted);
	free(sorted);
}
