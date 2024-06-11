/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:48:00 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:48:01 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sb(t_stack **head_b, bool print)
{
	t_stack	*temp;
	t_stack	*n;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	temp = *head_b;
	*head_b = (*head_b)->next;
	n = (*head_b)->next;
	(*head_b)->next = temp;
	temp->next = n;
	if (n != NULL)
		n->prev = temp;
	temp->prev = (*head_b);
	(*head_b)->prev = NULL;
	if (print)
		ft_printf("sb\n");
}

void	sa(t_stack **head_a, bool print)
{
	t_stack	*temp;
	t_stack	*n;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	temp = *head_a;
	*head_a = (*head_a)->next;
	n = (*head_a)->next;
	(*head_a)->next = temp;
	temp->next = n;
	if (n != NULL)
		n->prev = temp;
	temp->prev = (*head_a);
	(*head_a)->prev = NULL;
	if (print)
		ft_printf("sa\n");
}

void	ss(t_stack **m_stack_a, t_stack **m_stack_b)
{
	sa(m_stack_a, false);
	sb(m_stack_b, false);
	ft_printf("ss\n");
}
