/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:05:46 by mgordag           #+#    #+#             */
/*   Updated: 2022/03/13 17:48:35 by gunjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_formats(va_list args, const char format);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int num, int len);
int	ft_print_unsigned(unsigned int num, int len);
int	ft_put_hex(unsigned int num, const char a, int len);
int	ft_print_ptr(unsigned long int num, int len);

#endif
