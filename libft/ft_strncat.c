/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:41:49 by braugust          #+#    #+#             */
/*   Updated: 2025/01/14 07:50:00 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	dlen;

	i = 0;
	dlen = ft_strlen(dest);
	while (src[i] && nb > 0)
	{
		dest[dlen + i] = src[i];
		i++;
		nb--;
	}
	dest[dlen + i] = 0;
	return (dest);
}
