/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_the_same_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:31 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/22 19:12:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *const a, t_stack *const b)
{
	swap(a, shadow);
	swap(b, shadow);
  printf ("ss\n");
}

void	rr(t_stack *const a, t_stack *const b)
{
	rotate(a, shadow);
	rotate(b, shadow);
  printf ("rr\n");
}

void	rrr(t_stack *const a, t_stack *const b)
{
	rrotate(a, shadow);
	rrotate(b, shadow);
  printf ("rrr\n");
}
