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

static void	large_sort(t_env *env)
{
}

static void	medium_sort(t_env *env)
{
}

void	large_size(t_env *env)
{
	env->lowest = find_lowest(env);
	env->highest = find_highest(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	else if (env->size_a <= 100)
		medium_sort(env);
	else
		large_sort(env);
}
