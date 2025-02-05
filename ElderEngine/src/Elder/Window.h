#pragma once




#include "eldpch.h"

#include "Elder/Core.h"
#include "Elder/Events/ApplicationEvent.h"

namespace Elder
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "ElderEngine", unsigned int width = 1280, unsigned int height = 720)
			: Title{ title }, Width{ width }, Height{ height } {}
	};


	class ELDER_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callbakc) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());

	};


}