
#include"raylib.h"
#include"raymath.h"
#include <iostream>
#pragma once

class player {
public:


	void undo_movement(Rectangle obj1, Rectangle ob2);
	void tick(float getframe);
	void draw();
	float getplayerposX();
	float getplayerposY();
	Rectangle getcollustion();
	player(int wid, int hight);
	Camera2D getcamra();
	int playerfailg();
	void playerdeath();
	int getplayerhelth();
	player();

private:
	float speed = 4.f;
	Vector2 playerpos{};
	Vector2 playerposlastframe{};
	Rectangle rce{ playerpos.x,playerpos.y,rce.width = 32  ,rce.height = 32 };
	const int gravry = 900;
	int jampvel = -400;
	Rectangle colliustion{};
	bool isair = {};
	float velocity = 0;
	bool coll = {};
	Vector2 dirction{};
	Camera2D camera = { camera.target = {  playerpos.x - 20.0f, playerpos.y - 280.0f },
	camera.offset = {playerpos.x, playerpos.y },
	camera.rotation = 0.0f,
	camera.zoom = 1.0f };

	int  maxhp = 10;
	int currenthp = 1;

};