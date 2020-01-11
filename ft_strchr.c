/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:52:34 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:52:37 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(str);
	while (i < (len + 1))
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
