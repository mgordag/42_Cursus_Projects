/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:16:59 by mgordag           #+#    #+#             */
/*   Updated: 2022/03/13 18:01:36 by gunjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	a = a % 256;
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ft_putchar(*str++);
		i++;
	}
	return (i);
}

int	format(const char a, va_list args)
{
	int	len;

	len = 0;
	if (a == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (a == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (a == 'p')
	{
		len += write(1, "0x", 2);
		len = ft_print_ptr(va_arg(args, unsigned long int), len);
	}
	else if (a == 'x' || a == 'X')
		len += ft_put_hex(va_arg(args, unsigned int), a, len);
	else if (a == 'd' || a == 'i')
		len += ft_putnbr(va_arg(args, int), len);
	else if (a == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int), len);
	else if (a == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			length += format(*(++str), args);
		else
			length += ft_putchar(*str);
		str++;
	}
	return (length);
}
