/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:00:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 21:22:11 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>
#include <stdio.h>

static size_t _atoi_helper(char const * const str, int i, int res)
{
  while (str[i])
  {
    if (str[i] != ' ')
      return (invalid_input);
  }
  return (res);
}

size_t _atoi(char const * const str)
{
  int i;
  long long res;
  int sign;

  sign = 1;
  res = 0;
  i = 0;
  while(str[i] && str[i] == ' ')
      i++;
  if (str[i] == '+' || str[i] == '-')
  {
    if (str[i] == '-')
      sign = -1;
    i++;
  }
  while(ft_isdigit(str[i]))
  {
    res = (10 * res) + (str[i] - '0');
    if (res * sign > INT_MAX || res * sign < INT_MIN)
        return (invalid_input);
    i++;
  }
  return (_atoi_helper(str, i, res * sign));
}

int alloc_nums(int ac, char **av, t_stack *stack)
{
  size_t current;
  int i;

  i = 0;
  while (i < ac)
  {
    current = _atoi(av[ac - 1 - i]);
    if (invalid_input == current || ((invalid_input != current) && find(current, stack)))
        return (-1);
    push((int const)current, stack);
    i++;
  }
  return 0;
}

void free_mat(char **mat)
{
  int i = 0;
  if (NULL == mat)
  {
    return;
  }
  while (mat[i])
  {
    free(mat[i]);
    i++;
  }
  free(mat);
}

static int _ac_count(char **mat)
{
  int count;

  count = 0;
  while (mat[count])
  {
    count++;
  }
  return (count);
}

t_stack *a_init(int ac, char **av)
{
  char **mat;

  t_stack *stack;

  stack = stack_init();
  mat = NULL;
  if (ac == 2)
  {
    mat = ft_split(av[1], ' ');
    if (alloc_nums(_ac_count(mat), mat, stack) == -1)
    {
      free_mat(mat);
      return NULL;
    }
  }
  else if (ac < 2 || alloc_nums(ac - 1, av + 1, stack) == -1)
  {
    return NULL;
  }
  free_mat(mat);
  return (stack);
}






