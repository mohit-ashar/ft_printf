/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:55:19 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:55:21 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convert_to_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char			*reverse(char *str, char c)
{
	char		*rev;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(rev = malloc(sizeof(char) * (str[0] + 1 + 2))))
		return (NULL);
	if (c == 'p' && (i = i + 2))
	{
		j = j + 2;
		rev[0] = '0';
		rev[1] = 'x';
	}
	while (i - j < str[0])
	{
		rev[i] = str[str[0] + j - i];
		i++;
	}
	rev[i] = '\0';
	ft_free(str);
	if (c == 'X')
		return (convert_to_uppercase(rev));
	return (rev);
}

char			*decimal_to_hex(unsigned long decimal, char c)
{
	unsigned long	quotient;
	unsigned long	remainder;
	char			*str;
	int				i;

	i = 1;
	if (!(str = (char *)malloc(sizeof(char) * 20)))
		return (NULL);
	quotient = 1;
	remainder = 0;
	while (quotient > 0)
	{
		quotient = decimal / 16;
		remainder = decimal % 16;
		if (remainder > 9)
			remainder = remainder + 87;
		else
			remainder = remainder + '0';
		decimal = quotient;
		str[i] = remainder;
		i++;
	}
	str[0] = (i - 1);
	return (reverse(str, c));
}
