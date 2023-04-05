/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:28:49 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/05 16:58:00 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_elem_nindex(t_env *env, int n_index, char lst)
{
	t_list	*current;
	t_data	*data;

	if (lst == 'a')
		current = *env->begin_a;
	else
		current = *env->begin_b;
	data = NULL;
	while (current)
	{
		data = current->content;
		if (n_index == data->n_index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	bubble_sort(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < env->size_a - 1)
	{
		j = 0;
		while (j < env->size_a - i - 1)
		{
			set_variables_bubblesort(env, j);
			j++;
		}
		i++;
	}
}

void	rotate_best(t_env *env, int index, char lst)
{
	int	i;

	i = 0;
	if (lst == 'a')
		calculate_rotations(env, index, env->size_a / 2, 'a');
	else
		calculate_rotations(env, index, env->size_b / 2, 'b');
	while (i++ < env->rotation_data->reps)
	{
		if (env->rotation_data->rev == 1)
		{
			if (lst == 'a')
				rra(env);
			else
				rrb(env);
		}
		else
		{
			if (lst == 'a')
				ra(env);
			else
				rb(env);
		}
	}
}

void	make_best_move(t_env *env, int min, int max)
{
	int			moves;
	int			i;
	t_algo_data	data;

	i = min;
	moves = INT32_MAX;
	while (i < max)
	{
		data.current = find_elem_nindex(env, i, 'a');
		if (data.current)
		{
			data.data = data.current->content;
			data.index = data.data->index;
			calculate_rotations(env, data.index, env->size_a / 2, 'a');
			if (env->rotation_data->reps < moves)
			{
				moves = env->rotation_data->reps;
				data.best_index = data.index;
			}
		}
		i++;
	}
	rotate_best(env, data.best_index, 'a');
	pb(env);
}
