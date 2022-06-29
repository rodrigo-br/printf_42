/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:55:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/29 17:25:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string_formated;

	va_start(args, format);
	string_formated = ft_count_placeholders((char *)format, args);
	va_end(args);
	ft_putstr_fd(string_formated, 1);
	return (ft_strlen(string_formated));
}
