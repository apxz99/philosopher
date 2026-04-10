*This project has been created as part of the 42 curriculum by sarayapa.*

# fract-ol
fract-ol is a program that draws fractals using the MiniLibX graphics library.


## Description

A fractal is a mathematical shape that shows similar patterns when you zoom in.
In this project we render two famous fractals:

- Mandelbrot set

- Julia set

Each pixel of the screen represents a point in the complex plane.
The program runs a mathematical formula many times to check if the point belongs to the fractal, then colors the pixel based on the result.

This project helps practice:

- graphics programming

- complex numbers

- rendering algorithms

- event handling with MiniLibX

## Instructions

This program uses MiniLibX (MLX42) to create a window and draw fractals.


### Execution

Run Mandelbrot:

    ./fractol mandelbrot

Run Julia:

    ./fractol julia <real> <imaginary>

Example:

    ./fractol julia 0.285 0.01


### Controls


| Input               | Action             |
| ------------------- | ------------------ |
| Mouse wheel         | Zoom in / Zoom out |
| Arrow keys          | Move the view      |
| ESC                 | Exit program       |
| Window close button | Exit program       |



## Resources

List references such as:

- https://w.wiki/JAKr
- https://www.facebook.com/share/p/1DysnSwesi/
- https://github.com/codam-coding-college/MLX42/tree/master/docs
- https://mandel.gart.nz/#/
- https://jmaio.github.io/mandelbrot-maps/#/m@0.2361652,0.5633767,11.2,0.2/j@0.4364131,-0.6468786,4,2.12
- https://youtu.be/7MotVcGvFMg?si=lL01AY-aPZe9Doi8


### AI Usage

AI was used to help understand:

- Mandelbrot and Julia fractals

- how fractal formulas work

- MLX42 documentation

