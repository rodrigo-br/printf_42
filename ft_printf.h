/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:14:45 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/01 20:31:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // APAGAR ESSA DISGRAMA!

/**
 * @brief 'Boolean expression' to turn switches on and off
 * 
 */
typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

/**
 * @brief switches to be turned on and off
 * 
 */
typedef struct s_flags
{
	t_bool	bool_space;
	t_bool	bool_zero;
	t_bool	bool_hash;
	t_bool	bool_dot;
	t_bool	bool_minus;
	t_bool	bool_plus;
	t_bool	bool_end;
	char	spcf;
}	t_flags;

/**
 * @brief at file ft_printf.c
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int		ft_printf(const char *format, ...);

/**
 * @brief at file ft_isspecifiers.c
 * 
 * @param c 
 * @return t_bool 
 */
t_bool	ft_isspecifiers(char c);

/**
 * @brief at file ft_isformat.c
 * 
 * @param width 
 * @param c 
 * @return t_bool 
 */
t_bool	ft_widthon(t_bool *width, char c);

/**
 * @brief at file ft_isformat.c
 * 
 * @param c 
 * @return t_bool 
 */
t_bool	ft_isformat(char c, t_bool *width);

/**
 * @brief at file ESCOLHERNOME.c
 * 
 * @return int 
 */
int		ft_runner_spcf(char **s, const char *format_parsed, va_list args);

/**
 * @brief at file ft_count_placeholders.c
 * 
 * @param format 
 * @param new_str 
 * @param i 
 */
void	ft_check_format(const char *format, char *new_str, int *i);

/**
 * @brief at file ft_count_placeholders.c
 * 
 * @param format 
 * @return char* 
 */
char	*ft_count_placeholders(const char *format, va_list args);

/**
 * @brief at file ft_initializers.c
 * 
 */
t_flags	ft_init_flags(const char *format_parsed);

/**
 * @brief at file ft_initializers.c
 * 
 * @return void* 
 */
void	**ft_init_caller(void);

/**
 * @brief at ft_initializer.c
 * 
 * @param flags 
 */
void ft_turn_false(t_flags *flags);


//----------------------INÍCIO DA DOIDERA DA MINHA CABEÇA------------------- //
// ----------------- VAI DAR CERTO SEUS DESCRENTE MALDITO -------------------//
// ---------- POR ENQUANTO ESTÃO NO ARQUIVO ESCOLHERNOME.c ------------------//
char	*specifier_char(t_flags *flags, char **s, va_list args);
char	*specifier_string(t_flags *flags, char **s, va_list args);
char	*specifier_decimal(t_flags *flags, char **s, va_list args);
char	*specifier_pointer(t_flags *flags, char **s, va_list args);
char	*specifier_integer(t_flags *flags, char **s, va_list args);
char	*specifier_unsigned_decimal(t_flags *flags, char **s, va_list args);
char	*specifier_lower_hexadecimal(t_flags *flags, char **s, va_list args);
char	*specifier_upper_hexadecimal(t_flags *flags, char **s, va_list args);
void	*ft_ite_spf(void *(*f)(t_flags*, char**, va_list),\
						t_flags *flags, char **s, va_list args);
// --------------- FIM DA DOIDERA DA MINHA CABEÇA -------------------------- //
#endif
