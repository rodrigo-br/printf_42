/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/06 02:32:49 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	funcao_do_renan(t_str *str, t_flags flags, int *count)
{
	char	estranho[2];

	if (!(str->size == 1 && str->s[0] == '0'))
	{
		estranho[0] = '0';
		if (flags.spcf == 'X')
			estranho[1] = 'X';
		else
			estranho[1] = 'x';
		write(1, estranho, 2);
		*count += 2;
	}
}
// static void	handle_width(t_str *str, t_flags *flags, int *count)
// {

// }

void	check_flags(t_str *str, t_flags flags, int *count)
{
	flags.width_value -= str->size;

	if ((flags.spcf == 'p' && !ft_strnstr(str->s, "(nil)", 5)) \
		|| flags.bool_hash)
		funcao_do_renan(str, flags, count);
}
