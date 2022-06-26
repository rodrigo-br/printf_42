/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_placeholders.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:27:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/26 14:45:42 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_check_format(char *format, char *new_str, int *i)
{
	t_bool	width_bool;
	int		width_value;
	int		index[1];

	(void) new_str;
	width_bool = FALSE;
	width_value = 0;
	*index = 1;
	if (ft_widthon(width_bool, format[*index]))
	{
		while (ft_isdigit(format[*index]))
		{
			width_value = width_value * 10 + (format[*index] - '0');
			*index = *index + 1;
		}
	}
	*i = *i + *index;
}

char	*ft_count_placeholders(char *format)
{
	int		index_format;
	int		index_aux;
	char	*new_str;
	char	*aux;

	aux = (char *)malloc(sizeof(char) * ft_strlen(format) + 1);
	index_format = 0;
	index_aux = 0;
	while (format[index_format])
	{
		if (format[index_format] == '%')
			ft_check_format(&format[index_format], aux, &index_format);
		aux[index_aux] = format[index_format];
		index_format++;
		index_aux++;
	}
	aux[index_aux] = '\0';
	new_str = ft_strdup(aux);
	free(aux);
	return (new_str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_count_placeholders("caval%200inho"));
// 	return (0);
// }
