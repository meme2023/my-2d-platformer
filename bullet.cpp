#include "bullet.h"

void bullet::tick(float getframe)
{
	
}

Vector2 bullet::getpos()
{
	return Vector2();
}



bullet::bullet(Rectangle rec, Texture2D idle,Texture2D move)
{
	//width = static_cast<float>(player1.width);
	//height = static_cast<float>(player1.height) / maxframe;
	speed = 6.0;
}

bullet::bullet()
{
}
