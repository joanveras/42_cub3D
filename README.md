# Cub3D

A 3D rendering project using raycasting, inspired by the classic game Wolfenstein 3D.

## Project Structure

```
.
├── sources/
│   ├── get_next_line/    # Line reading utility
│   ├── libft/            # Custom C library
│   ├── utils/            # Utility functions
│   ├── wall_casting.c    # Raycasting implementation
│   ├── safe_exit.c       # Cleanup and error handling
│   ├── handle_key_inputs.c # Keyboard input handling
│   └── x11_connect.c     # X11 window management
├── includes/             # Header files
├── maps/                 # Map files (*.cub)
└── textures/             # Wall textures
```

## Requirements

- GCC compiler
- X11 libraries
- Make

## Building

```bash
make
```

## Running

```bash
./cub3D maps/map1.cub
```

## Controls

- WASD: Move player
- Arrow keys: Rotate view
- ESC: Exit game

## Map Format

Maps are defined in `.cub` files with the following structure:

```
NO textures/north.xpm    # North wall texture
SO textures/south.xpm    # South wall texture
WE textures/west.xpm     # West wall texture
EA textures/east.xpm     # East wall texture
F 220,100,0              # Floor color (RGB)
C 225,30,0               # Ceiling color (RGB)

1111111111111111111111
1000000000110000000001
1011000001110000000001
1001000000000000000001
1111111110110000011101
1000000000110000011101
1111011111111101110001
1111011111111101110001
1100000011010101110001
1000000000000000110001
1000000000000000110001
1100000111010101111101
11110111 1110101 1011
11111111 1111111 1111
```

- 1: Wall
- 0: Empty space
- N/S/E/W: Player starting position and direction
- Space: Optional space (ignored)

## Features

- 3D rendering using raycasting
- Wall textures
- Floor and ceiling colors
- Player movement and rotation
- Collision detection
- Window resizing
- Error handling

## Error Handling

The program handles various error cases:
- Invalid map format
- Missing textures
