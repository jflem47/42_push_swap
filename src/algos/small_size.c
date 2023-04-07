/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:33 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 19:25:58 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_rotations(t_env *env, int index, int lim, char lst)
{
	t_rotation_data	*rot;

	if (lst == 'a')
		rot = env->rot_data_a;
	else
		rot = env->rot_data_b;
	if (index <= lim)
	{
		rot->reps = index;
		rot->rev = 0;
	}
	else
	{
		if (lst == 'a')
			rot->reps = env->size_a - index;
		else
			rot->reps = env->size_b - index;
		rot->rev = 1;
	}
}

void	rotate(t_env *env)
{
	int				i;
	t_rotation_data	*rot;

	env->algo_data->lim = env->size_a / 2;
	calculate_rotations(env, lowest_index(env), env->algo_data->lim, 'a');
	rot = env->rot_data_a;
	i = 0;
	while (i++ < rot->reps)
	{
		if (rot->rev == 1)
			make_move(RRA, env);
		else
			make_move(RA, env);
	}
}

static void	sort_small(t_env *env)
{
	env->algo_data->current = *env->begin_a;
	if (ft_lstsize(env->algo_data->current) == 3)
		sort_3(env);
	else if (is_sorted(env))
		return ;
	else
	{
		env->lowest = find_lowest(env, 'a');
		env->highest = find_highest(env, 'a');
		while (env->algo_data->current && !is_sorted(env))
		{
			env->algo_data->data = env->algo_data->current->content;
			if (env->algo_data->data->value == env->lowest)
			{
				make_move(PB, env);
				break ;
			}
			rotate(env);
			env->algo_data->current = *env->begin_a;
		}
		if (!is_sorted(env))
			sort_small(env);
		if (env->size_b != 0)
			make_move(PA, env);
	}
}

void	small_size(t_env *env)
{
	env->lowest = find_lowest(env, 'a');
	env->highest = find_highest(env, 'a');
	bubble_sort(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	if (env->size_a == 2)
		sort_2(env);
	else if (env->size_a == 3)
		sort_3(env);
	else
		sort_small(env);
}
