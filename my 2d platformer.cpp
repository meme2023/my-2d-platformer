#include"raylib.h"
#include"raymath.h"
#include"ground.h"
#include"player.h"
#include"shader.h"
#include <iostream>
#include"bullet.h"
#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

int WinMain()
 {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// creating the window size
	const int win_width = 1270;
	const int win_height = 720;
	// wind can resie
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

	// creating the winodow
	InitWindow(win_width, win_height, "Game!");
	SetWindowTitle("my 2d platfomer");

	SetWindowMinSize(800, 600);
	// creating the game window size
	int gameScreenWidth = 640;
	int gameScreenHeight = 360;
	// cratinag render texture 
	RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
	SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
	const int row{ 50 };
	const int col{ 50 };
	int pposx = gameScreenWidth / 2, pposy = gameScreenHeight / 2;
	player pla(pposx,pposy);
	player* p;
	p = &pla;
	// the difrent screen 
	enum screens
	{
		start_screen,
		main_screen,
		loding_screen,
		death,
		exit

	};
	screens current = {};
	// helps with loding screen
	int framerate = 0;
	
	const int size = 2;
	// creating a ground obj
		ground flo[size] = { ground({0,320},{0,320,20 * 40,20 },RED),ground({200,420},{200,420,20 * 40,20 },RED) };
	
	int map[row][col];
	shader post;
	bullet fireball{ LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\bullet.png"),
	LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\bullet.png") };
	bullet* f;
	f = &fireball;
	f->setpos(p);
	SetTargetFPS(60);
	

	while (WindowShouldClose() == false) {
		// saleing the window
		f->addprj({ p->getplayerposX(),p->getplayerposY() });
		float scale = MIN((float)GetScreenWidth() / gameScreenWidth, (float)GetScreenHeight() / gameScreenHeight); ;
		// render the everthing here
	
		BeginTextureMode(target);
		BeginMode2D(pla.getcamra());
		ClearBackground(DARKGRAY);
		switch (current)
		{
		case start_screen:
			DrawText("Start", 150, 100, 100, RED);
			if (IsKeyPressed(KEY_S)) {
				current = main_screen;
			}
			break;
		case main_screen:
			DrawText("Main Screen", 0, 0, 100, RED);
			for(int i = 0; i < size; i++){
				f->tick(GetFrameTime());
				p->tick(GetFrameTime());				
				p->undo_movement(flo[0].getcolustion(),  p->getcollustion());
				p->undo_movement(flo[1].getcolustion(), p->getcollustion());
				
				
				if (p->getplayerhelth() <= 0) {

					current = death;
				}
			}
				break;
		case loding_screen:
			break;
		case death:
			DrawText("you died", (float)p->getplayerposX()-200, (float)p->getplayerposY()-100, 100, BLUE);
			DrawText("Press R to rest", (float)p->getplayerposX()-200, (float)p->getplayerposY()+50, 50, DARKBLUE);
			if (IsKeyPressed(KEY_R)) {
				current = main_screen;
			}
			break;
		case exit:
			break;
		default:
			break;

			}


			
		if (current == main_screen) {
			for (int x = 0; x < row; x++) {
				for (int y = 0; y < col; y++) {
					map[x][y];

					DrawRectangleLines(x * 32, y * 32, 32 * 20, 32, WHITE);
					//draw the player
					p->draw();



				
						if(f->isactive){
							f->draw();
							f->isactive = true;
						}
					p->playerfailg();
					//render the platform
					for (int i = 0; i < size; i++) {
						flo[i].render();
					}
					
				}
			}
			if (current == death) {
				p->playerdeath();
				
			}

		}
		EndTextureMode();
		EndMode2D();
		BeginDrawing();
		ClearBackground(BLACK);

		// draw the game screen
		BeginShaderMode(post.getcurrentshader());
		DrawTexturePro(target.texture, { 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
			 {
			(GetScreenWidth() - ((float)gameScreenWidth * scale)) * 0.5f, (GetScreenHeight() - ((float)gameScreenHeight * scale)) * 0.5f,
				(float)gameScreenWidth * scale, (float)gameScreenHeight * scale
			 }, { 0, 0 }, 0.0f, WHITE);



		EndShaderMode();


		EndDrawing();


		


	}

	CloseWindow();
	UnloadRenderTexture(target);
	pla.unloadrexture();
}

