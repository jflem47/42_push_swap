/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:16:16 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 20:09:20 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	rotate_same(t_env *env)
// {
// 	int	i;
// 	int	reps_both;

// 	i = 0;
// 	if (env->rot_data_a->reps > env->rot_data_b->reps)
// 	{
// 		reps_both = env->rot_data_b->reps;
// 		env->rot_data_a->reps -= reps_both;
// 		rotate_best(env, 'a');
// 	}
// 	else
// 	{
// 		reps_both = env->rot_data_b->reps;
// 		env->rot_data_a->reps -= reps_both;
// 		rotate_best(env, 'b');
// 	}
// 	while (i++ < reps_both)
// 	{
// 		if (env->rot_data_b->rev == 1)
// 			rrr(env);
// 		else
// 			rr(env);
// 	}
// }

static void	large_sort(t_env *env)
{
	int	n_index;

	while (env->size_a > 0)
	{
		plot_best_move(env);
		calculate_rotations(env, env->next_move, env->size_a / 2, 'a');
		env->algo_data->current = find_elem_index(env, env->next_move, 'a');
		env->algo_data->data = env->algo_data->current->content;
		n_index = env->algo_data->data->n_index;
		calculate_rotations(env, find_neighbor(env, n_index), env->size_b / 2,
				'b');
		// if (env->rot_data_a->rev && env->rot_data_b->rev)
		// 	rotate_same(env);
		// else
		// {
		// 	rotate_best(env, 'b');
		// 	rotate_best(env, 'a');
		// }
		rotate_best(env, 'a');
		rotate_best(env, 'b');
		pb(env);
	}
	calculate_rotations(env, highest_index(env, 'b'), env->size_b / 2, 'b');
	rotate_best(env, 'b');
	while (env->size_b > 0)
		pa(env);
}

void	large_size(t_env *env)
{
	env->lowest = find_lowest(env, 'a');
	env->highest = find_highest(env, 'a');
	bubble_sort(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	else
		large_sort(env);
}
