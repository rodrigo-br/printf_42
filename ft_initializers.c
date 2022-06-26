/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/26 18:11:17 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;
	
	flags.bool_space = FALSE;
	flags.bool_zero = FALSE;
	flags.bool_hash = FALSE;
	flags.bool_dot = FALSE;
	flags.bool_minus = FALSE;
	flags.bool_plus = FALSE;

	return (flags);
}

void **ft_init_caller(void)
{
	void	**specifiers_caller;
	
	specifiers_caller = (void **)malloc(9);
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