#include <ElderEngine.h>


class ExampleLayer : public Elder::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		ELD_INFO("ExampleLayer::Update");
	}
	void OnEvent(Elder::Event& event) override
	{
		ELD_TRACE("{0}", event);
	}
};



class Abyloss : public Elder::Application
{
public:
	Abyloss() 
	{
		PushLayer(new ExampleLayer());
	}
	~Abyloss() {}

};


Elder::Application* Elder::CreateApplication()
{
	return new Abyloss();
}