/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:50:46 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:50:47 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **m_stack_a, bool print)
{
	t_stack	*current;
	t_stack	*head;

	current = *m_stack_a;
	head = *m_stack_a;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	*m_stack_a = current;
	current->next = head;
	head->prev = current;
	current->prev = NULL;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **m_stack_b, bool print)
{
	t_stack	*current;
	t_stack	*head;

	current = *m_stack_b;
	head = *m_stack_b;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	*m_stack_b = current;
	current->next = head;
	head->prev = current;
	current->prev = NULL;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **m_stack_a, t_stack **m_stack_b)
{
	rra(m_stack_a, false);
	rrb(m_stack_b, false);
	ft_printf("rrr\n");
}

void	r_rotate_a_b(t_stack **m_head_a, t_stack **m_head_b, t_stack *cheapest)
{
	while (*m_head_a != cheapest && *m_head_b != cheapest->target)
		rrr(m_head_a, m_head_b);
	set_index(*m_head_a);
	set_index(*m_head_b);
}
