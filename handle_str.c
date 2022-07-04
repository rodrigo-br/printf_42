/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/04 20:03:49 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	handle_str(va_list args, int *count)
{
	t_str	str;
	char	*temp;
	
	temp = va_arg(args, char *);
	str.s = ft_strdup(temp);
	str.size = ft_strlen(temp);
	*count += str.size;
	return (str);
}
