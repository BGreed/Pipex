/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:35:15 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:01 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_conversion(va_list args, const char format)
{
	int	impress;

	impress = 0;
	if (format == 's')
		impress += ft_putstr(va_arg(args, const char *));
	else if (format == 'c')
		impress += ft_putchar(va_arg(args, int));
	else if (format == 'p')
		impress += ft_convert_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		impress += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		impress += ft_putusig(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		impress += ft_printhexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		impress += ft_putchar('%');
	return (impress);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		impress;
	va_list	args;

	va_start(args, str);
	impress = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			impress += ft_conversion(args, str[i + 1]);
			i++;
		}
		else
			impress += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (impress);
}
