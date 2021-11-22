#include "ggg-2d.h"

#include "ggg-2d-draw-select.h"

//function to draw a point with color
void GGG2D_DrawPoint(int x, int y, GGG2D_Color* color)
{
	GGG2D_DrawPoint_internal(x, y, color);
}

//function to draw a point with color
void GGG2D_DrawPointP(GGG2D_Point p1, GGG2D_Color* color)
{
	GGG2D_DrawPointP_internal(p1, color);
}

//function to draw line with thickness and color
void GGG2D_DrawLine(int x1, int y1, int x2, int y2, int thickness, GGG2D_Color* color)
{
	GGG2D_DrawLine_internal(x1, y1, x2, y2, thickness, color);
}

//function to draw line with thickness and color
void GGG2D_DrawLineP(GGG2D_Point p1, GGG2D_Point p2, int thickness, GGG2D_Color* color)
{
	GGG2D_DrawLineP_internal(p1,p2,thickness,color);
}

//function to draw rectangled, filled
void GGG2D_DrawRectangle(GGG2D_Rectangle* rect,GGG2D_Color* color)
{
	GGG2D_DrawRectangle_internal(rect,color);
}

//function to draw rectangle outline with color
void GGG2D_DrawRectangleOutline(GGG2D_Rectangle* rect,GGG2D_Color* color)
{
	GGG2D_DrawRectangleOutline_internal(rect,color);
}

//function to draw triangle, filled
void GGG2D_DrawTriangle(GGG2D_Triangle* triangle,GGG2D_Color* color)
{
	GGG2D_DrawTriangle_internal(triangle,color);
}

//function to draw triangle outline with color
void GGG2D_DrawTriangleOutline(GGG2D_Triangle* triangle,GGG2D_Color* color)
{
	GGG2D_DrawTriangleOutline_internal(triangle,color);
}

//function to draw circle, filled
void GGG2D_DrawCircle(GGG2D_Circle* circle, GGG2D_Color* color)
{
	GGG2D_DrawCircle_internal(circle,color);
}

//function to draw circle outline with color
void GGG2D_DrawCircleOutline(GGG2D_Circle* circle, GGG2D_Color* color)
{
	GGG2D_DrawCircleOutline_internal(circle, color);
}

void GGG2D_DrawHumanEye_IrisPupil(int posX, int posY, int pupilSize, int irisSize, GGG2D_Color* pupil_color, GGG2D_Color* iris_color)
{
	
	GGG2D_Color black = {10,10,10,255};
	
	//draw iris first
	GGG2D_Circle iris_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=irisSize/2};
	
	iris_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=irisSize/2};
	GGG2D_DrawCircle_internal(&iris_circle,iris_color);
	
	//draw iris outline
	iris_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=(irisSize-1)/2};
	GGG2D_DrawCircleOutline_internal(&iris_circle,&black);
	
	iris_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=(irisSize-2)/2};
	GGG2D_DrawCircleOutline_internal(&iris_circle,&black);
	
	//draw pupil circle centered to position input
	//draw it over iris
	GGG2D_Circle pupil_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=pupilSize/2};
	
	GGG2D_DrawCircle_internal(&pupil_circle,pupil_color);
	
}
