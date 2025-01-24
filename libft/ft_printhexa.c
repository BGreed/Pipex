/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:16:27 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:08 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_printhexa(unsigned int nb, const char base)
{
	int		count;

	count = 0;
	if (base == 'x')
	{
		count += ft_putnbr_base(nb, "0123456789abcdef");
	}
	else
		count += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (count);
}
