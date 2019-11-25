#pragma once

class Application
{
public:

	void Initialize();
	void Run();
	void Shutdown();

private:

	bool bShutdown = false;
	class Window* win = nullptr;

};
