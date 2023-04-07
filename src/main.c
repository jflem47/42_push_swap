/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:11:15 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 18:49:05 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_env	env;
	int		parsing;

	if (ac < 2)
		return (FAILURE);
	env.begin_a = (t_list **)ft_calloc(1, sizeof(t_list **));
	env.begin_b = (t_list **)ft_calloc(1, sizeof(t_list **));
	env.algo_data = ft_calloc(1, sizeof(t_algo_data));
	env.rot_data_a = ft_calloc(1, sizeof(t_rotation_data));
	env.rot_data_b = ft_calloc(1, sizeof(t_rotation_data));
	parsing = parse_args(ac, av, &env);
	if (parsing == FAILURE)
	{
		free_exit(&env);
		ft_putendl_fd("Error", 2);
		return (FAILURE);
	}
	push_swap(&env);
	free_exit(&env);
	return (SUCCESS);
}
