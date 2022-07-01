/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:14:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 18:44:01 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_bool	ft_widthon(t_bool *width, char c)
{
	if (*width == FALSE && c != '0' && ft_isdigit(c))
	{
		*width = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
// PQ TU NÃO USOU O STRCHR, MANO?
t_bool	ft_isformat(char c, t_bool *width)
{
	if (*width == TRUE && ft_isdigit(c))
		*width = TRUE;
	else
		*width = FALSE;
	if (c == '0'
		|| c == '-'
		|| c == '+'
		|| c == '.'
		|| c == ' '
		|| c == '#'
		|| c == '%'
		|| ft_widthon(width, c)
		|| *width == TRUE)
		return (TRUE);
	return (FALSE);
}
