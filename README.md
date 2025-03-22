# Cube3D

A 3D rendering project using raycasting, inspired by classic games like Wolfenstein 3D. This project demonstrates the use of raycasting to render a 3D environment from a 2D map.

---

## Build Instructions

To build the project, run the following commands in your terminal:

```console
make minilibx && make && make clean
```

---

## Table of Contents

1. [map_utils.c](#map_utilsc)
2. [put_pixel.c](#put_pixelc)
3. [get_texel_color.c](#get_texel_colorc)
4. [clear_image.c](#clear_imagec)
5. [wall_casting.c](#wall_castingc)
6. [handle_key_inputs.c](#handle_key_inputsc)
7. [Helper Functions](#helper-functions)
8. [Raycasting Utilities](#raycasting-utilities)
9. [main.c](#mainc)

---

## File Descriptions

### 1. map_utils.c

This file contains utility functions for handling map data:

- **`count_lines(char *path)`**  
  Opens a file and counts the number of lines in it.

- **`fill_map(char *path, char **map)`**  
  Reads the file line by line and fills the `map` array with its content.

- **`open_map(char *path)`**  
  Allocates memory for the map and fills it using the above functions.

---

### 2. put_pixel.c

This file contains a function to manipulate image data at the pixel level:

- **`put_pixel(t_img_data *img, int x, int y, int color)`**  
  Sets the color of a pixel at coordinates `(x, y)` in the image data.

---

### 3. get_texel_color.c

This file contains a function to retrieve the color of a texel from a texture:

- **`get_texel_color(t_texture_data *tex, int texX, int texY)`**  
  Retrieves the color of a texel at coordinates `(texX, texY)` from the texture data.

---

### 4. clear_image.c

This file contains a function to clear an image by filling it with a specific color:

- **`clear_image(t_img_data *img, int color)`**  
  Fills the entire image with the specified color.

---

### 5. wall_casting.c

This file contains the main wall-casting logic:

- **`wall_casting(t_program *program)`**  
  Performs the wall-casting algorithm to render the 3D scene based on the player's position and direction. It uses helper functions like `calc_step_and_initial_side_dist`, `perform_dda`, and `calc_where_the_wall_was_hit`.

---

### 6. handle_key_inputs.c

This file handles keyboard inputs to control the player:

- **`handle_key_inputs(int keycode, t_program *program)`**  
  Processes key presses to move the player or rotate the view direction.

---

### 7. Helper Functions

#### load_game_and_raycast_initial_info.c

- **`load_game_and_raycast_initial_info(t_program *program)`**  
  Initializes the player's position, direction, and camera plane for raycasting.

#### safe_exit.c

- **`safe_exit(t_program *program)`**  
  Safely exits the program, freeing allocated resources.

---

### 8. Raycasting Utilities

#### calc_step_and_initial_side_dist.c

- **`calc_step_and_initial_side_dist(t_program *program)`**  
  Calculates the step direction and initial side distances for the raycasting algorithm.

#### perform_dda.c

- **`perform_dda(t_program *program, int *side)`**  
  Performs the Digital Differential Analysis (DDA) algorithm to determine the point of wall collision.

#### calc_dist_of_perpendicular_ray.c

- **`calc_dist_of_perpendicular_ray(t_program *program, int side)`**  
  Calculates the perpendicular distance from the player to the wall.

#### calc_where_the_wall_was_hit.c

- **`calc_where_the_wall_was_hit(t_program *program, int side, double *wallX)`**  
  Determines the exact position where the wall was hit and the corresponding texture to use.

#### calc_vertical_line_and_transform_image.c

- **`calc_vertical_line_and_transform_image(t_program *program, int x, double wallX, int lineHeight, int side)`**  
  Draws the vertical line representing the wall slice and applies texture mapping.

---

### 9. main.c

This is the main entry point of the program:

- Initializes the program, loads the map and textures, sets up the player and raycasting parameters, and starts the main loop to handle events and render the scene.

---

## Features

- **Raycasting Engine**: Implements a raycasting algorithm to render a 3D environment from a 2D map.
- **Keyboard Controls**: Allows the player to move and rotate the view using keyboard inputs.
- **Texture Mapping**: Supports textured walls for a more immersive experience.
- **Customizable Maps**: Easily load and render custom maps.

---

## How to Run

1. Build the project using the provided `make` command.
2. Run the executable generated in the project directory.
3. Use the keyboard to navigate the 3D environment.

---

## Controls

- **Arrow Keys**: Move forward, backward, and strafe left/right.
- **Left/Right Arrows**: Rotate the player's view.

---

## Project Structure

```
cube3d/
├── sources/
│   ├── handle_key_inputs.c
│   ├── safe_exit.c
│   ├── wall_casting.c
│   ├── utils/
│   │   ├── input_keys/
│   │   │   ├── forward.c
│   │   │   ├── backward.c
│   │   │   ├── left.c
│   │   │   └── right.c
│   │   ├── raycasting/
│   │   │   ├── calc_step_and_initial_side_dist.c
│   │   │   ├── perform_dda.c
│   │   │   ├── calc_dist_of_perpendicular_ray.c
│   │   │   ├── calc_where_the_wall_was_hit.c
│   │   │   └── calc_vertical_line_and_transform_image.c
│   │   └── helper/
│   │       └── load_game_and_raycast_initial_info.c
│   ├── get_next_line/
│   │   ├── get_next_line.c
│   │   └── get_next_line_utils.c
│   └── libft/
│       ├── ft_atoi.c
│       ├── ft_bzero.c
│       ├── ft_calloc.c
│       └── ...
├── includes/
│   └── cube3d.h
├── assets/
│   └── textures/
└── README.md
```

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

## Acknowledgments

- Inspired by classic 3D games like **Wolfenstein 3D**.
- Built using the **MiniLibX** graphics library.