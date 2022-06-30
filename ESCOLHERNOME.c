/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/30 04:38:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	*specifier_char(t_flags *flags)
{
	if (flags->spfc == 'c')
	{
		flags->bool_end = TRUE;
		printf("enviou um char\n");
	}
	return (NULL);
}

char	*specifier_string(t_flags *flags)
{
	if (flags->spfc == 's')
	{
		flags->bool_end = TRUE;
		printf("enviou uma string\n");
	}
	return (NULL);
}

void	*specifier_decimal(t_flags *flags)
{
	if (flags->spfc == 'd')
	{
		flags->bool_end = TRUE;
		printf("enviou um decimal\n");
	}
	return (NULL);
}

void	*specifier_pointer(t_flags *flags)
{
	if (flags->spfc == 'p')
	{
		flags->bool_end = TRUE;
		printf("enviou um pointer\n");
	}
	return (NULL);
}

void	*specifier_integer(t_flags *flags)
{
	if (flags->spfc == 'i')
	{
		flags->bool_end = TRUE;
		printf("enviou um inteiro\n");
	}
	return (NULL);
}

void	*specifier_unsigned_decimal(t_flags *flags)
{
	if (flags->spfc == 'u')
	{
		flags->bool_end = TRUE;
		printf("enviou um decimal unsigned\n");
	}
	return (NULL);
}

void	*specifier_lower_hexadecimal(t_flags *flags)
{
	if (flags->spfc == 'x')
	{
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal minúsculo\n");
	}
	return (NULL);
}

void	*specifier_upper_hexadecimal(t_flags *flags)
{
	if (flags->spfc == 'X')
	{
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal maiúsculo\n");
	}
	return (NULL);
}

void	*ft_ite_spf(void *(*f)(t_flags*), t_flags *flags, char *s,\
						char *format_parsed, va_list args)
{
	return (f(flags, s, format_parsed, args));
}
// Q Q CE TA FAZENDO, MANO?
int		ft_runner_spcf(char *s, char *format_parsed, va_list args)
{
	t_flags		flags;
	int			index;
	void		**specifiers_caller;

	flags = ft_init_flags(format_parsed);
	specifiers_caller = ft_init_caller();
	index = 0;
	while (specifiers_caller[index] && !flags.bool_end)
		ft_ite_spf(specifiers_caller[index++], &flags, s, format_parsed, args);
	return (0);
}
// E agora, véi?