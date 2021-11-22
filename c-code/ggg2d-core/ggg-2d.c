#include "ggg-2d.h"

#include "ggg-2d-draw-select.h"

void GGG2D_DrawHumanEye(int posX, int posY, int pupilSize, int irisSize, GGG2D_Color* pupil_color, GGG2D_Color* iris_color)
{
	//draw iris first
	GGG2D_Circle iris_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=irisSize/2};
	
	GGG2D_DrawCircle(&iris_circle,iris_color);
	
	//draw pupil circle centerd to position input
	//draw it over iris
	GGG2D_Circle pupil_circle = (GGG2D_Circle){.centerX = posX,.centerY=posY,.radius=pupilSize/2};
	
	GGG2D_DrawCircle(&pupil_circle,pupil_color);
	
	
}
