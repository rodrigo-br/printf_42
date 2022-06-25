/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:14:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/25 02:28:44 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

t_bool	ft_widthon(t_bool width, char c)
{
	if (width == FALSE && c != '0' && ft_isdigit(c))
	{
		width = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_isformat(char c)
{
	if (c == '0'
		|| c == '-'
		|| c == '+'
		|| c == '.'
		|| c == ' '
		|| c == '#')
		return (TRUE);
	return (FALSE);
}
