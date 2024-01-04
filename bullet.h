#include "raylib.h"
#include "raymath.h"

#pragma once
class bullet{
public:
	bullet( Texture2D move, Texture2D move2);
	bullet();
	 void tick(float getframe);
	virtual void draw();
	Vector2 setpos(float x, float y);
	
	void addprj(Vector2 pos);
	Vector2 getpos();

private:
	float speed{ 7.f };
	float updating_time{ 5.f / 16.f };
	float running_time{};
	int frame{};
	int maxframe{ 4 };
	int width{};
	int height{};
	float scale{ 1.5f };
	float rightleft{ 1.f };
	Vector2 bulletpos = { };
	Rectangle rce={ bulletpos.x,bulletpos.y, (float)width ,(float)height };
	Rectangle scorce = { 0.f,frame * (float)height ,rightleft * (float)width,(float)height };
	Texture2D bllet{};
	Texture2D blletmove{};
	int vel{};
	


	
	
};