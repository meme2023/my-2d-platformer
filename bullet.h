#include "raylib.h"
#include "raymath.h"
#pragma once
class bullet {
private:
	int width;
	int height;
	int speed=0;
	float updating_time{ 5.f / 16.f };
	float running_time{};
	int frame{};
	int maxframe{ 4 };
	float rightleft{ 1.f };
	Vector2 bulletpos{};
	Texture2D bllet{};
	Texture2D blletmove{};
public:
	bullet( Texture2D move,Texture2D move2);
	bullet();
	void tick(float getframe);
	Vector2 setpos(int posx, int posy);
	
};