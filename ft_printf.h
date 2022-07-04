/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:14:45 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/04 17:34:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // APAGAR ESSA DISGRAMA!

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
	t_bool	bool_end;
	int		width_value;
	char	spcf;
}	t_flags;

typedef struct s_str
{
	int				size;
	char			*s;
}	t_str;

int		ft_printf(const char *format, ...);
void	*ft_strmemjoin(void *s1, void *s2, size_t size_s1, size_t size_s2);
t_str	handle_char(va_list args, int *count);
t_flags	ft_init_flags(const char *format_parsed);
t_bool	ft_isformat(char c, t_bool *width);

#endif
