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
	
	
	rce = { bulletpos.x,bulletpos.y, (float)width ,(float)height};
	scorce = { 0.f,frame * (float)height ,rightleft * (float)width,(float)height };
	DrawTexturePro(bllet, scorce, rce, Vector2{ 0.f,0.f }, 0.f, WHITE);
	
}
void bullet::tick(float getframe) {
	

	
	
		Vector2 dirction{};
		

		if (IsKeyPressed(KEY_A)) {
			if (rightleft == -1.f) {
				dirction.x -= 1;
			}
			else {
				dirction.x += 1;
			}


			if (Vector2Length(dirction) != 0.0) {
				
				bulletpos = Vector2Add(bulletpos, Vector2Scale(Vector2Normalize(dirction), speed));
				dirction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
				bllet = blletmove;
			}
		bulletpos.x += dirction.x*getframe;

		}
		if (running_time >= updating_time) {
			frame++;
			running_time = 0.f;
			if (frame > maxframe) {
				frame = 0;
			}
		}

	
	
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
