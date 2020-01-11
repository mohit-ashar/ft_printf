/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:53:20 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:53:23 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_free(char *str)
{
	if (str == NULL)
		return (1);
	free(str);
	str = NULL;
	return (1);
}

char			*act_null_check(char *str)
{
	if (str)
		return (str);
	else
		return ("(null)");
}

int				act_custom_write(t_meta_print meta, char *str, int a, int b)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (meta.flag == '-')
		write(1, str, b);
	if (meta.flag == '0' && ((meta.precision > b) || meta.is_zero))
		c = '0';
	while (i < (a - b))
	{
		ft_putchar(c);
		i++;
	}
	if (meta.flag != '-')
		write(1, str, b);
	return (i + b);
}

int				act_custom_write_zero(char *str, int a, int b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str[i] == '-')
	{
		write(1, "-", 1);
		j++;
		i = -1;
	}
	while (i++ < (a - b))
		ft_putchar('0');
	write(1, &str[j], b - j);
	return ((i - 1 + j) + b);
}

t_meta_print	check_var_meta(t_meta_print meta, va_list ap)
{
	int flag_w;

	flag_w = 0;
	if (meta.width == -1 && (flag_w = flag_w + 1))
		meta.width = va_arg(ap, int);
	if (meta.precision == -1)
	{
		meta.precision = va_arg(ap, int);
		if (meta.precision < 0)
			meta.is_zero++;
	}
	if (meta.width < 0 && flag_w)
	{
		meta.width = -meta.width;
		meta.flag = '-';
	}
	if (meta.precision < 0 && meta.is_zero)
		meta.precision = 0;
	return (meta);
}
