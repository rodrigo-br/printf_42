/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:53:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/05 05:09:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	handle_hex(va_list args, int *count, char c)
{
	t_str	str;
	int		temp;

	temp = va_arg(args, int);
	str.s = ft_itohex(temp);
	str.size = ft_strlen(str.s);
	*count += str.size;
	if (c == 'X')
		str.s = ft_strtoupper(str.s);
	return (str);
}
