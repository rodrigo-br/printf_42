/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:25:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/29 21:54:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_count_hex_size(unsigned long int nb)
{
	size_t	counter;

	counter = 1;
	while (nb >= 16)
	{
		nb /= 16;
		counter++;
	}
	return (counter);
}

char	*ft_itohex(unsigned	long int nb)
{
	const char	*hexmap = "0123456789abcdef";
	char		*new_str;
	size_t		size_hex;

	size_hex = ft_count_hex_size(nb);
	new_str = (char *)malloc(sizeof(char) * (size_hex + 1));
	new_str[size_hex] = '\0';
	while (size_hex--)
	{
		new_str[size_hex] = hexmap[nb % 16];
		nb /= 16;
	}
	return (new_str);
}
