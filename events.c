/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshanabl <mshanabl@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:12:47 by mshanabl          #+#    #+#             */
/*   Updated: 2026/02/01 18:16:28 by mshanabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractal *f, double factor, int x, int y)
{
	double	mouse_real;
	double	mouse_imag;
	double	pixel_size;

	pixel_size = (f->max_real - f->min_real) / f->width;
	mouse_real = f->min_real + x * pixel_size;
	mouse_imag = f->min_imag + y * pixel_size;
	f->min_real = mouse_real - (mouse_real - f->min_real) * factor;
	f->max_real = mouse_real + (f->max_real - mouse_real) * factor;
	f->min_imag = mouse_imag - (mouse_imag - f->min_imag) * factor;
	f->max_imag = mouse_imag + (f->max_imag - mouse_imag) * factor;
}

static void	pan(t_fractal *f, int direction)
{
	double	shift_real;
	double	shift_imag;

	shift_real = (f->max_real - f->min_real) * 0.1;
	shift_imag = (f->max_imag - f->min_imag) * 0.1;
	if (direction == 0)
	{
		f->min_real -= shift_real;
		f->max_real -= shift_real;
	}
	else if (direction == 1)
	{
		f->min_real += shift_real;
		f->max_real += shift_real;
	}
	else if (direction == 2)
	{
		f->min_imag -= shift_imag;
		f->max_imag -= shift_imag;
	}
	else if (direction == 3)
	{
		f->min_imag += shift_imag;
		f->max_imag += shift_imag;
	}
}

static void	handle_arrow(int keycode, t_fractal *f)
{
	if (keycode == 65361 || keycode == 123)
		pan(f, 0);
	else if (keycode == 65363 || keycode == 124)
		pan(f, 1);
	else if (keycode == 65362 || keycode == 126)
		pan(f, 2);
	else if (keycode == 65364 || keycode == 125)
		pan(f, 3);
	render_fractal(f);
}

int	handle_keypress(int keycode, t_fractal *f)
{
	if (keycode == 65307 || keycode == 53)
		clean_exit(f);
	else
		handle_arrow(keycode, f);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
		zoom(f, 0.9, x, y);
	else if (button == 5)
		zoom(f, 1.1, x, y);
	render_fractal(f);
	return (0);
}
