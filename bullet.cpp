#include "bullet.h"

void bullet::addprj(Vector2 pos)
{
	bulletpos = pos;
}


Vector2 bullet::setpos(float x, float y)
{
	return bulletpos = { x,y };
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

bullet::bullet( Texture2D move, Texture2D move2) : bllet(move), blletmove(move2)
{
	
	
	width = static_cast<float>(move.width);
	height = static_cast<float>(move.height) / maxframe;
	speed = 6.f;
}




bullet::bullet()
{
}
