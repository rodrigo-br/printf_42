/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:14:45 by ralves-b          #+#    #+#             */
/*   Updated: 2022/06/26 14:30:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_flags
{
	t_bool	bool_space;
	t_bool	bool_zero;
	t_bool	bool_hash;
	t_bool	bool_dot;
	t_bool	bool_minus;
	t_bool	bool_plus;
	t_bool	bool_width;
}	t_flags;

int		ft_printf(const char *format, ...);
t_bool	ft_isspecifiers(char c);
t_bool	ft_widthon(t_bool width, char c);
int		ft_runner_spcf(void);

//----------------------INÍCIO DA DOIDERA DA MINHA CABEÇA------------------- //
// ----------------- VAI DAR CERTO SEUS DESCRENTE MALDITO -------------------//

void	*placeholder_char(void);
void	*placeholder_string(void);
void	*placeholder_decimal(void);
void	*placeholder_pointer(void);
void	*placeholder_integer(void);
void	*placeholder_unsigned_decimal(void);
void	*placeholder_lower_hexadecimal(void);
void	*placeholder_upper_hexadecimal(void);
void	*pick_placeholder(void *(*f)(void));

//--------------- FIM DA DOIDERA DA MINHA CABEÇA -------------------------- //

#endif
