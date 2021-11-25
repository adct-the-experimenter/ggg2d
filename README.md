# Generative Game Graphics 2D

This is code made to help with making 2D generative art for video games.

The rendering is abstracted to any graphical library that can draw a point, line, rectangle, triangle, circle.

## Still developing. It is not ready for serious use.

## How to use

1. Choose a graphics library to use to handle drawing for this code set. (SDL2,raylib,etc.)

2. Copy ggg2d-core folder into your project.

3. Copy vanilla draw definitions header, ggg-2d-draw-defs-vanilla.h, and rename the file. 
For best practice, include graphics library file in name. 
Example: ggg-2d-draw-defs-raylib-3p5.h

4. Use graphics library calls to define the drawing functions in the new draw defintions header.

Example: ggg-2d-draw-defs-raylib-3p5.h

```

#include "raylib.h"

#if defined(GGG2D_DRAW)


//C definition code start

void GGG2D_DrawPoint_internal(int x, int y, GGG2D_Color* color)
{
	//raylib draw pixel used to define GGG2D_DrawPoint_internal function
	DrawPixel(x, y, (Color){.r=color->red,.g=color->green,.b=color->blue,.a=color->alpha});
}

...

//C definition code end

```

5. In ggg-2d-draw-select.h, include the fully-defined draw defintions header file made in step 3 and 4.

Example:

```
//define draw functions
#define GGG2D_DRAW

//add draw defintions header here.
#include "ggg-2d-draw-defs-raylib3p5.h"

```

6. In the general code, include ggg-2d.h header. 
Also include graphics library header for initialization of graphics library.
Look at tests/animate-monster-srpite/raylib-test/animate-monster-sprite-raylib.c for an example.

```
//graphics library here
#include "raylib.h"

#include "ggg-2d.h"

```

7. In compilation step, add ggg-2d.c file 
Look at tests/animate-monster-sprite/raylib-test/Makefile for an example.
