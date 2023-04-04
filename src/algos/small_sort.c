/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:27:55 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/30 15:12:28 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_env *env)
{
	t_list	*one;
	t_list	*two;
	t_data	*c_1;
	t_data	*c_2;

	one = *env->begin_a;
	two = one->next;
	c_1 = one->content;
	c_2 = two->content;
	if (c_1->value > c_2->value)
		sa(env);
}

void	sort_3(t_env *env)
{
	int	index;

	update_index(env);
	env->highest = find_highest(env, 'a');
	index = highest_index(env, 'a');
	if (index != 2)
	{
		if (index == 1)
			rra(env);
		else
			ra(env);
	}
	sort_2(env);
}
