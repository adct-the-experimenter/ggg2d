
#include "raylib.h"

#include "ggg-2d.h"

#include <stdbool.h>

int screenWidth = 800;
int screenHeight = 450;

//using render texture of resolution 640x360 to scale it up better by integers.
RenderTexture2D target;
int gameScreenWidth = 640;
int gameScreenHeight = 360;

#define max(a, b) ((a)>(b)? (a) : (b))
#define min(a, b) ((a)<(b)? (a) : (b))

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
	
	//To do: animation, change sprite appeareance for different frames, drawing static sprite for now
	
	bool quit = false;
	
	while (!quit)
	{
		// Detect window close button or ESC key
		if(WindowShouldClose())
		{
			quit = true;
		}    
		
		//perform rendering
		// Compute required framebuffer scaling
        float scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
				
		BeginTextureMode(target);
		ClearBackground(WHITE);
		
		///Drawing of sprite is done here
		
		GGG2D_Color pupil_color = {30,20,0,255};
		int pupilSize = 100;
		
		GGG2D_Color iris_color = {20,20,100,255};
		int irisSize = 200;
		//GGG2D_DrawHumanEye(int posX, int posY, int pupilSize, int irisSize, GGG2D_Color* pupil_color, GGG2D_Color* iris_color)
		GGG2D_DrawHumanEye(320, 180, pupilSize, irisSize, &pupil_color,&iris_color);
		
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
