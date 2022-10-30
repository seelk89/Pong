#pragma once
#include "raylib.h"

typedef struct
{
	float x, y;
	int speed, width, height;
} Paddle;

Rectangle GetPaddleRect(Paddle paddle);

void DrawPaddle(Paddle paddle);