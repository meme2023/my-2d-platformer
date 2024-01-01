#include "raylib.h"
#include "raymath.h"
#include"player.h"
#pragma once
class bullet {
private:
	int width;
	int height;
	int speed=0;
public:
	bullet(Rectangle rec , Texture2D drawing,Texture2D move);
	bullet();
	void tick(float getframe);
	Vector2 getpos();
};