/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/26 18:14:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	*specifier_char(t_flags *flags, t_bool *end)
{
	t_bool	chr;

	(void) flags;
	chr = FALSE;
	if (chr && flags->bool_space)
	{
		*end = TRUE;
		printf("enviou um char\n");
	}
	return (NULL);
}

void	*specifier_string(t_flags *flags, t_bool *end)
{
	t_bool	str;

	(void) flags;
	str = FALSE;
	if (str)
	{
		*end = TRUE;
		printf("enviou uma string\n");
	}
	return (NULL);
}

void	*specifier_decimal(t_flags *flags, t_bool *end)
{
	t_bool	decimal;

	(void) flags;
	decimal = FALSE;
	if (decimal)
	{
		*end = TRUE;
		printf("enviou um decimal\n");
	}
	return (NULL);
}

void	*specifier_pointer(t_flags *flags, t_bool *end)
{
	t_bool	pointer;

	(void) flags;
	pointer = FALSE;
	if (pointer)
	{
		*end = TRUE;
		printf("enviou um pointer\n");
	}
	return (NULL);
}

void	*specifier_integer(t_flags *flags, t_bool *end)
{
	t_bool	integer;

	(void) flags;
	integer = FALSE;
	if (integer)
	{
		*end = TRUE;
		printf("enviou um inteiro\n");
	}
	return (NULL);
}

void	*specifier_unsigned_decimal(t_flags *flags, t_bool *end)
{
	t_bool	udecimal;

	(void) flags;
	udecimal = FALSE;
	if (udecimal)
	{
		*end = TRUE;
		printf("enviou um decimal unsigned\n");
	}
	return (NULL);
}

void	*specifier_lower_hexadecimal(t_flags *flags, t_bool *end)
{
	t_bool	l_hex;

	(void) flags;
	l_hex = FALSE;
	if (l_hex)
	{
		*end = TRUE;
		printf("enviou um hexadecimal minúsculo\n");
	}
	return (NULL);
}

void	*specifier_upper_hexadecimal(t_flags *flags, t_bool *end)
{
	t_bool	u_hex;

	(void) flags;
	u_hex = FALSE;
	if (u_hex)
	{
		*end = TRUE;
		printf("enviou um hexadecimal maiúsculo\n");
	}
	return (NULL);
}

void	*ft_ite_spf(void *(*f)(t_flags*, t_bool*), t_flags *flags, t_bool *end)
{
	return (f(flags, end));
}

int		ft_runner_spcf(void)
{
	t_flags		flags;
	t_bool		end;
	int			index;
	void		**specifiers_caller;

	end = FALSE;
	flags = ft_init_flags();
	specifiers_caller = ft_init_caller();
	index = 0;
	while (specifiers_caller[index] && !end)
		ft_ite_spf(specifiers_caller[index++], &flags, &end);
	return (0);
}
