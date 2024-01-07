#include "bullet.h"

bullet::bullet(Texture2D move, Texture2D move2) : bllet(move), blletmove(move2)
{

	speed = 1.0;
	width = static_cast<float>(move.width);
	height = static_cast<float>(move.height) / maxframe;
	
}




Vector2 bullet::addprj(Vector2 pos)
{
	return bulletpos = pos;
}


Vector2 bullet::getpos()
{
	return bulletpos;
}
void bullet::draw()
{
	
	
		rce = { bulletpos.x,bulletpos.y, (float)width ,(float)height };
		scorce = { 0.f,frame * (float)height ,rightleft * (float)width,(float)height };
		DrawTexturePro(bllet, scorce, rce, Vector2{ 0.f,0.f }, 0.f, WHITE);
	
}

void bullet::tick(float getframe)
{
	Vector2 bvel{};
	// if a and bullet not active else will active it and key prssed to player diriction 

	if (IsKeyUp(KEY_A) && !isactive) {
		
		isactive = false;
		
		
			playerpos.x = 0;
		
	}
	else {
		if (target->getrigtleft() == 1.0 ) {
			
			playerpos.x += shoolvel;
			
			
		}
		
		if ( target->getrigtleft() == -1.0)
		{
			playerpos.x -= shoolvel;
			
		}
		isactive = true;
	}
if (playerpos.x >=100 ||playerpos.x<=-100) {
	
		isactive = false;
		playerpos.x = playerpos.x;
		
	
	}
	
	
	running_time += getframe;
	if (Vector2Length(playerpos) != 0.0) {
		bulletpos = Vector2Add(bulletpos, (playerpos));
		target->getrigtleft() ==1.0 ? rightleft = 1.0f : rightleft = -1.0f;
		bllet = blletmove;
	}
	//update ainmaton 
	if (running_time >= updating_time) {
		frame++;
		running_time = 0.f;
		if (frame > maxframe) {
			frame = 0;
		}
	}
}

bullet::bullet()
{
}
