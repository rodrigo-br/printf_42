/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_placeholders.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:27:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 20:31:16 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_check_format(const char *format, char *new_str, int *i)
{
	t_bool	width_bool;
	int		width_value;
	int		index[1];

	(void) new_str;
	width_bool = FALSE;
	*index = 1;
	while (ft_isformat(format[*index], &width_bool) && format[*index])
	{
		if (width_bool)
		{
			width_value = 0;
			while (ft_isdigit(format[*index]))
			{
				width_value = width_value * 10 + (format[*index] - '0');
				*index = *index + 1;
			}
			width_bool = FALSE;
			printf("width value = %d\n", width_value);
		}
		*index = *index + 1;
	}
	*i = *i + *index;
}

char	*ft_count_placeholders(const char *format, va_list args)
{
	int		index_format;
	char	*aux;
	char	*temp;
	char	*temp_middle_str;
	char	*temp_ph;

	index_format = 0;
	aux = ft_strtilchr(format, '%');
	while (format[index_format])
	{
		if (format[index_format] == '%' && format[index_format + 1] != '%')
		{
			ft_runner_spcf(&aux, &format[index_format], args);
			ft_check_format(&format[index_format], aux, &index_format);
			temp_middle_str = ft_strtilchr(&format[index_format + 1], '%');
			temp = ft_strjoin(aux, temp_middle_str);
			free(temp_middle_str);
			free(aux);
			aux = temp;
		}
		else if (format[index_format] == '%' && format[index_format + 1] == '%')
		{
			temp_ph = ft_strjoin(aux, "%");
			free(aux);
			index_format ++;
			temp_middle_str = ft_strtilchr(&format[index_format + 1], '%');
			temp = ft_strjoin(temp_ph, temp_middle_str);
			free(temp_middle_str);
			free(temp_ph);
			aux = temp;
		}
		index_format++;
	}
	return (aux);
}
// SOCORRO O QUE EU TÔ FAZENDO? D:
