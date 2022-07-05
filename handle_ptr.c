/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:09:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/04 22:12:43 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	handle_ptr(va_list args, int *count)
{
	unsigned long int	ptr;
	t_str				str;
	char				*temp;
	void				*void_tmp;

	void_tmp = va_arg(args, void *);
	ptr = ft_ptoi(void_tmp);
	if (ptr == 0)
	{
		str.s = ft_strdup("(nil)");
		str.size = 5;
	}
	else
	{
		temp = ft_uitohex(ptr);
		str.s = ft_strmemjoin("0x", temp, 2, ft_strlen(temp));
		str.size = ft_strlen(str.s);
		free(temp);
	}
	*count += str.size;
	return (str);
}
