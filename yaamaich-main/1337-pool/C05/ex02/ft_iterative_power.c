/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:12:26 by yaamaich          #+#    #+#             */
/*   Updated: 2024/07/11 02:17:57 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	r;
	int	i;

	i = 0;
	r = 1;
	while (i < power)
	{
		r *= nb;
		i++;
	}
	if (power < 0)
		return (0);
	return (r);
}
