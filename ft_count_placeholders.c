/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_placeholders.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:27:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/03 14:18:09 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_check_format(const char *format, int *i)
{
	t_bool	width_bool;
	int		width_value;
	int		index[1];

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
		}
		*index = *index + 1;
	}
	*i = *i + *index;
	return (0);
}

char	*ft_count_placeholders(const char *format, va_list args, int *count)
{
	int		index_format;
	char	*aux;

	index_format = 0;
	aux = ft_strtilchr(format, '%');
	while (format[index_format])
	{
		if (format[index_format] == '%' && format[index_format + 1] != '%')
			*count += doidera(&aux, format, args, &index_format);
		else if (format[index_format] == '%' && format[index_format + 1] == '%')
		{
			index_format = segunda_doidera(&aux, format, index_format);
			*count++;
		}
		index_format++;
	}
	return (aux);
}
// SOCORRO O QUE EU TÔ FAZENDO? D:
int	doidera(char **a, const char *format, va_list args, int *index_format)
{
	char	*temp;
	char	*temp_middle_str;
	int		count;
	count = ft_runner_spcf(&a, &format[*index_format], args);
	count += ft_check_format(&format[*index_format], index_format);
	temp_middle_str = ft_strtilchr(&format[*index_format + 1], '%');
	temp = ft_strjoin(*a, temp_middle_str);
	free(temp_middle_str);
	free(*a);
	*a = temp;
	return (count);
}
// LARISSA TÁ BRIGANDO COMIGO
int segunda_doidera(char **a, const char *format, int index_format)
{
	char		*temp_ph;
	char		*temp;
	char		*temp_middle_str;
	const char	*ph = "%";
	
	temp_ph = ft_strjoin(*a, ph);
	index_format++;
	temp_middle_str = ft_strtilchr(&format[index_format + 1], '%');
	temp = ft_strjoin(temp_ph, temp_middle_str);
	free(*a);
	free(temp_middle_str);
	free(temp_ph);
	*a = temp;
	return (index_format);
}
