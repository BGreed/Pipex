/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:51:50 by braugust          #+#    #+#             */
/*   Updated: 2024/06/04 13:34:45 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_size(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len ++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_result(char *result, long int nbr, int len)
{
	if (nbr == 0)
	{
		result[0] = '0';
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			len;
	char		*result;

	nbr = n;
	len = ft_size(nbr);
	result = malloc((sizeof(char)) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	ft_result(result, nbr, len);
	return (result);
}
