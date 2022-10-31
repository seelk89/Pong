#pragma once
#include "raylib.h"

struct Paddle
{
	float x, y;
	int speed, width, height;

	Rectangle GetRect()
	{
		return Rectangle{
			x - width / 2, y - height / 2, 10, 100
		};
	}

	// Draw paddle from the center of the paddle instead of the default
	void Draw()
	{
		DrawRectangleRec(GetRect(), WHITE);
	}
};