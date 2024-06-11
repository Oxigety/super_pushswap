/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:13:36 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/12 16:13:37 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	count_words(const char *s, char c)
{
	int	nbr;

	nbr = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			nbr++;
		while (*s != c && *s)
			s++;
	}
	return (nbr);
}

char	*alloc_words(const char *s, char c, unsigned int current_word)
{
	char		*word;
	size_t		i;
	size_t		begin;
	size_t		end;

	i = 0;
	while (current_word--)
	{
		while (s[i] == c && s[i])
			i++;
		begin = i;
		while (s[i] != c && s[i])
			i++;
	}
	end = i;
	word = malloc(sizeof(char) * (end - begin + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
		word[i++] = s[begin++];
	word[i] = '\0';
	return (word);
}

void	free_all(size_t current_word, char **tab)
{
	while (current_word > 0)
	{
		free(tab[current_word - 1]);
		current_word--;
	}
	free(tab);
}

char	**ft_split(char const *s, char c, int *argc, int current_word)
{
	char		**tab;
	int			nb_words;

	nb_words = count_words(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 2));
	if (tab == NULL)
		return (NULL);
	while (++current_word <= nb_words)
	{
		tab[current_word] = alloc_words(s, c, current_word);
		if (tab[current_word] == NULL)
		{
			free_all(current_word + 1, tab);
			return (NULL);
		}
	}
	tab[nb_words + 1] = NULL;
	*argc = nb_words + 1;
	if (tab[1] == NULL)
	{
		free(tab);
		exit(0);
	}
	return (tab);
}
