/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/06 18:55:36 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	funcao_do_renan(t_str *str, t_flags flags, int *count)
{
	char	estranho[2];

	if (!(str->size == 1 && str->s[0] == '0'))
	{
		estranho[0] = '0';
		if (flags.spcf == 'X')
			estranho[1] = 'X';
		else
			estranho[1] = 'x';
		write(1, estranho, 2);
		*count += 2;
	}
}
// static void	handle_width(t_str *str, t_flags *flags, int *count)
// {
// }

static void	handle_dot(t_str *str, t_flags *flags, int *count)
{
	char	*temp;

	if (flags->spcf != 's' && !ft_strchr(str->s, '-'))
	{
		while (flags->precision_value > str->size)
		{
			write(1, "0", 1);
			*count += 1;
			flags->precision_value -= 1;
		}
	}
	else if (flags->spcf != 's' && ft_strchr(str->s, '-'))
	{
		if (flags->precision_value >= str->size)
		{
			temp = ft_substr(str->s, 1, str->size - 1);
			free(str->s);
			str->s = ft_strdup(temp);
			free(temp);
			write(1, "-", 1);
			while (flags->precision_value >= str->size)
			{
				write(1, "0", 1);
				*count += 1;
				flags->precision_value -= 1;
			}
			str->size -= 1;
		}
	}
	else if (flags->spcf == 's' && flags->precision_value < str->size)
	{
		if (flags->precision_value >= 1)
		{
			temp = ft_substr(str->s, 0, flags->precision_value);
			free(str->s);
			str->s = ft_strdup(temp);
			free(temp);
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
	flags.width_value -= str->size;
	if (flags.bool_plus && (flags.spcf == 'p'
			|| flags.spcf == 'd' || flags.spcf == 'i')
		&& !ft_strchr(str->s, '-'))
	{
		write(1, "+", 1);
		*count += 1;
		flags.bool_space = FALSE;
	}
	else if (flags.bool_space && (flags.spcf == 'p'
			|| flags.spcf == 'd' || flags.spcf == 'i')
		&& !ft_strchr(str->s, '-') && !ft_strchr(str->s, 'n'))
	{
		write(1, " ", 1);//falta implementar o width!
		*count += 1;
	}
	if ((flags.spcf == 'p' && !ft_strnstr(str->s, "(nil)", 5))
		|| flags.bool_hash)
		funcao_do_renan(str, flags, count);
	if (flags.bool_dot && flags.spcf != 'c' && !ft_strnstr(str->s, "(nil)", 5))
		handle_dot(str, &flags, count);
}
