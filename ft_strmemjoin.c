/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmemjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:34:04 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/03 16:52:56 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_strmemjoin(void *s1, void *s2, size_t size_s1, size_t size_s2)
{
	unsigned char	*aux_s2;
	unsigned char	*new_str;

	aux_s2 = (unsigned char *)s2;
	new_str = (unsigned char *)ft_calloc(sizeof(char), (size_s1 + size_s2 + 1));
	ft_memcpy(new_str, s1, size_s1);
	ft_memcpy(new_str + size_s1, aux_s2, size_s2);
	free(s1);
	return (new_str);
}
// cavalinho, 0,  ao vento, 0