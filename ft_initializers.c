/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/30 16:01:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_turn_false(t_flags *flags)
{
	flags->bool_space = FALSE;
	flags->bool_zero = FALSE;
	flags->bool_hash = FALSE;
	flags->bool_dot = FALSE;
	flags->bool_minus = FALSE;
	flags->bool_plus = FALSE;
	flags->bool_end = FALSE;
}

t_flags	ft_init_flags(const char *format_parsed)
{
	t_flags	flags;
	t_bool	width_bool;
	int		index;

	ft_turn_false(&flags);
	width_bool = FALSE;
	index = -1;
	while (ft_isformat(format_parsed[++index], &width_bool))
	{
		if (format_parsed[index] == ' ')
			flags.bool_space = TRUE;
		if (format_parsed[index] == '0')
			flags.bool_zero = TRUE;
		if (format_parsed[index] == '#')
			flags.bool_hash = TRUE;
		if (format_parsed[index] == '.')
			flags.bool_dot = TRUE;
		if (format_parsed[index] == '-')
			flags.bool_minus = TRUE;
		if (format_parsed[index] == '+')
			flags.bool_plus = TRUE;
	}
	flags.spcf = format_parsed[index];
	return (flags);
}

void	**ft_init_caller(void)
{
	void	**specifiers_caller;
	int		index;

	index = 0;
	specifiers_caller = malloc(sizeof(&specifier_char) * 9);
	while (index < 9)
	{
		specifiers_caller[index] = malloc(sizeof(&specifier_char));
		index++;
	}
	specifiers_caller[0] = specifier_char;
	specifiers_caller[1] = specifier_string;
	specifiers_caller[2] = specifier_decimal;
	specifiers_caller[3] = specifier_pointer;
	specifiers_caller[4] = specifier_integer;
	specifiers_caller[5] = specifier_unsigned_decimal;
	specifiers_caller[6] = specifier_lower_hexadecimal;
	specifiers_caller[7] = specifier_upper_hexadecimal;
	specifiers_caller[8] = 0;
	return (specifiers_caller);
}
