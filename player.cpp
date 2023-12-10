#include"player.h"
#include"shader.h"

player::player(int wid, int hight)
{
	width = static_cast<float>(idle_player.width);
	height = static_cast<float>(idle_player.height)/maxframe;

	playerpos = {
		  (float)wid / 2.0f - scale * (0.5f * width) ,
		(float)hight / 2.0f - scale * (0.5f * height) };

}
void player::undo_movement(Rectangle obj1, Rectangle ob2)
{
	if (CheckCollisionRecs(obj1, ob2)) {
		playerpos = playerposlastframe;
		velocity = 0;
		coll = true;
		isair = false;
	}

	else
	{
		coll = false;
		
	}
}

void player::tick(float getframe)
{
	//undo movement
	playerposlastframe = playerpos;

	Vector2 dirction{};
	//update the velo

	playerpos.y += velocity * getframe;


	//move the player
	if (IsKeyDown(KEY_A)) {
		dirction.x -= 1.f;
	}
	if (IsKeyDown(KEY_D)) { dirction.x += 1.f; }

	if (IsKeyPressed(KEY_SPACE) && isair == false) {
		
		velocity += jampvel;
		

	}
	
	// collution true is in the ground else cout to fall
	if (coll ) {
		velocity = 0;
		
	}
	else
	{
		velocity += gravry * getframe;
		isair = true;
		coll = false;
	}

	if (Vector2Length(dirction) != 0.0) {
		playerpos = Vector2Add(playerpos, Vector2Scale(Vector2Normalize(dirction), speed));


	}

	// follow the player
	camera.target = { playerpos.x - 20.0f,  playerpos.y - 280.0f };
	//updte ainmaton 
	running_time += getframe;
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
	Rectangle scorce = { 0.f,frame*(float)height ,(float)width,(float)height };
	// draw rhe player
	DrawTexturePro(idle_player, scorce, rce, Vector2{ 0.f,0.f }, 0.f, WHITE);

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







