*This project has been created as part of the 42 curriculum.by [albelaiz , yaamaich / hafa hermanos].*

# Cub3D - 3D Raycasting Engine

## Description

The Cub3D project serves as a practical, simplified introduction to the world of 3D graphics rendering. The primary goal is to create a 3D perspective from a 2D map using the classic raycasting algorithm.

**Overview:** The engine is highly optimized for performance. Instead of rendering the entire world, it calculates only what is currently visible on the screen. It works by shooting rays from the player's viewpoint for every vertical screen column. By calculating the distance from the player to the nearest wall intersection, the engine uses perspective projection mathematics to convert that distance into wall height on the screen. This allows for the creation of a pseudo-3D environment with very minimal resource costs.

## Technical Architecture

### Project Structure

The project is organized as follows:

- **Core Files:** Main implementation files for the game engine
  - `main.c` - Entry point and main game loop
  - `init_game.c` - Game initialization
  - `draw.c` - Rendering logic
  - `recasting.c` - Raycasting algorithm implementation
  - `recasting_tex.c` - Texture raycasting
  - `recasting_tex_draw.c` - Textured wall drawing
  - `move_player.c` - Player movement and collision
  - `parse.c` - Map file parsing
  - `validation.c` - Input validation

- **Libraries:**
  - `libft/` - Custom C library with utility functions

- **Assets:**
  - `textures/` - Game textures
  - `map/` - Map definition files (`.cub` format)

- **Graphics Library:**
  - `MLX42-master/` - The 42-curriculum graphics library wrapper

### Dependencies & Technical Choices

To handle window creation, events, and rendering, this project relies on specific graphics libraries:

* **MLX42:** A 42-curriculum wrapper library that provides a simplified interface for graphics rendering and event handling.
* **GLFW:** Used internally by MLX42 for window management and OpenGL context creation.
* **OpenGL:** The underlying graphics library for GPU rendering.

## Instructions

Follow these steps to compile, install dependencies, and execute the game.

### Prerequisites

Ensure you have the following installed on your system:
- `gcc` or `clang` compiler
- `make` build tool
- `cmake` (for MLX42 compilation)

### Installation and Execution

**1. Install System Dependencies**

On macOS (if applicable):
```bash
brew install glfw cmake
```

On Ubuntu/Debian:
```bash
sudo apt-get install libglfw3 libglfw3-dev cmake build-essential
```

**2. Build MLX42 (if not already built)**

Navigate to the MLX42 directory and build it:
```bash
cd MLX42-master
cmake -B build && cmake --build build --parallel --config Release
cd build
make
cd ../..
```

**3. Compile the Project**

From the project root directory, compile the source code:
```bash
make
```

This will generate the `cub3D` executable.

**4. Running the Game**

Execute the program by passing a valid `.cub` map file:
```bash
./cub3D map/map1.cub
```

**5. Controls**

- **W/A/S/D** - Move forward, left, backward, right
- **LEFT/RIGHT Arrow Keys** - Rotate view
- **ESC** - Exit the game

## Game Files

### Map Format (.cub files)

Map files define the layout of the 3D world using the following format:
- Textures are defined with `NO`, `SO`, `EA`, `WE` (cardinal directions)
- Floor and ceiling colors are defined with `F` and `C`
- The map grid is defined with:
  - `0` = Empty space
  - `1` = Wall
  - `N/S/E/W` = Player start position and direction

Example map structure in `map1.cub`:
```
NO ./textures/north.png
SO ./textures/south.png
EA ./textures/east.png
WE ./textures/west.png
F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
10110000011100000111011N0111111111
1011000001110101011001011111111111
1001000000000101011000001111111111
100000000000001011000000000000001111
100000000000001011101010000000001111
11000001110101011111011010101111111111
11110111 1110101101111010101111111111
11111111 1111101101010111010101111111111
111111111111111111111111111111111111111
```

## Resources

The algorithm and mathematical concepts were developed using multiple references:

**Primary Logic & Math References:**
* [Permadi Raycasting Tutorial](https://permadi.com/tutorial/raycast/) - The primary reference used for engine logic and mathematics.

**Video References:**
These videos, particularly those discussing raycasting engines, were instrumental in understanding the algorithm:
* [Make Your Own Raycaster Part 1](https://youtu.be/gYRrGTC7GtA)
* [Making my First RAYCASTING Game in C++ - SFML Gamedev - Devlog 1](https://youtu.be/LUYxLjic0Bc)
* [Ray casting fully explained. Pseudo 3D game](https://youtu.be/g8p7nAbDz6Y)
* [Lode V. Tutorial](https://lodev.org/cgtutor/raycasting.html) - Classic raycasting reference using vector/matrix approach

**Additional Documentation:**
* [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)
* [OpenGL Documentation](https://www.khronos.org/opengl/)

## Development Notes

### Key Implementation Details

1. **Raycasting Algorithm:** Rays are cast for each vertical column on the screen to determine wall heights through distance calculation.

2. **Texture Mapping:** Walls are textured by determining which part of the texture to draw based on the hit position and wall orientation.

3. **Player Movement:** Movement checks for collisions against the map grid to prevent walking through walls.

4. **Map Parsing:** The `.cub` file is parsed to extract texture paths, colors, and the 2D map layout.

## Compilation Issues & Troubleshooting

If you encounter compilation errors:

1. **MLX42 not found:** Ensure MLX42 is properly built in the `MLX42-master/build` directory.
2. **Missing textures:** Verify that texture paths in your `.cub` file are correct.
3. **Map parsing errors:** Check that your map file follows the correct `.cub` format.

Run `make clean` to remove old build artifacts, then `make` to recompile.

## License

This project is part of the 42 School curriculum.

---

**Note:** This is an educational project demonstrating fundamental concepts in 3D graphics rendering and game engine development.
