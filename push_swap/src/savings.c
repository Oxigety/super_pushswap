/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:53:07 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:53:08 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

char	**save_argv(char **argv)
{
	static char	**last_argv;

	if (argv == NULL)
		argv = last_argv;
	else
		last_argv = argv;
	return (last_argv);
}

int	save_argc(int argc)
{
	static int	last_argc;

	if (argc == 0)
		argc = last_argc;
	else
		last_argc = argc;
	return (last_argc);
}

bool	save_split(int split)
{
	static bool	last_split;

	if (split == -1)
		split = last_split;
	else
		last_split = split;
	return (last_split);
}

// void	empty_stack(t_stack **m_head_b, t_stack **m_head_a)
// {
// 	while (*m_head_b != NULL)
// 	{
// 		pa(m_head_a, m_head_b, 1);
// 	}
// }