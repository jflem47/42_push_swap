/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:11 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/18 17:24:23 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_algo_data(t_algo_data *algo_data)
{
	algo_data->current = NULL;
	algo_data->data = NULL;
	algo_data->b = NULL;
	algo_data->tmp = NULL;
	algo_data->data_b = NULL;
	algo_data->data_tmp = NULL;
}
