#pragma once
#include "raylib.h"

struct Ball
{
	float x, y;
	int speedX, speedY, radius;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE);
	}
};