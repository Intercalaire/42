/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:36:34 by vgodart           #+#    #+#             */
/*   Updated: 2024/04/01 13:40:52 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_lst **stack)
{
	t_lst	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = lst_last(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = *stack;
	(*stack)->prev = lst;
	*stack = (*stack)->prev;
}

void	do_rra(t_lst **stack)
{
	reverse(stack);
	ft_printf("rra\n");
}

void	do_rrb(t_lst **stack)
{
	reverse(stack);
	ft_printf("rra\n");
}

void	do_rrr(t_lst **a_stack, t_lst **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_printf("rrr\n");
}
