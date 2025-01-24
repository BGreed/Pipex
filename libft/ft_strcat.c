/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:25:31 by braugust          #+#    #+#             */
/*   Updated: 2025/01/14 08:02:45 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dlen;

	i = 0;
	dlen = ft_strlen(dest);
	while (src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = 0;
	return (dest);
}

