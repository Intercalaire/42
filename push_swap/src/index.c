/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:36:34 by vgodart           #+#    #+#             */
/*   Updated: 2024/04/01 13:40:17 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_lst	*ps_get_min(t_lst **stack)
{
	t_lst	*lst;
	t_lst	*lst_min;
	int		min;

	if (!(*stack))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *stack;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || lst->content < lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	ps_index(t_lst **stack)
{
	t_lst	*lst;
	int		index;

	index = 0;
	lst = ps_get_min(stack);
	while (lst)
	{
		lst->index = index++;
		lst = ps_get_min(stack);
	}
}
