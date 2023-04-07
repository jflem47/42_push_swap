/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:57:58 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 18:49:21 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	free(lst);
	lst = NULL;
}

void	free_split(char **args)
{
	size_t	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	is_sorted(t_env *env)
{
	t_list	*current;
	t_list	*next;
	t_data	*d1;
	t_data	*d2;

	current = *env->begin_a;
	if (ft_lstsize(current) == env->size_a)
	{
		while (current->next)
		{
			next = current->next;
			d1 = current->content;
			d2 = next->content;
			if (d1->value > d2->value)
				return (0);
			current = next;
		}
		return (1);
	}
	else
		return (0);
}

int	find_lowest(t_env *env, char lst)
{
	t_list	*current;
	t_data	*data;
	int		res;
	int		tmp;

	if (lst == 'a')
		current = *env->begin_a;
	else
		current = *env->begin_b;
	res = INT32_MAX;
	while (current)
	{
		data = current->content;
		tmp = data->value;
		if (tmp < res)
			res = tmp;
		current = current->next;
	}
	return (res);
}

void	free_exit(t_env *env)
{
	free_all(env->begin_a);
	free_all(env->begin_b);
	free(env->algo_data);
	free(env->rot_data_a);
	free(env->rot_data_b);
}
