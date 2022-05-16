/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:20:48 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/01 16:42:37 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	counter = 0;
	i = -1;
	va_start(args, format);
	counter = ft_printf_iteri(format, &args, counter, i);
	va_end(args);
	return (counter);
}

int	ft_printf_iteri(const char *format, va_list *args, int counter, int i)
{
	while (format && format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += ft_printf_formatspecifier(format, args, i);
		}
		else
			counter += write(1, &format[i], 1);
	}
	return (counter);
}

int	ft_printf_formatspecifier(const char *format, va_list *args, int i)
{
	int	ret;

	ret = 0;
	if (format[i] == 'c')
		ret += ft_printf_c(va_arg(*args, int));
	else if (format[i] == 's')
		ret += ft_printf_s(va_arg(*args, char *));
	else if (format[i] == 'p')
		ret += ft_printf_p(va_arg(*args, unsigned long int));
	else if (format[i] == 'd' || format[i] == 'i')
		ret += ft_printf_di(va_arg(*args, int));
	else if (format[i] == 'u')
		ret += ft_printf_u(va_arg(*args, unsigned int));
	else if (format[i] == 'x')
		ret += ft_printf_x(va_arg(*args, long));
	else if (format[i] == 'X')
		ret += ft_printf_mx(va_arg(*args, long));
	else if (format[i] == '%')
		ret += write(1, "%", 1);
	return (ret);
}
