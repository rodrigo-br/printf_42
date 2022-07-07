/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/07 06:32:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	funcao_do_renan(t_str *str, t_flags *flags, int *count)
{
	if (!(str->size == 1 && str->s[0] == '0')
		&& !(flags->spcf == 'p' && ft_strnstr(str->s, "(nil)", str->size)))
	{
		str->temp = ft_strjoin("0x", str->s);
		free(str->s);
		str->s = ft_strdup(str->temp);
		free(str->temp);
		if (flags->spcf == 'X')
			str->s = ft_strtoupper(str->s);
		str->size += 2;
		*count += 2;
	}
	else
		flags->null = TRUE;
}

static void	handle_dot(t_str *str, t_flags *flags, int *count)
{	
	// handle_dot_numerals_no_signals
	if (flags->spcf != 's' && !ft_strchr(str->s, '-')
		&& !ft_strchr(str->s, '+'))
	{
		if (flags->bool_hash)
			flags->precision_value += 2;
		while (flags->precision_value > str->size)
		{
			str->temp = ft_strjoin("0", str->s);
			free(str->s);
			str->s = ft_strdup(str->temp);
			free(str->temp);
			*count += 1;
			str->size += 1;
		}
		if (flags->bool_hash)
		{
			str->s[1] = flags->spcf;
			if (flags->spcf == 'p')
				str->s[1] = 'x';
			str->s[flags->precision_value - 2] = '0';
		}
	}
	// handle_dot_numerals_with_signals
	else if (flags->spcf != 's' && (ft_strchr(str->s, '-')
			|| ft_strchr(str->s, '+')))
	{
		if (flags->precision_value >= str->size)
		{
			while (flags->precision_value >= str->size)
			{
				str->temp = ft_strjoin("-0", &str->s[1]);
				if (ft_strchr(str->s, '+'))
					str->temp[0] = '+';
				free(str->s);
				str->s = ft_strdup(str->temp);
				free(str->temp);
				*count += 1;
				str->size += 1;
			}
		}
	}
	// handle_dot_numerals_exceptions_nulls
	if (flags->spcf != 's' && flags->spcf != 'c' && flags->spcf != 'p'
		&& str->size == 1 && str->s[0] == '0')
	{
		*count -= 1;
		str->size = 0;
	}
	// handle_dot_strings
	if (flags->spcf == 's' && flags->precision_value < str->size)
	{
		// handle_dot_valid_strings
		if (!flags->null)
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
		// handle_dot_null_strings
		else
		{
			if (flags->precision_value < 6)
			{
				*count -= str->size;
				str->size = 0;
			}
			else
			{
				str->size = 0;
				write(1, "(null)", 6);
			}
		}
	}
}

void	check_flags(t_str *str, t_flags flags, int *count)
{
	int		index;

	index = 0;
	// handle_plus
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
	// handle_sharp
	if (((flags.spcf == 'x' || flags.spcf == 'X') && flags.bool_hash)
		|| flags.spcf == 'p')
		funcao_do_renan(str, &flags, count);
	// handle_dot
	if (flags.bool_dot && flags.spcf != 'c')
		handle_dot(str, &flags, count);
	flags.width_value -= str->size;
	// handle_width
	if (flags.width_value > 0 && !flags.bool_minus)
	{		
		*count += flags.width_value;
		while (flags.width_value > index)
		{
			str->temp = ft_strjoin(" ", str->s);
			free(str->s);
			str->s = ft_strdup(str->temp);
			free(str->temp);
			index++;
			str->size += 1;
		}
	}
	// handle_zero
	if (flags.bool_zero && !flags.bool_minus && flags.width_value > 0
		&& flags.spcf != 's' && flags.spcf != 'c' && !flags.bool_dot)
	{
		index = 0;
		// handle_zero_settling
		while (flags.width_value > index)
		{
			str->s[index] = '0';
			index++;
		}
		// handle_zero_and_0x_cases
		if (((flags.spcf == 'x' || flags.spcf == 'X') && flags.bool_hash
				&& !flags.null) || (flags.spcf == 'p' && !flags.null))
		{
			str->s[1] = 'x';
			str->s[flags.width_value + 1] = '0';
			if (flags.spcf == 'X')
				str->s[1] = 'X';
		}
		// handle_zero_and_signals
		if ((flags.spcf == 'd' || flags.spcf == 'i') && (ft_strchr(str->s, '-')
			|| ft_strchr(str->s, '+')))
		{
			str->s[0] = '-';
			if (ft_strchr(str->s, '+'))
				str->s[0] = '+';
			str->s[flags.width_value] = '0';
		}
	}
	// handle_minus_without_c
	if (flags.bool_minus && flags.width_value > 0 && flags.spcf != 'c')
	{
		index = 0;
		*count += flags.width_value;
		while (flags.width_value > index)
		{
			str->temp = ft_strjoin(str->s, " ");
			free(str->s);
			str->s = ft_strdup(str->temp);
			free(str->temp);
			index++;
			str->size += 1;
		}
	}
	// handle_space
	if (flags.bool_space && (flags.spcf == 'p'
			|| flags.spcf == 'd' || flags.spcf == 'i')
		&& !ft_strchr(str->s, '-') && !ft_strchr(str->s, 'n')
		&& flags.spcf != 'c')
	{
		str->temp = ft_strjoin(" ", str->s);
		free(str->s);
		str->s = ft_strdup(str->temp);
		free(str->temp);
		str->size += 1;
		*count += 1;
	}
	// handle_minus_with_c
	if (flags.bool_minus && flags.width_value > 0 && flags.spcf == 'c')
	{
		index = 0;
		*count += flags.width_value;
		str->size = 0;
		write(1, str->s, 1);
		while (flags.width_value > index)
		{
			write(1, " ", 1);
			index++;
		}
	}
	// handle_dit_with_null_exceptions
	if (flags.spcf != 's' && flags.spcf != 'p' && flags.null
		&& flags.bool_dot && flags.precision_value < 1)
		str->s[0] = ' ';
	if (flags.bool_zero && flags.bool_dot && flags.null
		&& flags.width_value == 1 && flags.precision_value == 1)
		str->s[0] = '0';
}
