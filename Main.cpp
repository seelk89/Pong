#include <stdio.h>
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

int main()
{
	printf("Hello from Pong!");

	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball;
	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5;
	ball.speedX = 200;
	ball.speedY = 200;

	// 50 from the left of the screen, screen height / 2, 10 wide, 100 tall
	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2;
	leftPaddle.speed = 300;
	leftPaddle.width = 10;
	leftPaddle.height = 100;

	// Screen width - 50 (so 50 from the right of the screen), etc.
	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.speed = 300;
	rightPaddle.width = 10;
	rightPaddle.height = 100;

	const char* winnerText = nullptr;

	while (!WindowShouldClose())
	{
		ball.x += ball.speedX * GetFrameTime();
		ball.y += ball.speedY * GetFrameTime();

		if (ball.y < 0)
		{
			ball.y = 0;
			ball.speedY *= -1;
		}
		if (ball.y > GetScreenHeight())
		{
			ball.y = GetScreenHeight();
			ball.speedY *= -1;
		}

		// Left paddle movement
		if (IsKeyDown(KEY_W))
		{
			leftPaddle.y -= leftPaddle.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S))
		{
			leftPaddle.y += leftPaddle.speed * GetFrameTime();
		}

		// right paddle movement
		if (IsKeyDown(KEY_UP))
		{
			rightPaddle.y -= rightPaddle.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			rightPaddle.y += rightPaddle.speed * GetFrameTime();
		}

		// Left paddle collision
		if (CheckCollisionCircleRec(Vector2
			{
				ball.x, ball.y
			}, ball.radius, leftPaddle.GetRect()))
		{
			// Check for handling edge case of hitting ball with the side of paddle, coursing ball to bounce back and forth
			if (ball.speedX < 0)
			{
				ball.speedX *= -1.1f;
				ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
			}
		}

		// Right paddle collision
		if (CheckCollisionCircleRec(Vector2
			{
				ball.x, ball.y
			}, ball.radius, rightPaddle.GetRect()))
		{
			// Check for handling edge case of hitting ball with the side of paddle, coursing ball to bounce back and forth
			if (ball.speedX > 0)
			{
				ball.speedX *= -1.1f;
				ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * - ball.speedX;
			}
		}

		// Winner declaration & resetting
		if (ball.x < 0)
		{
			winnerText = "Right Paddle Wins!";
		}
		if (ball.x > GetScreenWidth())
		{
			winnerText = "Left Paddle Wins!";
		}
		if (winnerText && IsKeyPressed(KEY_SPACE))
		{
			ball.x = GetScreenWidth() / 2;
			ball.y = GetScreenHeight() / 2;
			ball.speedX = 200;
			ball.speedY = 200;
			winnerText = nullptr;
		}

		// Remember to destroy everything you create
		BeginDrawing();
			ClearBackground(BLACK);

			ball.Draw();
			leftPaddle.Draw();
			rightPaddle.Draw();

			if (winnerText)
			{
				// 60 is font size
				int textWidth = MeasureText(winnerText, 60);
				DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, GREEN);
			}

			DrawFPS(10, 10);
		EndDrawing();
	}
	

	CloseWindow();

	return 0;
}