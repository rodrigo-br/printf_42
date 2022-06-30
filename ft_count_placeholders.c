/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_placeholders.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:27:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/30 16:04:06 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_check_format(const char *format, char *new_str, int *i)
{
	t_bool	width_bool;
	int		width_value;
	int		index[1];

	(void) new_str;
	width_bool = FALSE;
	width_value = 0;
	*index = 1;
	while (ft_isformat(format[*index], &width_bool) && format[*index])
	{
		if (width_bool)
		{
			while (ft_isdigit(format[*index]))
			{
				width_value = width_value * 10 + (format[*index] - '0');
				*index = *index + 1;
			}
			width_bool = FALSE;
		}
		*index = *index + 1;
	}
	*i = *i + *index;
}

char	*ft_count_placeholders(const char *format, va_list args)
{
	int		index_format;
	char	*new_str;
	char	*aux;

	index_format = 0;
	aux = ft_strtilchr(format, '%');
	while (format[index_format])
	{
		if (format[index_format] == '%')
		{
			ft_runner_spcf(&aux, &format[index_format], args);
			ft_check_format(&format[index_format], aux, &index_format);
		}
		index_format++;
	}
	new_str = ft_strdup(aux);
	free(aux);
	return (new_str);
}
// SOCORRO O QUE EU TÔ FAZENDO? D:
