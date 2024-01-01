#include "ground.h"



ground::ground(Vector2 pos, Rectangle rec,Color cl) :  floor(rec), col(cl)
{
	floor = { pos.x,pos.y,scale*floor.width,scale*floor.height };
	
}

void ground::render()
{
	// draw the ground
	DrawRectangleRec(floor, col);
}


float ground::getfloorposX()
{
	return floor.x;
}

float ground::getfloorposY()
{
	return floor.y;
}

Rectangle ground::getcolustion()

{
	DrawRectangleRec(coll, YELLOW);
	
	return coll = {floor.x,floor.y,floor.width,floor.height};
}

