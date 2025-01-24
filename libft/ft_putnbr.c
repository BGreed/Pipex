/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:42:58 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:34 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		count += ft_putchar('-');
		count += ft_putnbr(nbr);
	}
	else if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	else
		count += ft_putchar(nbr + 48);
	return (count);
}
