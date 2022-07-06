/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/06 21:28:40 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	funcao_do_renan(t_str *str, t_flags flags, int *count)
{
	if (!(str->size == 1 && str->s[0] == '0'))
	{
		str->temp = ft_strjoin("0x", str->s);
		free(str->s);
		str->s = ft_strdup(str->temp);
		free(str->temp);
		if (flags.spcf == 'X')
			str->s = ft_strtoupper(str->s);
		str->size += 2;
		*count += 2;
	}
}

static void	handle_dot(t_str *str, t_flags *flags, int *count)
{
	if (flags->spcf != 's' && !ft_strchr(str->s, '-'))
	{
		while (flags->precision_value > str->size)
		{
			str->temp = ft_strjoin("0", str->s);
			free(str->s);
			str->s = ft_strdup(str->temp);
			free(str->temp);
			*count += 1;
			str->size += 1;
		}
	}
	else if (flags->spcf != 's' && ft_strchr(str->s, '-'))
	{
		if (flags->precision_value >= str->size)
		{
			while (flags->precision_value >= str->size)
			{
				str->temp = ft_strjoin("-0", &str->s[1]);
				free(str->s);
				str->s = ft_strdup(str->temp);
				free(str->temp);
				*count += 1;
				str->size += 1;
			}
		}
	}
	else if (flags->spcf == 's' && flags->precision_value < str->size)
	{
		if (flags->precision_value >= 1)
		{
			str->temp = ft_substr(str->s, 0, flags->precision_value);
			free(str->s);
			str->s = ft_strdup(str->temp);
			free(str->temp);
			*count -= str->size - flags->precision_value;
			str->size = flags->precision_value;
		}
		else
		{
			free(str->s);
			str->s = ft_strdup("");
			*count -= str->size;
			str->size = 0;
		}
	}
}

void	check_flags(t_str *str, t_flags flags, int *count)
{
	int		index;
	char	*aux;

	index = 0;
	if (flags.bool_plus && (flags.spcf == 'p'
			|| flags.spcf == 'd' || flags.spcf == 'i')
		&& !ft_strchr(str->s, '-'))
	{
		str->temp = ft_strjoin("+", str->s);
		free(str->s);
		str->s = ft_strdup(str->temp);
		free(str->temp);
		*count += 1;
		str->size += 1;
		flags.bool_space = FALSE;
	}
	if ((flags.spcf == 'p' && !ft_strnstr(str->s, "(nil)", 5))
		|| flags.bool_hash)
		funcao_do_renan(str, flags, count);
	if (flags.bool_space && (flags.spcf == 'p'
			|| flags.spcf == 'd' || flags.spcf == 'i')
		&& !ft_strchr(str->s, '-') && !ft_strchr(str->s, 'n'))
	{
		str->temp = ft_strjoin(" ", str->s);
		free(str->s);
		str->s = ft_strdup(str->temp);
		free(str->temp);
		str->size += 1;
		*count += 1;
	}
	if (flags.bool_dot && flags.spcf != 'c' && !ft_strnstr(str->s, "(nil)", 5))
		handle_dot(str, &flags, count);
	flags.width_value -= str->size;
	if (flags.width_value > 0)
	{		
		*count += flags.width_value;
		str->temp = (char *)malloc(sizeof(char) * flags.width_value);
		while (flags.width_value > index)
		{
			str->temp[index] = ' ';
			index++;
			str->size += 1;
		}
		aux = ft_strjoin(str->temp, str->s);
		free(str->temp);
		free(str->s);
		str->s = ft_strdup(aux);
		free(aux);
	}
}
