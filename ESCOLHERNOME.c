/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/29 18:26:31 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	*specifier_char(t_flags *flags)
{
	t_bool	chr;

	chr = TRUE;
	if (chr)
	{
		flags->bool_end = TRUE;
		printf("enviou um char\n");
	}
	return (NULL);
}

void	*specifier_string(t_flags *flags)
{
	t_bool	str;

	str = TRUE;
	if (str)
	{
		flags->bool_end = TRUE;
		printf("enviou uma string\n");
	}
	return (NULL);
}

void	*specifier_decimal(t_flags *flags)
{
	t_bool	decimal;

	decimal = FALSE;
	if (decimal)
	{
		flags->bool_end = TRUE;
		printf("enviou um decimal\n");
	}
	return (NULL);
}

void	*specifier_pointer(t_flags *flags)
{
	t_bool	pointer;

	pointer = FALSE;
	if (pointer)
	{
		flags->bool_end = TRUE;
		printf("enviou um pointer\n");
	}
	return (NULL);
}

void	*specifier_integer(t_flags *flags)
{
	t_bool	integer;

	integer = FALSE;
	if (integer)
	{
		flags->bool_end = TRUE;
		printf("enviou um inteiro\n");
	}
	return (NULL);
}

void	*specifier_unsigned_decimal(t_flags *flags)
{
	t_bool	udecimal;

	udecimal = FALSE;
	if (udecimal)
	{
		flags->bool_end = TRUE;
		printf("enviou um decimal unsigned\n");
	}
	return (NULL);
}

void	*specifier_lower_hexadecimal(t_flags *flags)
{
	t_bool	l_hex;

	l_hex = FALSE;
	if (l_hex)
	{
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal minúsculo\n");
	}
	return (NULL);
}

void	*specifier_upper_hexadecimal(t_flags *flags)
{
	t_bool	u_hex;

	u_hex = FALSE;
	if (u_hex)
	{
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal maiúsculo\n");
	}
	return (NULL);
}

void	*ft_ite_spf(void *(*f)(t_flags*), t_flags *flags)
{
	return (f(flags));
}

int		ft_runner_spcf(void)
{
	t_flags		flags;
	int			index;
	void		**specifiers_caller;

	flags = ft_init_flags();
	specifiers_caller = ft_init_caller();
	index = 0;
	while (specifiers_caller[index] && !flags.bool_end)
		ft_ite_spf(specifiers_caller[index++], &flags);
	return (0);
}
