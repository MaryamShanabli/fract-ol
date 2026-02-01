/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshanabl <mshanabl@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:12:56 by mshanabl          #+#    #+#             */
/*   Updated: 2026/02/01 19:54:06 by mshanabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel_color(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	pixel = img->addr + offset;
	*(unsigned int *)pixel = color;
}

static int	calculate_mandelbrot(double cx, double cy, int max_iter)
{
	double	zx;
	double	zy;
	double	temp;
	int		iter;

	zx = 0.0;
	zy = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		if (zx * zx + zy * zy > 4.0)
			return (iter);
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iter++;
	}
	return (max_iter);
}

static int	calculate_julia(t_fractal *f, double zx, double zy)
{
	double	temp;
	int		iter;

	iter = 0;
	while (iter < f->max_iter)
	{
		if (zx * zx + zy * zy > 4.0)
			return (iter);
		temp = zx * zx - zy * zy + f->julia_cx;
		zy = 2 * zx * zy + f->julia_cy;
		zx = temp;
		iter++;
	}
	return (f->max_iter);
}

static void	render_line(t_fractal *f, int y)
{
	int		x;
	double	real;
	double	imag;
	int		iter;
	double	pixel_size;

	pixel_size = (f->max_real - f->min_real) / f->width;
	x = 0;
	while (x < f->width)
	{
		real = f->min_real + x * pixel_size;
		imag = f->max_imag - y * pixel_size;
		if (ft_strcmp(f->type, "m") == 0)
			iter = calculate_mandelbrot(real, imag, f->max_iter);
		else
			iter = calculate_julia(f, real, imag);
		put_pixel_color(&f->img, x, y, get_color(iter, f->max_iter));
		x++;
	}
}

void	render_fractal(t_fractal *f)
{
	int	y;

	y = 0;
	while (y < f->height)
	{
		render_line(f, y);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
