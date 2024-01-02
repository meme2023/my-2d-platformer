#include "bullet.h"

bullet::bullet(Texture2D move, Texture2D move2) :bllet(move), blletmove(move2)
{
	width = static_cast<float>(move.width);
	height = static_cast<float>(move.height) / maxframe;
	speed = 6.0;
}
void bullet::tick(float getframe)
{
	Vector2 dirction{};

	if (Vector2Length(dirction) != 0.0) {
		bulletpos = Vector2Add(bulletpos, Vector2Scale(Vector2Normalize(dirction), speed));
		dirction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
		bllet = blletmove;
	}
		Rectangle rce{ bulletpos.x,bulletpos.y, (float)width ,(float)height };
		Rectangle scorce = { 0.f,frame * (float)height ,rightleft * (float)width,(float)height };
		DrawTexturePro(bllet, scorce, rce, Vector2{ 0.f,0.f }, 0.f, WHITE);
}

Vector2 bullet::setpos(int posx,int posy)
{
	return bulletpos = { (float)posx,
		(float)posy-10};
}


bullet::bullet()
{
}
