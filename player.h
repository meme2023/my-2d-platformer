
#include"raylib.h"
#include"raymath.h"
#include <iostream>
#include"bullet.h"
#pragma once

class player{
private:
	float speed{ 7.f };
	Vector2 playerpos{};
	Vector2 playerposlastframe{};
	const int gravry = { 700 };
	int jampvel{ -400 };
	Rectangle colliustion{};
	bool isair = {};
	float velocity = 0;
	bool coll = {};
	Vector2 dirction{};
	Camera2D camera = { camera.target = {  playerpos.x - 200.0f, playerpos.y - 200.0f },
	camera.offset = {playerpos.x, playerpos.y },
	camera.rotation = 0.0f,
	camera.zoom = 1.0f };
	int  maxhp = 10;
	int currenthp = 1;
	Texture2D player1 = LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\Idle.png");
	Texture2D idle_player = LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\Idle.png");
	Texture2D walk_player = LoadTexture("C:/Users/memeo/Desktop/c++/my 2d platformer/Walking.png");
	Texture2D jump_player = LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\jumping.png");
	float updating_time{ 5.f / 16.f };
	float running_time{};
	int frame{};
	int maxframe{ 4 };
	int width{};
	int height{};
	float scale{ 1.5f };
	float rightleft{ 1.f };
	Rectangle hpbar{};
	int windowwidth{};
	int windowhieght{};
	bullet fireball{LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\bullet.png"),LoadTexture("C:\\Users\\memeo\\Desktop\\c++\\my 2d platformer\\bullet.png") };
	Vector2 bvel = {};
	int shoolvel = 100;
public:


	void undo_movement(Rectangle obj1, Rectangle ob2);
	 void tick(float getframe);
	  void draw();
	 float getplayerposX();
	 float getplayerposY();
	  Vector2 getplayepos();
	Rectangle getcollustion();
	player(int wid, int hight);
	Camera2D getcamra();
	int playerfailg();
	void playerdeath();
	int getplayerhelth();
	player();
	void unloadrexture();

	
	
	
};
