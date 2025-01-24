/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:05:02 by braugust          #+#    #+#             */
/*   Updated: 2024/05/30 18:25:10 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t tab, size_t size)
{
	char	*dest;

	if (size != 0 && ((size * tab) / size != tab))
		return (NULL);
	dest = malloc(size * tab);
	if (!dest)
		return (NULL);
	ft_bzero(dest, (size * tab));
	return (dest);
}
