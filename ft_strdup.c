/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:52:22 by mashar            #+#    #+#             */
/*   Updated: 2019/11/22 13:52:24 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		copy[j] = s1[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
