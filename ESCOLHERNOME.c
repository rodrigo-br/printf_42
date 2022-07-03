/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ESCOLHERNOME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:48:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/03 16:50:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	specifier_char(t_flags *flags, char **s, va_list args, int size_count)
{
	char	new_str[1];
	char	*temp;

	(void)size_count;
	if (flags->spcf == 'c' && !flags->bool_end)
	{
		new_str[0] = (char)va_arg(args, int);
		temp = ft_strmemjoin(*s, new_str, size_count, 1);
		*s = temp;
		flags->bool_end = TRUE;
		return (1);
	}
	return (0);
}

int	specifier_string(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp;
	char	*new_str;
	size_t	size_new_str;

	if (flags->spcf == 's' && !flags->bool_end)
	{
		new_str = va_arg(args, char *);
		size_new_str = ft_strlen(new_str);
		temp = ft_strmemjoin(*s, new_str, size_count, size_new_str);
		*s = temp;
		flags->bool_end = TRUE;
		return (size_new_str);
	}
	return (0);
}

int	specifier_decimal(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp;
	char	*temp_2;
	(void)size_count;
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

int	specifier_pointer(t_flags *flags, char **s, va_list args, int size_count)
{
	unsigned long int	i;
	char				*temp_ox;
	char				*temp_hex;
	char				*temp_2;
	(void)size_count;
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

int	specifier_integer(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp;
	char	*temp_2;
	(void)size_count;
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

int	specifier_unsigned_decimal(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp;
	char	*temp_itoa;
	(void)size_count;
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

int	specifier_lower_hexadecimal(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp_hex;
	char	*temp;
	(void)size_count;
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

int	specifier_upper_hexadecimal(t_flags *flags, char **s, va_list args, int size_count)
{
	char	*temp_hex;
	char	*temp;
	int		index;
	(void)size_count;
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

// Q Q CE TA FAZENDO, MANO?
int	ft_runner_spcf(char ***s, const char *format_parsed, va_list args, int size_count)
{
	t_flags		flags;

	flags = ft_init_flags(format_parsed);
	size_count += specifier_char(&flags, *s, args, size_count);
	size_count += specifier_string(&flags, *s, args, size_count);
	size_count += specifier_decimal(&flags, *s, args, size_count);
	size_count += specifier_pointer(&flags, *s, args, size_count);
	size_count += specifier_integer(&flags, *s, args, size_count);
	size_count += specifier_unsigned_decimal(&flags, *s, args, size_count);
	size_count += specifier_lower_hexadecimal(&flags, *s, args, size_count);
	size_count += specifier_upper_hexadecimal(&flags, *s, args, size_count);
	return (size_count);
}
// E agora, véi?