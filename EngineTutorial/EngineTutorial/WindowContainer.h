#pragma once
#include "RenderWindow.h"
#include "Keyboard/KeyboardClass.h"
#include "Mouse/MouseClass.h"
#include "Graphics/Graphics.h"
class WindowContainer
{
public:
	WindowContainer();
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	RenderWindow _renderWindow;
	KeyboardClass _keyboard;
	MouseClass _mouse;
	Graphics gfx;
};