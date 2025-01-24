/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:28:45 by braugust          #+#    #+#             */
/*   Updated: 2024/05/30 16:49:58 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*str;
	unsigned char	*tofind;

	i = 0;
	str = (unsigned char *)big;
	tofind = (unsigned char *)little;
	if (*tofind == 0)
		return ((char *)str);
	while (str[i])
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while ((str[i + j] == tofind[j]) && tofind[j] && (i + j < len))
			{
				j++;
				if (tofind[j] == 0)
					return ((char *)(&str[i]));
			}
		}
		i++;
	}
	return (0);
}
