#include "raylib.h"

void ToggleFullScreenWindow(int windowWidth, int windowHeight)
{
	if (!IsWindowFullscreen())
	{
		int monitor = GetCurrentMonitor();
		SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
		ToggleFullscreen();
	}
	else
	{
		ToggleFullscreen();
		SetWindowSize(windowWidth, windowHeight);
	}

}

// For returning correct window width when fullscreen is toggled
int GetDisplayWidth()
{
	if (IsWindowFullscreen())
	{
		int monitor = GetCurrentMonitor();
		return GetMonitorWidth(monitor);
	}
	else
	{
		return GetScreenWidth();
	}
}

// For returning correct window height when fullscreen is toggled
int GetDisplayHeight()
{
	if (IsWindowFullscreen())
	{
		int monitor = GetCurrentMonitor();
		return GetMonitorHeight(monitor);
	}
	else
	{
		return GetScreenHeight();
	}
}