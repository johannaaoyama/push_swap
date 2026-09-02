/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:23:04 by jaoyama           #+#    #+#             */
/*   Updated: 2026/09/01 15:29:01 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* notes on push_swap program logic:

void    push_swap(t_stack *a)
{
	// 1. If no parameters are specified, the program must not display anything and give the prompt back.
        if (argc == 1)
                return ; // give back the prompt

        // 2. parsing & validation:
        // parse_and_validate(); // proceed or return "Error \n"
        if argc == 2
                split string by whitespace, then proceed with "for each element"

        if argc > 2, go through arguments one by one,
                check each -> is it whitespace? -> split // this is to catch the edge case input "1" "4" "-5" "1 2 3" "-42"
                        for each element: is it numeric? -> if yes -> atol -> within INT MIN/MAX? -> if yes -> duplicate? -> if no -> into array & proceed with next element

        // -> we have array int *valid_input

        // 3. create doubly linked list from integer array *valid_input
        // -> we have a t_stack *a;

        // 4. if algo not specified, go adaptive -> decide based on disorder
        {
                disorder = calc_disorder(a);
                if (--simple == true || (disorder < 0.2 && --medium == false && --complex == false))
                        simple(a);
                        // return: ft_printf(ops) and send benchmarks to stderr; or Error
                        // benchmarks to stderr
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
                if (––medium == true || (disorder < 0.5 && disorder >= 0.2))
                        medium(a);
                if (--complex == true || disorder >= 0.5)
                        complex(a);
        }
}
*/
