/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:28:49 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 19:26:58 by jlemieux         ###   ########.fr       */
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

void	rotate_best(t_env *env, char lst)
{
	int				i;
	t_rotation_data	*rot;

	i = 0;
	if (lst == 'a')
		rot = env->rot_data_a;
	else
		rot = env->rot_data_b;
	while (i++ < rot->reps)
	{
		if (rot->rev == 1)
		{
			if (lst == 'a')
				make_move(RRA, env);
			else
				make_move(RRB, env);
		}
		else
		{
			if (lst == 'a')
				make_move(RA, env);
			else
				make_move(RB, env);
		}
	}
}
