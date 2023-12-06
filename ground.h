#include"raylib.h"
#include"raymath.h"

class ground
{
public:
	ground(Vector2 ground ,Rectangle rec, Color color);
	void render();
	float getfloorposX();
	float getfloorposY();
	Rectangle getcolustion();
private:
	Rectangle floor{};
	Color col{};
	Rectangle coll{ };
	float pad{};
	Vector2 wpos{};
};

