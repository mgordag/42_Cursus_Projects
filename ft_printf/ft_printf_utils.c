/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:31 by mgordag           #+#    #+#             */
/*   Updated: 2022/03/13 17:48:14 by gunjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long int num, int len)
{
	if (num >= 16)
	{
		len = ft_print_ptr(num / 16, len);
		len = ft_print_ptr(num % 16, len);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar((num + '0'));
		else
			len += ft_putchar((num - 10 + 'a'));
	}
	return (len);
}

int	ft_put_hex(unsigned int num, const char a, int len)
{
	if (num >= 16)
	{
		len = ft_put_hex(num / 16, a, len);
		len = ft_put_hex(num % 16, a, len);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar((num + '0'));
		else
		{
			if (a == 'x')
				len += ft_putchar((num - 10 + 'a'));
			else
				len += ft_putchar((num - 10 + 'A'));
		}
	}
	return (len);
}

int	ft_putnbr(int num, int len)
{
	if (num == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (num < 0)
	{
		len += ft_putchar('-');
		len = ft_putnbr((num * -1), len);
	}
	if (num > 9)
	{
		len = ft_putnbr(num / 10, len);
		len = ft_putnbr(num % 10, len);
	}
	else if (num >= 0)
		len += ft_putchar(num + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int num, int len)
{
	if (num > 9)
	{
		len = ft_print_unsigned(num / 10, len);
		len = ft_print_unsigned(num % 10, len);
	}
	else
		len += ft_putchar(num + '0');
	return (len);
}
