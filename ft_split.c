/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaymaz <asaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:50:54 by asaymaz           #+#    #+#             */
/*   Updated: 2025/06/21 14:52:47 by asaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static void	init_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	if (!s)
		return (NULL);
	init_vars(&i, &j, &s_word);
	res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || s[i] == '\0') && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!res[j++])
				return (ft_free(res, j - 1));
			s_word = -1;
		}
		i++;
	}
	return (res);
}
