/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:55:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/04 18:17:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	simple_print(const char *s, int *size)
{
	char *temp;
	
	temp = ft_strtilchr(s, '%');
	*size += ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
}

static t_str	check_specifier(const char *format, va_list args, \
t_flags flags, int *count)
{
	t_str	str;
	(void) format;
	
	str.s = "";
	str.size = 0;
	if (flags.spcf == 'c')
		str = handle_char(args, count);
	// else if (flags.spcf == 'i' || flags.spcf == 'd')
	// 	handle_n(format, str, args);
	// else if (flags.spcf == 's')
	// 	handle_str(format, str, args);
	// else if (flags.spcf == 'u')
	// 	handle_unsigned(format, str, args);
	// else if (flags.spcf == 'p')
	// 	handle_pointer(format, str, args);
	// else if (flags.spcf == 'x' || flags.spcf == 'X')
	// 	handle_hex(format, str, args);
	// else if (flags.spcf == '%')
		// handle_ph(format, str, args);
	// check_flags(format, str, args, flags);
	return (str);
}

static int	parse_format(const char *format, va_list args, int *count)
{
	int		index;
	t_bool	width;
	t_flags flags;
	t_str	str_parsed;

	width = FALSE;
	index = 0;
	flags = ft_init_flags(format);
	while (ft_isformat(format[index], &width))
	{
		if (width && flags.width_value == 0)
		{
			flags.width_value = atoi(&format[index]);
			width = FALSE;
		}
		index++;
	}
	str_parsed = check_specifier(format, args, flags, count);
	write(1, str_parsed.s, str_parsed.size);
	free(str_parsed.s);
	
	return (index + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	simple_print(format, &count);
	va_start(args, format);
	while(*format)
	{
		if (*format == '%')
		{
			format += parse_format((format + 1), args, &count);
			simple_print(format + 1, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
