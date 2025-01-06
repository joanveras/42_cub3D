
```console
make minilibx && make && make clean
```

## Table of Contents
1. [map_utils.c](#map_utilsc)
2. [put_pixel.c](#put_pixelc)
3. [get_texel_color.c](#get_texel_colorc)
4. [clear_image.c](#clear_imagec)
5. [raycasting.c](#raycastingc)
6. [handle_key_inputs.c](#handle_key_inputsc)
7. [main.c](#mainc)

## map_utils.c
This file contains utility functions for handling map data:
- `count_lines(char *path)`: Opens a file and counts the number of lines in it.
- `fill_map(char *path, char **map)`: Reads the file line by line and fills the `map` array with its content.
- `open_map(char *path)`: Allocates memory for the map and fills it using the above functions.

## put_pixel.c
This file contains a function to put a pixel on an image:
- `put_pixel(t_img_data *img, int x, int y, int color)`: Sets the color of a pixel at coordinates `(x, y)` in the image data.

## get_texel_color.c
This file contains a function to get the color of a texel from a texture:
- `get_texel_color(t_texture_data *tex, int texX, int texY)`: Retrieves the color of a texel at coordinates `(texX, texY)` from the texture data.

## clear_image.c
This file contains a function to clear an image by filling it with a specific color:
- `clear_image(t_img_data *img, int color)`: Fills the entire image with the specified color.

## raycasting.c
This file contains the main raycasting logic:
- `raycasting(t_program *program)`: Performs the raycasting algorithm to render the 3D scene based on the player's position and direction, and updates the image accordingly.

## handle_key_inputs.c
This file handles keyboard inputs to control the player:
- `handle_key_inputs(int keycode, t_program *program)`: Processes key presses to move the player or rotate the view direction.

## main.c
This is the main entry point of the program:
- Initializes the program, loads the map and textures, sets up the player and raycasting parameters, and starts the main loop to handle events and render the scene.
