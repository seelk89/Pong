#include "Ball.h"
#include "raylib.h"

void DrawBall(Ball ball)
{
	DrawCircle(ball.x, ball.y, ball.radius, WHITE);
}