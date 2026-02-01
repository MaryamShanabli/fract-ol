/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshanabl <mshanabl@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:13:15 by mshanabl          #+#    #+#             */
/*   Updated: 2026/02/01 17:15:56 by mshanabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_putstr(const char *s)
{
	int	len;

	if (!s)
		return (write(2, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

static void	parse_integer(const char **str, double *result)
{
	while (**str >= '0' && **str <= '9')
	{
		*result = *result * 10.0 + (**str - '0');
		(*str)++;
	}
}

static void	parse_decimal(const char **str, double *result)
{
	double	decimal;

	decimal = 0.1;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			*result = *result + decimal * (**str - '0');
			decimal *= 0.1;
			(*str)++;
		}
	}
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	parse_integer(&str, &result);
	parse_decimal(&str, &result);
	return (result * sign);
}
