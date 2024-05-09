# cub3D


## Description:

Cub3D is a collaborative project aimed at creating a realistic 3D graphical representation of the inside of a maze from a first-person perspective. Implemented in C, the project utilizes Ray-Casting principles and the miniLibX library for graphics rendering. It provides users with an interactive exploration experience of a virtual maze environment.

## Project Structure

The Cub3D project is organized into several directories, each serving a specific purpose. Here's an overview:

- **src/:** Contains the source files for the main program logic, including Ray-Casting implementation and maze rendering.
- **texture/:** Holds texture files used for wall textures and other visual elements.
- **includes/:** Contains header files necessary for compiling the project.
- **libft/:** Directory for the Libft library, providing utility functions.
- **maps/:** Includes sample map files in the .cub format for testing.
- **Makefile:** Makefile for compiling, building the MLX library, and managing the project.
- **cub3d:** Executable file generated after compilation.

This structured approach ensures clarity and organization within the project, facilitating easier management and maintenance.


## Features

- **Interactive Exploration:** Users can navigate through the maze environment from a first-person perspective.
- **Wall Textures:** Different wall textures are displayed based on the orientation of the walls (North, South, East, West).
- **Floor and Ceiling Colors:** Allows customization of floor and ceiling colors for visual aesthetics.
- **Smooth Window Management:** Supports smooth window operations, including switching windows and minimizing.
- **Keyboard Controls:** Arrow keys allow users to look left and right in the maze, while WASD keys facilitate movement within the maze.
- **Clean Program Exit:** Provides a clean exit mechanism via ESC key or window close button.
- **Map Parsing:** Parses a scene description file (.cub) to define the maze structure and textures.
- **Error Handling:** Detects and reports misconfigurations or errors encountered during map parsing.

## Compilation:

To compile the project, simply run 'make':

```bash
make
```
## Usage 
After compilation, run the compiled program to start Cub3D:

```bash
./cub3d map.cub #map.cub could be replaced with any other custom or provided maps you would like to use from the maps folder.
```

## Collaboration:

This two-person project was done with [Sal-zuba](https://github.com/Sal-zuba).

. I was responsible for the parsing, map dynamics, and error management.

. Saadoun took care of the Raycasting and texture management part.
## 🚀 Next Project

[ft_irc](https://github.com/adhaka-afk/ft_irc)

## ⏳ Previous Project

[CPP04](https://github.com/adhaka-afk/CPP04)


