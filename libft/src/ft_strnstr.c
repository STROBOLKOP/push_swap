/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:17:28 by efret             #+#    #+#             */
/*   Updated: 2023/12/04 17:35:44 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (!little[0])
		return ((char *)big);
	b = 0;
	while (big[b] && len > 0)
	{
		l = 0;
		while (big[b + l] == little[l] && len - l > 0)
		{
			l++;
			if (!little[l])
				return ((char *)&big[b]);
		}
		b++;
		len--;
	}
	return (NULL);
}
