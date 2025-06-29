#pragma once

#ifdef SW_PLATFORM_WINDOWS

// declared by App.h, defined by client app, being run in entrypoint->main
extern Sword::Application* Sword::CreateApplication();

int32_t main(int32_t argc, char** argv)
{
	Sword::Log::Init();
	SW_CORE_INFO("Logger initialized");

	auto app = Sword::CreateApplication();
	app->Run();
	delete app;
}

#endif
