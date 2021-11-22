#ifndef GGG_2D_H
#define GGG_2D_H

#include "ggg-2d-defs.h"

#ifdef __cplusplus
extern "C" {
#endif

//C code start

//Basic Shapes functions

//function to draw a point with color
void GGG2D_DrawPoint(int x, int y, GGG2D_Color* color);

//function to draw a point with color
void GGG2D_DrawPointP(GGG2D_Point p1, GGG2D_Color* color);

//function to draw line with thickness and color
void GGG2D_DrawLine(int x1, int y1, int x2, int y2, int thickness, GGG2D_Color* color);

//function to draw line with thickness and color
void GGG2D_DrawLineP(GGG2D_Point p1, GGG2D_Point p2, int thickness, GGG2D_Color* color);

//function to draw rectangled, filled
void GGG2D_DrawRectangle(GGG2D_Rectangle* rect,GGG2D_Color* color);

//function to draw rectangle outline with color
void GGG2D_DrawRectangleOutline(GGG2D_Rectangle* rect,GGG2D_Color* color);

//function to draw triangle, filled
void GGG2D_DrawTriangle(GGG2D_Triangle* triangle,GGG2D_Color* color);

//function to draw triangle outline with color
void GGG2D_DrawTriangleOutline(GGG2D_Triangle* triangle,GGG2D_Color* color);

//function to draw circle, filled
void GGG2D_DrawCircle(GGG2D_Circle* circle, GGG2D_Color* color);

//function to draw circle outline with color
void GGG2D_DrawCircleOutline(GGG2D_Circle* circle, GGG2D_Color* color);


//Sprite draw functions


//function to draw human eye iris and pupil
void GGG2D_DrawHumanEye_IrisPupil(int posX, int posY, int pupilSize, int irisSize, GGG2D_Color* pupil_color, GGG2D_Color* iris_color);

//end C code

#ifdef __cplusplus
}
#endif


#endif
