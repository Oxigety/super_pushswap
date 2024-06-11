/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:18:25 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/18 19:18:26 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **m_head_a, t_stack **m_head_b, bool freed)
{
	int	max;

	max = find_max_rank(*m_head_a);
	if ((*m_head_a)->data == max)
		ra(m_head_a, true);
	else if ((*m_head_a)->next->data == max)
		rra(m_head_a, true);
	if ((*m_head_a)->data > (*m_head_a)->next->data)
		sa(m_head_a, true);
	if (freed)
		free_push_swap(m_head_a, m_head_b);
}

void	sort_stacks(t_stack **m_head_a, t_stack **m_head_b)
{
	int	size_a;

	size_a = stack_len(*m_head_a);
	if (size_a-- > 3 && !is_in_order(*m_head_a))
		pb(m_head_a, m_head_b, true);
	if (size_a-- > 3 && !is_in_order(*m_head_a))
		pb(m_head_a, m_head_b, true);
	while (size_a-- > 3 && !is_in_order(*m_head_a))
	{
		update_nodes_a(*m_head_a, *m_head_b);
		rotate_push_b(m_head_a, m_head_b);
	}
	sort_three(m_head_a, m_head_b, false);
	while (*m_head_b)
	{
		update_nodes_b(*m_head_a, *m_head_b);
		rotate_push_a(m_head_a, m_head_b);
	}
	set_index(*m_head_a);
	min_on_top(m_head_a);
	free_push_swap(m_head_a, m_head_b);
}

void	sort_two(t_stack **m_head_a, t_stack **m_head_b)
{
	sa(m_head_a, true);
	free_push_swap(m_head_a, m_head_b);
}

int	stack_init(t_stack **m_head_a, t_stack **m_head_b, char **argv, int argc)
{
	if (argv == NULL)
		return (0);
	*m_head_b = NULL;
	(*m_head_a) = malloc(sizeof(t_stack));
	if ((*m_head_a) == NULL)
		return (0);
	(*m_head_a)->prev = NULL;
	(*m_head_a)->next = NULL;
	save_argv(argv);
	save_argc(argc);
	fill_a(m_head_a, argv, argc - 1);
	if (check_inv_nb((*m_head_a)))
	{
		free_push_swap(m_head_a, m_head_b);
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	else if (is_in_order((*m_head_a)))
	{
		free_push_swap(m_head_a, m_head_b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack			*m_head_a;
	t_stack			*m_head_b;
	static bool		splitted = false;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ', &argc, 0);
		splitted = true;
	}
	save_split(splitted);
	if (stack_init(&m_head_a, &m_head_b, argv, argc))
	{
		if (argc - 1 == 2)
			sort_two(&m_head_a, &m_head_b);
		else if (argc - 1 == 3)
			sort_three(&m_head_a, &m_head_b, true);
		else
			sort_stacks(&m_head_a, &m_head_b);
	}
	if (splitted)
		free_split(argv, argc);
	return (0);
}
