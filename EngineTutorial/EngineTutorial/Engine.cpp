#include "Engine.h"

bool Engine::Initialize( HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height)
{
	//_keyboard.EnableAutoRepeatChars();
	if (!this->_renderWindow.Initialize(this, hInstance, windowTitle, windowClass, width, height))
		return false;
	if (!gfx.Initialize(this->_renderWindow.GetHWND(), width, height))
		return false;
	return true;
}

bool Engine::ProcessMessages()
{
	return this->_renderWindow.ProcessMessages();
}

void Engine::Update()
{
	while (!_keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = _keyboard.ReadChar();
	}

	while (!_keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent kbe = _keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
	}

	while (!_mouse.EventBufferIsEmpty())
	{
		MouseEvent me = _mouse.ReadEvent();
		if (me.GetType() == MouseEvent::EventType::RAW_MOVE)
		{
			std::string outmsg = "X: ";
			outmsg += std::to_string(me.GetPosX());
			outmsg += ", ";
			outmsg += "Y: ";
			outmsg += std::to_string(me.GetPosY());
			outmsg += "\n";
			OutputDebugStringA(outmsg.c_str());

		}
	}
}

void Engine::RenderFrame()
{
	gfx.RenderFrame();
}