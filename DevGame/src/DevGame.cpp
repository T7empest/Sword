#include <Sword.h>

class DevGame : public Sword::Application
{
public:
	DevGame()
	{
		
	}

	~DevGame()
	{
		
	}

};

Sword::Application* Sword::CreateApplication()
{
	return new DevGame();
}