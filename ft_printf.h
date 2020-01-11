/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:51:32 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:51:41 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_meta_print
{
	char	flag;
	int		width;
	int		precision;
	char	specifier;
	int		count;
	char	*id;
	int		is_zero;
}				t_meta_print;

void			ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_atoi(char *str);
int				ft_strlen(const char *str);
t_meta_print	parse_printf_args(t_meta_print meta, char *args);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_printf(const char *str, ...);
int				ft_putnbr(int nb);
int				ft_nbrlen(int n);
int				ft_print_str(t_meta_print meta, va_list ap);
int				ft_print_nbr(t_meta_print meta, va_list ap);
char			*act_null_check(char *str);
t_meta_print	check_var_meta(t_meta_print meta, va_list ap);
char			*ft_itoa(int nbr);
char			*ft_strdup(const char *s1);
int				act_custom_write(t_meta_print meta, char *str, int a, int b);
int				ft_print_char(t_meta_print meta, va_list ap);
char			*ft_uint_itoa(unsigned int nbr);
char			*decimal_to_hex(unsigned long decimal, char c);
int				ft_free(char *str);
int				act_custom_write_zero(char *str, int a, int b);

#endif
