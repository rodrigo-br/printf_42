/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:55:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 19:07:29 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string_formated;
	int		s_len;

	va_start(args, format);
	string_formated = ft_count_placeholders((char *)format, args);
	va_end(args);
	ft_putstr_fd(string_formated, 1);
	s_len = ft_strlen(string_formated);
	free(string_formated);
	return (s_len);
}
