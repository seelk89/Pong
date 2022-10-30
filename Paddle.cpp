#include "Paddle.h"

Rectangle GetPaddleRect(Paddle paddle)
{
	return Rectangle{
		paddle.x - paddle.width / 2, paddle.y - paddle.height / 2, 10, 100
	};
}

// draw paddle from the center of the paddle instead of the default
void DrawPaddle(Paddle paddle)
{
	DrawRectangleRec(GetPaddleRect(paddle), WHITE);
}
