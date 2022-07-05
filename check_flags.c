/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/05 21:25:00 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_width(t_str *str, t_flags flags, int *count)
{
	char	*new_str;

	if (flags.spcf == 'p' || flags.bool_hash)
		(flags).width_value -= 2;
	while((flags).width_value > str->size)
	{
		if (flags.bool_zero && !flags.bool_minus
&& flags.spcf != 'c' && flags.spcf != 's')
			new_str = ft_strjoin("0", str->s);
		else
			new_str = ft_strjoin(" ", str->s);
		free(str->s);
		str->s = ft_strdup(new_str);
		free(new_str);
		str->size += 1;
		*count += 1;
	}
}

void	check_flags(t_str *str, t_flags flags, int *count)
{
	if (flags.spcf == 'p' || flags.bool_hash)
	{
		write(1, "0x", 2);
		*count += 2;
	}
	if (flags.width_value > str->size && flags.spcf != '%')
		handle_width(str, flags, count);
}
