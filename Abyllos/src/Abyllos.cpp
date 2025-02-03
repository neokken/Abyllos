#include <ElderEngine.h>

class Abyloss : public Elder::Application
{
public:
	Abyloss() {}
	~Abyloss() {}

};


Elder::Application* Elder::CreateApplication()
{
	return new Abyloss();
}