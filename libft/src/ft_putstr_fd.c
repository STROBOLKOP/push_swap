/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:18:10 by efret             #+#    #+#             */
/*   Updated: 2023/12/04 17:37:28 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
