/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshanabl <mshanabl@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:13:42 by mshanabl          #+#    #+#             */
/*   Updated: 2026/02/02 02:11:48 by mshanabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	int		max_iter;
	char	*type;
	double	julia_cx;
	double	julia_cy;
}	t_fractal;

int		get_color(int iter, int max_iter);

void	render_fractal(t_fractal *f);
int		clean_exit(t_fractal *f);

int		handle_mouse(int button, int x, int y, t_fractal *f);
int		handle_keypress(int keycode, t_fractal *f);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_putstr(const char *s);
double	ft_atof(const char *str);

#endif
