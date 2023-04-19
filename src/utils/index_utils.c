/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:45 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/19 12:52:48 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_index(t_env *env)
{
	t_list	*current;
	t_data	*data;

	current = *env->begin_a;
	while (current)
	{
		data = current->content;
		if (data->value == env->lowest)
			return (data->index);
		current = current->next;
	}
	return (0);
}

int	highest_index(t_env *env, char lst)
{
	t_list	*current;
	t_data	*data;

	env->highest = find_highest(env, lst);
	if (lst == 'a')
		current = *env->begin_a;
	else
		current = *env->begin_b;
	while (current)
	{
		data = current->content;
		if (data->value == env->highest)
			return (data->index);
		current = current->next;
	}
	return (0);
}

int	find_highest(t_env *env, char lst)
{
	t_list	*current;
	t_data	*data;
	int		res;
	int		tmp;

	if (lst == 'a')
		current = *env->begin_a;
	else
		current = *env->begin_b;
	res = INT32_MIN;
	while (current)
	{
		data = current->content;
		tmp = data->value;
		if (tmp > res)
			res = tmp;
		current = current->next;
	}
	return (res);
}

void	update_index(t_env *env)
{
	int		i;
	t_list	*current;
	t_data	*data;

	current = *env->begin_a;
	i = 0;
	while (current)
	{
		data = current->content;
		data->index = i++;
		current = current->next;
	}
	env->size_a = i;
	current = *env->begin_b;
	i = 0;
	while (current)
	{
		data = current->content;
		data->index = i++;
		current = current->next;
	}
	env->size_b = i;
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
