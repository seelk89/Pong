#pragma once

typedef struct
{
	float x, y;
	int speedX, speedY, radius;
} Ball;

void DrawBall(Ball ball);