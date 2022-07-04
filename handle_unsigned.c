/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:26:01 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/04 19:32:56 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	handle_unsigned(va_list args, int *count)
{
	t_str			n;

	n.s = ft_uitoa(va_arg(args, int));
	n.size = ft_strlen(n.s);
	*count += n.size;
	return (n);
}