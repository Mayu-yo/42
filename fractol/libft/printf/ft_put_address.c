/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:06:19 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/05 15:09:30 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long n, int uporlow)
{
	if (uporlow == 0)
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (ft_puthex(n, 0) + 2);
}
