/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/02 18:02:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	specifier_char(t_flags *flags, char **s, va_list args)
{
	char	*new_str;
	char	*temp;
	int		count;

	count = 0;
	if (flags->spcf == 'c' && !flags->bool_end)
	{
		new_str = (char *)malloc(sizeof(char) * 2);
		new_str[0] = (char)va_arg(args, int);
		if (new_str[0] == 0)
			count = 1;
		new_str[1] = '\0';
		temp = ft_strjoin(*s, new_str);
		free(*s);
		free(new_str);
		*s = temp;
		flags->bool_end = TRUE;
	}
	return (count);
}

int	specifier_string(t_flags *flags, char **s, va_list args)
{
	char	*temp;

	if (flags->spcf == 's' && !flags->bool_end)
	{
		temp = ft_strjoin(*s, va_arg(args, char *));
		free(*s);
		*s = temp;
		flags->bool_end = TRUE;
		
	}
	return (0);
}

int	specifier_decimal(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_2;

	if (flags->spcf == 'd' && !flags->bool_end)
	{
		temp_2 = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_2);
		free(*s);
		free(temp_2);
		*s = temp;
		flags->bool_end = TRUE;
	}
	return (0);
}

int	specifier_pointer(t_flags *flags, char **s, va_list args)
{
	unsigned long int	i;
	char				*temp_ox;
	char				*temp_hex;
	char				*temp_2;
	if (flags->spcf == 'p' && !flags->bool_end)
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
		
	}
	return (0);
}

int	specifier_integer(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_2;

	if (flags->spcf == 'i' && !flags->bool_end)
	{
		temp_2 = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_2);
		free(*s);
		free(temp_2);
		*s = temp;
		flags->bool_end = TRUE;
		
	}
	return (0);
}

int	specifier_unsigned_decimal(t_flags *flags, char **s, va_list args)
{
	char	*temp;
	char	*temp_itoa;

	if (flags->spcf == 'u' && !flags->bool_end)
	{
		temp_itoa = ft_itoa(va_arg(args, int));
		temp = ft_strjoin(*s, temp_itoa);
		free(*s);
		free(temp_itoa);
		*s = temp;
		flags->bool_end = TRUE;
	}
	return (0);
}

int	specifier_lower_hexadecimal(t_flags *flags, char **s, va_list args)
{
	char	*temp_hex;
	char	*temp;

	if (flags->spcf == 'x' && !flags->bool_end)
	{
		temp_hex = ft_itohex(va_arg(args, int));
		temp = ft_strjoin(*s, temp_hex);
		free(temp_hex);
		free(*s);
		*s = temp;
		flags->bool_end = TRUE;
	}
	return (0);
}

int	specifier_upper_hexadecimal(t_flags *flags, char **s, va_list args)
{
	char	*temp_hex;
	char	*temp;
	int		index;
	if (flags->spcf == 'X' && !flags->bool_end)
	{
		index = 0;
		temp_hex = ft_itohex(va_arg(args, int));
		temp = ft_strjoin(*s, ft_strtoupper(temp_hex));
		free(*s);
		free(temp_hex);
		*s = temp;
		flags->bool_end = TRUE;
	}
	return (0);
}

// void	*ft_ite_spf(void *(*f)(t_flags*, char**, va_list),\
// 						t_flags *flags, char **s, va_list args)
// {
// 	return (f(flags, s, args));
// }
// Q Q CE TA FAZENDO, MANO?
int	ft_runner_spcf(char ***s, const char *format_parsed, va_list args)
{
	t_flags		flags;
	int			count;

	count = 0;
	flags = ft_init_flags(format_parsed);
	count += specifier_char(&flags, *s, args);
	count += specifier_string(&flags, *s, args);
	count += specifier_decimal(&flags, *s, args);
	count += specifier_pointer(&flags, *s, args);
	count += specifier_integer(&flags, *s, args);
	count += specifier_unsigned_decimal(&flags, *s, args);
	count += specifier_lower_hexadecimal(&flags, *s, args);
	count += specifier_upper_hexadecimal(&flags, *s, args);
	return (count);
}
// E agora, véi?