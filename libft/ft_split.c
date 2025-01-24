/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:45:28 by braugust          #+#    #+#             */
/*   Updated: 2024/06/06 14:27:10 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	countl(const char *s, char c, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (s[start] == c && s[start])
		start++;
	while (s[start] != c && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

static int	countstart(const char *s, char c, unsigned int start)
{
	while (s[start] != c && s[start])
		start++;
	while (s[start] == c && s[start])
		start++;
	return (start);
}

static char	**ft_dothes(char **new, const char *s, char c, int count)
{
	int				i;
	unsigned int	len;
	unsigned int	start;

	start = 0;
	i = 0;
	while (s[start] && s[start] == c)
		start++;
	while (i < count)
	{
		len = countl(s, c, start);
		new[i] = ft_substr(s, start, len);
		if (new[i] == NULL)
		{
			while (i >= 0)
				free(new[i--]);
			free(new);
			return (NULL);
		}
		i++;
		start = countstart(s, c, start);
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		count;

	count = countw(s, c);
	new = malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (NULL);
	new = ft_dothes(new, s, c, count);
	return (new);
}
