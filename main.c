/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshanabl <mshanabl@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:13:04 by mshanabl          #+#    #+#             */
/*   Updated: 2026/02/02 02:02:45 by mshanabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("  ./fractol Mandelbrot\n");
	ft_putstr("  ./fractol Julia <real> <imag>\n");
	ft_putstr("Examples:\n");
	ft_putstr("  ./fractol Julia -0.4 0.6\n");
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x00000000); //(0x000511) Deep ocean color
	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static void	init_fractal(t_fractal *f, char *type,
	double julia_cx, double julia_cy)
{
	f->width = 1000;
	f->height = 800;
	f->max_iter = 100;
	f->type = type;
	if (ft_strcmp(type, "m") == 0)
	{
		f->min_real = -2.5;
		f->max_real = 1.0;
		f->min_imag = -1.4;
		f->max_imag = 1.4;
	}
	else if (ft_strcmp(type, "j") == 0)
	{
		f->min_real = -2.0;
		f->max_real = 2.0;
		f->min_imag = -1.6;
		f->max_imag = 1.6;
		f->julia_cx = julia_cx;
		f->julia_cy = julia_cy;
	}
}

int	clean_exit(t_fractal *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2)
		return (print_usage(), 1);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		init_fractal(&f, "m", 0.0, 0.0);
	else if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4)
		init_fractal(&f, "j", ft_atof(argv[2]), ft_atof(argv[3]));
	else if (ft_strcmp(argv[1], "Julia") == 0)
		init_fractal(&f, "j", 0.35, 0.35);
	else
		return (print_usage(), 1);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.width, f.height, "Fract-ol");
	f.img.img_ptr = mlx_new_image(f.mlx, f.width, f.height);
	f.img.addr = mlx_get_data_addr(f.img.img_ptr, &f.img.bpp,
			&f.img.line_len, &f.img.endian);
	mlx_hook(f.win, 2, 1L << 0, handle_keypress, &f);
	mlx_hook(f.win, 17, 0, clean_exit, &f);
	mlx_hook(f.win, 4, 1L << 2, handle_mouse, &f);
	render_fractal(&f);
	mlx_loop(f.mlx);
	return (0);
}
