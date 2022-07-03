/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_placeholders.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:27:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/03 17:29:02 by ralves-b         ###   ########.fr       */
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
	int		index;
	char	*aux;
	char	*new_str;
	int		last_index;

	index = 0;
	aux = ft_strtilchr(format, '%');
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] != '%')
		{
			*count = doidera(&aux, format, args, &index);
			last_index = index + 1;
		}
		else if (format[index] == '%' && format[index + 1] == '%')
		{
			index = segunda_doidera(&aux, format, index);
			*count += 1;
			last_index = index + 1;
		}
		index++;
	}
	new_str = ft_strmemjoin(aux, (void *)&format[last_index], *count, ft_strlen(&format[last_index]));
	*count += ft_strlen(&format[last_index]);
	return (new_str);
}
// SOCORRO O QUE EU TÔ FAZENDO? D:
int	doidera(char **a, const char *format, va_list args, int *index)
{
	char	*temp;
	char	*temp_middle_str;
	int		size_count;

	size_count = *index;
	size_count = ft_runner_spcf(&a, &format[*index], args, size_count);
	size_count += ft_check_format(&format[*index], index);
	temp_middle_str = ft_strtilchr(&format[*index + 1], '%');
	temp = ft_strjoin(*a, temp_middle_str);
	free(temp_middle_str);
	free(*a);
	*a = temp;
	return (size_count);
}
// LARISSA TÁ BRIGANDO COMIGO
int segunda_doidera(char **a, const char *format, int index)
{
	char		*temp_ph;
	char		*temp;
	char		*temp_middle_str;
	const char	*ph = "%";

	temp_ph = ft_strjoin(*a, ph);
	index++;
	temp_middle_str = ft_strtilchr(&format[index + 1], '%');
	temp = ft_strjoin(temp_ph, temp_middle_str);
	free(*a);
	free(temp_middle_str);
	free(temp_ph);
	*a = temp;
	return (index);
}
