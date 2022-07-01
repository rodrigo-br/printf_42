/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 20:00:21 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*specifier_char(t_flags *flags, char **s, va_list args)
{
	char	new_str[2];
	
	if (flags->spcf == 'c')
	{
		new_str[0] = (char)va_arg(args, int);
		new_str[1] = '\0';
		*s = ft_strjoin(*s, new_str);
		flags->bool_end = TRUE;
		printf("enviou um char\n");
	}
	return (NULL);
}

char	*specifier_string(t_flags *flags, char **s, va_list args)
{	
	if (flags->spcf == 's')
	{
		*s = ft_strjoin(*s, va_arg(args, char *));
		flags->bool_end = TRUE;
		printf("enviou uma string\n");
	}
	return (NULL);
}

char	*specifier_decimal(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_2;

	if (flags->spcf == 'd')
	{
		temp_2 = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_2);
		free(*s);
		free(temp_2);
		*s = temp;
		flags->bool_end = TRUE;
		printf("enviou um decimal\n");
	}
	return (NULL);
}

char	*specifier_pointer(t_flags *flags, char **s, va_list args)
{
	unsigned long int	i;
	char				*temp_ox;
	char				*temp_hex;
	char				*temp_2;
	if (flags->spcf == 'p')
	{
		i = ft_ptoi(va_arg(args, void *));
		temp_hex = ft_itohex(i);
		temp_ox = ft_strjoin("0x", temp_hex);
		free(temp_hex);
		temp_2 = ft_strjoin(*s, temp_ox);
		free(*s);
		free(temp_ox);
		*s = temp_2;
		flags->bool_end = TRUE;
		printf("enviou um pointer\n");
	}
	return (NULL);
}

char	*specifier_integer(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_2;

	if (flags->spcf == 'i')
	{
		temp_2 = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_2);
		free(*s);
		free(temp_2);
		*s = temp;
		flags->bool_end = TRUE;
		printf("enviou um inteiro\n");
	}
	return (NULL);
}

char	*specifier_unsigned_decimal(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_itoa;

	if (flags->spcf == 'u')
	{
		temp_itoa = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_itoa);
		free(*s);
		free(temp_itoa);
		*s = temp;
		flags->bool_end = TRUE;
		printf("enviou um decimal unsigned\n");
	}
	return (NULL);
}

char	*specifier_lower_hexadecimal(t_flags *flags, char **s, va_list args)
{
	char	*temp_hex;
	char	*temp;

	if (flags->spcf == 'x')
	{
		temp_hex = ft_itohex(va_arg(args, int));
		temp = ft_strjoin(*s, temp_hex);
		free(temp_hex);
		free(*s);
		*s = temp;
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal minúsculo\n");
	}
	return (NULL);
}

char	*specifier_upper_hexadecimal(t_flags *flags, char **s, va_list args)
{
	char	*temp_hex;
	char	*temp;
	int		index;
	if (flags->spcf == 'X')
	{
		index = 0;
		temp_hex = ft_itohex(va_arg(args, int));
		temp = ft_strjoin(*s, ft_strtoupper(temp_hex));
		free(*s);
		free(temp_hex);
		*s = temp;
		flags->bool_end = TRUE;
		printf("enviou um hexadecimal maiúsculo\n");
	}
	return (NULL);
}

void	*ft_ite_spf(void *(*f)(t_flags*, char**, va_list),\
						t_flags *flags, char **s, va_list args)
{
	return (f(flags, s, args));
}
// Q Q CE TA FAZENDO, MANO?
int		ft_runner_spcf(char **s, const char *format_parsed, va_list args)
{
	t_flags		flags;
	int			index;
	void		**specifiers_caller;

	flags = ft_init_flags(format_parsed);
	specifiers_caller = ft_init_caller();
	index = 0;
	while (specifiers_caller[index] && !flags.bool_end)
		ft_ite_spf(specifiers_caller[index++], &flags, s, args);
	return (0);
}
// E agora, véi?