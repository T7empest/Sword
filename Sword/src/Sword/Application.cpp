#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Sword
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 900);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SW_TRACE("Window resize event called");
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SW_TRACE("ERROR, shouldnt be called eventcategoryinput");
		}

		while (true);
	}
}
