/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:36:34 by vgodart           #+#    #+#             */
/*   Updated: 2024/04/01 13:41:00 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_lst **stack)
{
	t_lst	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = lst_last(*stack);
	lst->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst->next->prev = lst;
	lst->next->next = NULL;
}

void	do_ra(t_lst **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	do_rb(t_lst **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	do_rr(t_lst **a_stack, t_lst **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	ft_printf("rr\n");
}
