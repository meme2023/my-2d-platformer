#include"player.h"
#include"shader.h"


player::player(int wid, int hight)
	:windowwidth(wid), windowhieght(hight)
{
	width = static_cast<float>(player1.width);
	height = static_cast<float>(player1.height) / maxframe;

}
void player::undo_movement(Rectangle obj1, Rectangle ob2)
{
	if (CheckCollisionRecs(obj1, ob2)) {
		playerpos = playerposlastframe;
		coll = true;
		velocity = 0;
		isair = false;
	}

	else
	{
		coll = false;
		
	}
}

void player::tick(float getframe)
{
	Vector2 dirction{};
	//undo movement
	playerposlastframe = playerpos;


	//move the player
	if (IsKeyDown(KEY_A)) {
		dirction.x -= 1.f;
	}
	if (IsKeyDown(KEY_D)) { dirction.x += 1.f; }

	if (IsKeyPressed(KEY_SPACE) && isair == false) {
		velocity += jampvel;
		

	}
	
	//updte ainmaton 
	running_time += getframe;
	//update the velo
	playerpos.y += velocity * getframe;
	// collution true is in the ground else cout to fall
	
		velocity += gravry * getframe;
		isair = true;
	
	
		if (Vector2Length(dirction) != 0.0) {
			playerpos = Vector2Add(playerpos, Vector2Scale(Vector2Normalize(dirction), speed));
			dirction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
			player1 = walk_player;

		 if (velocity <= 0.0 && isair == true)
		{
			player1 = jump_player;
		}
		 
		}
		else if (velocity <= 0.0 && isair == true) {
			player1 = jump_player;
		}
	else {
		player1 = idle_player;
	}

	// follow the player
	camera.target = { playerpos.x-640/2,   playerpos.y- 360/2 };
	
	if (running_time >= updating_time) {
		frame++;
		running_time = 0.f;
		if (frame > maxframe) {
			frame = 0;
		}
	}
	
}

void player::draw()

{

	Rectangle rce{ playerpos.x,playerpos.y,scale*(float)width ,scale*(float)height };
	Rectangle scorce = { 0.f,frame*(float)height ,rightleft*(float)width,(float)height };
	// draw rhe player
	DrawRectangleRec(hpbar = { playerpos.x,playerpos.y - 20,(float)maxhp * 6,16 }, GREEN);
	DrawRectangleLines(playerpos.x, playerpos.y - 19, 60, 16, BLACK);
	DrawTexturePro(player1, scorce, rce, Vector2{ 0.f,0.f }, 0.f, WHITE);
	
}

float player::getplayerposX()
{
	return playerpos.x;
}

float player::getplayerposY()
{
	return playerpos.y;
}

Vector2 player::getplayepos()
{
	return playerpos = {
		  (float)windowwidth / 2.f - scale * (0.5f * width) ,
		(float)windowhieght / 2.f - scale * (0.5f * height) };
}

Rectangle player::getcollustion()
{

	// creating te coll
	return colliustion = { playerpos.x,playerpos.y,(float)width*scale,(float)height*scale};
}


Camera2D player::getcamra()
{
	// get the camra
	return camera;
}
int player::playerfailg()
{

	

	if (playerpos.y >=1500&&isair==true) {
		maxhp = maxhp - currenthp;
		playerpos = {10.f,10.f };
		return maxhp;
	}
	
	if (IsKeyPressed(KEY_R)) {
		maxhp = 10;
		return maxhp;
	}
	return 0;
}

void player::playerdeath()
{
	if (maxhp <= 0) {

		playerpos = playerposlastframe;

	}
}

int player::getplayerhelth()
{
	return maxhp;
}

player::player()
{
}

void player::unloadrexture()
{
	UnloadTexture(player1);
	UnloadTexture(idle_player);
	UnloadTexture(walk_player);
}







