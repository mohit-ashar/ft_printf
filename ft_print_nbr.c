/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:54:03 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:54:05 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		act_width_lt_precision_nbr(t_meta_print meta, char *str, int len_str)
{
	if (len_str > meta.precision)
		return (write(1, str, len_str));
	else
		return (act_custom_write_zero(str, meta.precision, len_str));
	return (0);
}

int		act_width_gt_precision_nbr(t_meta_print meta, char *str, int len_str)
{
	int x;
	int i;

	i = 0;
	x = 0;
	if (meta.precision >= len_str)
	{
		if (meta.flag == '-')
			x = act_custom_write_zero(str, meta.precision, len_str);
		if (str[0] == '-')
			meta.width--;
		while (i++ < (meta.width - meta.precision))
			ft_putchar(' ');
		if (meta.flag != '-')
			x = act_custom_write_zero(str, meta.precision, len_str);
		return (x + (i - 1));
	}
	if (meta.width > len_str)
	{
		if (meta.flag == '0' && meta.is_zero && str[0] == '-' &&\
		(meta.width = meta.width - 1))
			return (act_custom_write_zero(str, meta.width, len_str));
		return (act_custom_write(meta, str, meta.width, len_str));
	}
	return (write(1, str, len_str));
}

int		ft_print_nbr_short(t_meta_print meta, char *str, int len_str)
{
	if (str[0] == '0' && ft_strlen(str) == 1 && meta.precision == 0)
		str[0] = ' ';
	if (meta.precision == -2 && meta.width > 0)
	{
		if (len_str < meta.width)
		{
			if (meta.flag == '0')
			{
				if (str[0] == '-')
					meta.width--;
				return (act_custom_write_zero(str, meta.width, len_str));
			}
			return (act_custom_write(meta, str, meta.width, len_str));
		}
		else
			return (write(1, str, len_str));
	}
	if (meta.width < meta.precision)
		return (act_width_lt_precision_nbr(meta, str, len_str));
	if (meta.width > meta.precision)
		return (act_width_gt_precision_nbr(meta, str, len_str));
	if (meta.width == meta.precision)
		return (act_custom_write_zero(str, meta.precision, len_str));
	return (0);
}

char	*get_nbr_string(t_meta_print meta, char *s, va_list ap)
{
	if (meta.specifier == 'x' || meta.specifier == 'X')
		s = decimal_to_hex(va_arg(ap, unsigned int), meta.specifier);
	if (meta.specifier == 'p')
		s = decimal_to_hex(va_arg(ap, unsigned long), meta.specifier);
	if (meta.specifier == 'u')
		s = ft_uint_itoa(va_arg(ap, unsigned int));
	else if (meta.specifier == 'd' || meta.specifier == 'i')
		s = ft_itoa(va_arg(ap, int));
	return (s);
}

int		ft_print_nbr(t_meta_print meta, va_list ap)
{
	char		*s;
	int			i;

	i = 0;
	s = NULL;
	meta = check_var_meta(meta, ap);
	s = get_nbr_string(meta, s, ap);
	s = act_null_check((char *)s);
	meta.precision = meta.is_zero ? 1 : meta.precision;
	meta.precision = (meta.is_zero && ft_strlen(s) == 1 && s[0] == '0' \
	&& meta.flag == '0' && meta.width != 0) ? meta.width : meta.precision;
	if ((meta.width <= 0 && meta.precision <= 0))
	{
		if (meta.specifier != 'p' && ft_strlen(s) > 0)
			if (meta.precision == 0 && s[0] == '0')
				return (0 * ft_free(s));
		return (write(1, s, ft_strlen(s)) * ft_free(s));
	}
	if ((meta.width > 0) || (meta.precision > 0))
		i = ft_print_nbr_short(meta, s, ft_strlen(s));
	return (i * ft_free(s));
}
