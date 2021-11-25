
#include "ggg-2d-defs.h"
#include "raylib.h"


#ifndef GGG2D_DRAW_DEFS_H
#define GGG2D_DRAW_DEFS_H

//C declaration code

#ifdef __cplusplus
extern "C" {
#endif

//function to draw a point with color
void GGG2D_DrawPoint_internal(int x, int y, GGG2D_Color* color);

//function to draw a point with color
void GGG2D_DrawPointP_internal(GGG2D_Point p1, GGG2D_Color* color);

//function to draw line with thickness and color
void GGG2D_DrawLine_internal(int x1, int y1, int x2, int y2, int thickness, GGG2D_Color* color);

//function to draw line with thickness and color
void GGG2D_DrawLineP_internal(GGG2D_Point p1, GGG2D_Point p2, int thickness, GGG2D_Color* color);

//function to draw rectangled, filled
void GGG2D_DrawRectangle_internal(GGG2D_Rectangle* rect,GGG2D_Color* color);

//function to draw rectangle outline with color
void GGG2D_DrawRectangleOutline_internal(GGG2D_Rectangle* rect,GGG2D_Color* color);

//function to draw triangle, filled
void GGG2D_DrawTriangle_internal(GGG2D_Triangle* triangle,GGG2D_Color* color);

//function to draw triangle outline with color
void GGG2D_DrawTriangleOutline_internal(GGG2D_Triangle* triangle,GGG2D_Color* color);

//function to draw circle, filled
void GGG2D_DrawCircle_internal(GGG2D_Circle* circle, GGG2D_Color* color);

//function to draw circle outline with color
void GGG2D_DrawCircleOutline_internal(GGG2D_Circle* circle, GGG2D_Color* color);

#ifdef __cplusplus
}
#endif

#endif

//C declaration code end

#if defined(GGG2D_DRAW)


//C definition code start


//function to draw a point with color
void GGG2D_DrawPoint_internal(int x, int y, GGG2D_Color* color)
{
	
}

//function to draw a point with color
void GGG2D_DrawPointP_internal(GGG2D_Point p1, GGG2D_Color* color)
{
	
}

//function to draw line with thickness and color
void GGG2D_DrawLine_internal(int x1, int y1, int x2, int y2, int thickness, GGG2D_Color* color)
{

}

//function to draw line with thickness and color
void GGG2D_DrawLineP_internal(GGG2D_Point p1, GGG2D_Point p2, int thickness, GGG2D_Color* color)
{
	
}

//function to draw rectangled, filled
void GGG2D_DrawRectangle_internal(GGG2D_Rectangle* rect,GGG2D_Color* color)
{
	
}

//function to draw rectangle outline with color
void GGG2D_DrawRectangleOutline_internal(GGG2D_Rectangle* rect,GGG2D_Color* color)
{
	
}

//function to draw triangle, filled
void GGG2D_DrawTriangle_internal(GGG2D_Triangle* triangle,GGG2D_Color* color)
{
	
}

//function to draw triangle outline with color
void GGG2D_DrawTriangleOutline_internal(GGG2D_Triangle* triangle,GGG2D_Color* color)
{
	
}

//function to draw circle, filled
void GGG2D_DrawCircle_internal(GGG2D_Circle* circle, GGG2D_Color* color)
{
	
}

//function to draw circle outline with color
void GGG2D_DrawCircleOutline_internal(GGG2D_Circle* circle, GGG2D_Color* color)
{
	
}

//end C code



#endif
