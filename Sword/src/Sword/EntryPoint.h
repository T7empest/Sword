#pragma once

#ifdef SW_PLATFORM_WINDOWS
#include <print>

extern Sword::Application* Sword::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Sword::CreateApplication();
	std::println("Created application");

	app->Run();

	delete app;
}

#endif
