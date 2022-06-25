/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:55:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/25 02:31:52 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	printf("%s\n", format);
	printf("%s\n", va_arg(args, char *));
	printf("%s\n", va_arg(args, char *));
	printf("%d\n", va_arg(args, int));
	printf("%f\n", va_arg(args, double));
	va_end(args);
}

// int	main(void)
// {
// 	ft_printf("this is the format", "first arg", "second arg", 10, 10.5);
// }
