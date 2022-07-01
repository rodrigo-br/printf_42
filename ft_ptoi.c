/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:16:08 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 18:44:13 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// NÃO ESQUECER DE ESCREVER '0x' ANTES DO RESULTADO
unsigned long int	ft_ptoi(void *pointer)
{
	return ((unsigned long int)pointer);
}
