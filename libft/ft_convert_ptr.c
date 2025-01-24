/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:16:36 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:50 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_convert_ptr(void *pt)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	if (!pt)
		return (write(1, "(nil)", 5));
	else
	{
		ptr = (unsigned long long)pt;
		count += write(1, "0x", 2);
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	}
	return (count);
}
