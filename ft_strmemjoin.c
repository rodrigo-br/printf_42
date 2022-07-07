/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmemjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:34:04 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/07 02:30:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_strmemjoin(void *s1, void *s2, size_t size_s1, size_t size_s2)
{
	unsigned char	*aux_s2;
	unsigned char	*aux_s1;
	unsigned char	*new_str;

	aux_s2 = (unsigned char *)s2;
	aux_s1 = (unsigned char *)s1;
	new_str = (unsigned char *)malloc(sizeof(char) * (size_s1 + size_s2));
	ft_memmove(new_str, aux_s1, size_s1);
	ft_memmove(&new_str[size_s1], aux_s2, size_s2);
	return (new_str);
}
