#include"player.h"
#include"shader.h"

void player::undo_movement(Rectangle obj1, Rectangle ob2)
{
	if (CheckCollisionRecs(obj1, ob2)) {

		playerpos = playerposlastframe;
		velocity = 0;
		coll = true;

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
	//update the velo
	
	playerpos.y += velocity * getframe;

	// collution true is in the ground else cout to fall
	if (coll) {
		velocity = 0;
		isair = false;

	}
	else
	{
		velocity += gravry * getframe;
		isair = true;
		
	}

	if (Vector2Length(dirction) != 0.0) {
		playerpos = Vector2Add(playerpos, Vector2Scale(Vector2Normalize(dirction), speed));


	}

	// follow the player
	camera.target = { playerpos.x - 20.0f,  playerpos.y - 280.0f };
	
}

void player::draw()

{
	rce = { playerpos.x,playerpos.y,rce.width ,rce.height };
	// draw rhe player
	DrawRectangleRec(rce, BLACK);

}

float player::getplayerposX()
{
	return playerpos.x;
}

float player::getplayerposY()
{
	return playerpos.y;
}

Rectangle player::getcollustion()
{
	DrawRectangleRec(colliustion, WHITE);
	// creating te coll
	return colliustion = { playerpos.x,playerpos.y,rce.width,rce.height };
}

player::player(int wid, int hight)
{

	playerpos = {
		 (float)wid,(float)hight };

}

Camera2D player::getcamra()
{
	// get the camra
	return camera;
}
int player::playerfailg()
{

	if (playerpos.y > 1500) {
		maxhp = maxhp - currenthp;
		playerpos = { 32, 32 + 250 };
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







