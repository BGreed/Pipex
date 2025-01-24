/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:57:25 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:40 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_putusig(unsigned int nb)
{
	long				nbr;
	unsigned int		count;

	nbr = nb;
	count = 0;
	if (nbr >= 10)
	{
		count += ft_putusig(nbr / 10);
		count += ft_putusig(nbr % 10);
	}
	else
		count += ft_putchar(nbr + 48);
	return (count);
}
