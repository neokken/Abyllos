#pragma once


#ifdef ELD_PLATFORM_WINDOWS

extern Elder::Application* Elder::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Elder::CreateApplication();
	app->Run();
	delete app;
}


#endif