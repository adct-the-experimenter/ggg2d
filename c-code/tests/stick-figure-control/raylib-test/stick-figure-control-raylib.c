
#include "raylib.h"

#include "ggg-2d.h"

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int screenWidth = 800;
int screenHeight = 450;

//using render texture of resolution 640x360 to scale it up better by integers.
RenderTexture2D target;
int gameScreenWidth = 640;
int gameScreenHeight = 360;

#define max(a, b) ((a)>(b)? (a) : (b))
#define min(a, b) ((a)<(b)? (a) : (b))

#define CUSTOM_PI 3.14

int main()
{
	///intialize raylib
	// Window configuration flags
	// Set MSAA 4X hint before windows creation, multi-sample anti aliasing
	// set v sync
	//set resizeable window
	//set to high DPI for very high resolutions
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI); 
    
	
    InitWindow(screenWidth, screenHeight, "Animate Monster Sprite Example");
	SetWindowMinSize(0.5*gameScreenWidth, 0.5*gameScreenHeight);
	
	// Render texture initialization, used to hold the rendering result so we can easily resize it
	target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
	SetTextureFilter(target.texture, FILTER_BILINEAR);  // Texture scale filter to use
	SetTextureWrap(target.texture,WRAP_CLAMP);
		
	
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	
	///draw sprite animation
	
	//stick figure position
	int startPosX = 320;
	int curPosX = startPosX;
	
	int posY = 180;
	double rad_angle = 0;
	
	//stick figure appearance
	
	GGG2D_Circle head = {startPosX,posY,20};
	GGG2D_Rectangle eye = {startPosX + 5,posY,5,5};
	double eye_angle = 0;
	
	GGG2D_Color body_color = {50,0,100,255};
	GGG2D_Color black = {10,10,10,255};
	
	//stick figure movement
	int move_speed = 5;
	
	//To do: animation, change sprite appeareance for different frames, drawing static sprite for now
	
	int frameCount = 0;
	
	int animationFrameSpeed = 8;
	
	bool quit = false;
	
	while (!quit)
	{
		// Detect window close button or ESC key
		if(WindowShouldClose())
		{
			quit = true;
		}
		
		float dt = GetFrameTime();
		
		int move = (int)(move_speed*dt*60.0f);
		
		//handle input
		if (IsKeyDown(KEY_D)){head.centerX += move; eye_angle = 0;}
        if (IsKeyDown(KEY_A)){ head.centerX -= move; eye_angle = CUSTOM_PI;}
        if (IsKeyDown(KEY_W)){head.centerY -= move; eye_angle = CUSTOM_PI / 2;}
        if (IsKeyDown(KEY_S)){head.centerY += move; eye_angle = 3*CUSTOM_PI / 2;}
		
		eye.x = head.centerX + (0.5*head.radius)*cos(eye_angle);
		eye.y = head.centerY - (0.5*head.radius)*sin(eye_angle);
		
		//handle animation
		frameCount++;

		//every animation
        if (frameCount >= (60 / animationFrameSpeed))
        {
			frameCount = 0;
			
			rad_angle += (CUSTOM_PI / 180);
			
			if(rad_angle > 2*CUSTOM_PI){rad_angle = 0;}
			
			
			
			//curPosX = startPosX*(1 - 0.5*cos(rad_angle));
			
			//head.centerX = curPosX;
			
		}    
		
		//perform rendering
		// Compute required framebuffer scaling
        float scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
				
		BeginTextureMode(target);
		ClearBackground(WHITE);
		
		///Drawing of sprite is done here
		
		GGG2D_DrawCircle(&head,&body_color);
		GGG2D_DrawRectangle(&eye,&black);
		
		///End drawing of sprite
		
		EndTextureMode();
		
		ClearBackground(BLACK);
		
		DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5f, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5f,
                           (float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);

		EndDrawing();
							
	}
	
	///close raylib
	UnloadRenderTexture(target);    // Unload render texture
	
	CloseWindow();        // Close window and OpenGL context
	
	return 0;
}
