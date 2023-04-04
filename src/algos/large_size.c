/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:16:16 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/30 17:30:49 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_back(t_env *env)
{
	int i;

	i = 0;
	while (env->size_b > 0)
	{
		i = 0;
		env->highest = find_highest(env, 'b');
		calculate_rotations(env, highest_index(env, 'b'), env->size_b / 2, 'b');
		while (i++ < env->rotation_data->reps)
		{
			if (env->rotation_data->rev == 1)
				rrb(env);
			else
				rb(env);
		}
		pa(env);
	}
} 

static void	large_sort(t_env *env)
{
	int i;
	int j;
	int max;

	max = env->size_a / 11 + 1;
	j = 0;
	i = 0;
	while (j < 11)
	{
		i = 0;
		while (i < max)
		{
			make_best_move(env, j * max, (j + 1) * max);
			i++;
		}
		j++;
	}
	sort_back(env);
}

static void	medium_sort(t_env *env)
{
	int i;
	int j;
	int max;

	max = env->size_a / 5;
	j = 0;
	i = 0;
	while (j < 5)
	{
		i = 0;
		while (i++ < max)
			make_best_move(env, j * max, (j + 1) * max);
		j++;
	}
	sort_back(env);
}

void	large_size(t_env *env)
{
	env->lowest = find_lowest(env);
	env->highest = find_highest(env, 'a');
	bubble_sort(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	else if (env->size_a <= 200)
		medium_sort(env);
	else
		large_sort(env);
}
