*This project has been created as part of the 42 curriculum by mshanabl*

## Description

fract'ol is a graphical fractal exploration program written in C using the MiniLibX library. The program renders two types of fractals: the Mandelbrot set and Julia sets. Users can interactively explore these fractals by zooming in and out, and panning the view to discover the infinite complexity of these mathematical objects.

The project demonstrates fundamental computer graphics concepts including:
- Complex number calculations
- Pixel rendering and color mapping
- Real-time interactive visualization
- Event handling (keyboard and mouse)
- Memory management in C

## Instructions

### Compilation

```bash
make
```

The Makefile will compile the project with the required flags (`-Wall -Wextra -Werror`) and automatically build the MiniLibX library.

### Execution

```bash
./fractol mandelbrot
./fractol julia <real> <imag>
```

#### Examples

Display the Mandelbrot set:
```bash
./fractol mandelbrot
```

Display a Julia set with specific parameters:
```bash
./fractol Julia -0.7 0.27015
./fractol Julia -0.835 -0.2321
./fractol Julia -0.8 0.156
./fractol Julia -0.4 0.6
./fractol Julia 0.285 0.01
```

### Controls

- **Mouse Wheel**: Zoom in (scroll up) and zoom out (scroll down)
- **Arrow Keys**: Pan left, right, up, and down (bonus feature)
- **ESC**: Close the window and exit the program
- **Window Close Button**: Close the window and exit the program

## Resources

### Fractal Mathematics
- [Wikipedia - Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Wikipedia - Julia Set](https://en.wikipedia.org/wiki/Julia_set)
- [Fractal Explorer Guide](https://www.fractalexplorer.com/tutorial.html)

### Technical References
- Complex number arithmetic in C
- Escape-time algorithm for fractal generation
- Color mapping techniques for visualization

## AI Usage

AI was used to:
- Explain the mathematical concepts behind Julia and Mandelbrot sets
- Clarify how complex numbers are used in fractal calculations
- Provide guidance on color mapping techniques for visualization

