/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:29:30 by efret             #+#    #+#             */
/*   Updated: 2023/12/04 17:36:15 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	d_len = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i + d_len < size - 1 && src[i])
	{
		dest[i + d_len] = src[i];
		i++;
	}
	dest[i + d_len] = '\0';
	if (size <= d_len)
		return (size + ft_strlen(src));
	return (d_len + ft_strlen(src));
}
