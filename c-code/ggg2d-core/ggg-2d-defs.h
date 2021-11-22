
#ifndef GGG_2D_DEFS_H
#define GGG_2D_DEFS_H

#include <stdint.h>

//C code start

typedef struct  {
	int x;
	int y;
} GGG2D_Point;

typedef struct {
	GGG2D_Point p1;
	GGG2D_Point p2;
	GGG2D_Point p3;
}GGG2D_Triangle;
	
typedef struct {
	int x;
	int y;
	int width;
	int height;
}GGG2D_Rectangle;

typedef struct {
	uint8_t red; 
	uint8_t green; 
	uint8_t blue; 
	uint8_t alpha;
}GGG2D_Color;

typedef struct {
	int centerX;
	int centerY;
	int radius;
	
}GGG2D_Circle;

#endif
