/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:14:45 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/07 01:42:23 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*--------------------------------------------------------------------------\
|					LIBRARY INCLUDES										|
\--------------------------------------------------------------------------*/
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <limits.h> // APAGAR ESSA DISGRAMA!
# include <stdio.h> // APAGAR ESSA AQUI TAMBÉM!

/*--------------------------------------------------------------------------\
|					TYPEDEF DECLARATIONS									|
\--------------------------------------------------------------------------*/
typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_flags
{
	int		precision_value;
	int		width_value;
	t_bool	bool_minus;
	t_bool	bool_space;
	t_bool	bool_zero;
	t_bool	bool_hash;
	t_bool	bool_plus;
	t_bool	bool_dot;
	t_bool	bool_end;
	t_bool	null;
	char	spcf;
}	t_flags;

typedef struct s_str
{
	int				size;
	char			*s;
	char			*temp;
}	t_str;

/*--------------------------------------------------------------------------\
|					NEW LIBFT FUNCTIONS										|
\--------------------------------------------------------------------------*/
void				*ft_strmemjoin(void *s1, void *s2, size_t size_s1, \
size_t size_s2);
char				*ft_strtilchr(const char *s, int c);
int					ft_printf(const char *format, ...);
char				*ft_uitohex(unsigned long int nb);
char				*ft_itohex(unsigned int nb);
char				*ft_uitoa(unsigned int n);
char				*ft_strtoupper(char *s);
unsigned long int	ft_ptoi(void *pointer);
/*--------------------------------------------------------------------------\
|					PRINTFT AUX FUNCTIONS									|
\--------------------------------------------------------------------------*/
t_flags				ft_init_flags(const char *format_parsed);
t_bool				ft_isformat(char c, t_bool *width);
/*--------------------------------------------------------------------------\
|					SPECIFIERS HANDLERS										|
\--------------------------------------------------------------------------*/
t_str				handle_hex(va_list args, int *count, char c);
t_str				handle_unsigned(va_list args, int *count);
t_str				handle_char(va_list args, int *count);
t_str				handle_str(va_list args, int *count);
t_str				handle_ptr(va_list args, int *count);
t_str				handle_n(va_list args, int *count);
t_str				handle_ph(int *count);
/*--------------------------------------------------------------------------\
|					FLAGS HANDLERS											|
\--------------------------------------------------------------------------*/
void				check_flags(t_str *str, t_flags flags, int *count);

#endif
