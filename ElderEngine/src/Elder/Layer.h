#pragma once

#include "Elder/Core.h"
#include "Elder/Events/Event.h"

namespace Elder
{

	class Layer
	{
	public:
		ELDER_API Layer(const std::string& name = "Layer");

		ELDER_API virtual ~Layer();

		ELDER_API virtual void OnAttach() {}
		ELDER_API virtual void OnDetach() {}
		ELDER_API virtual void OnUpdate() {}
		ELDER_API virtual void OnEvent(Event& event) {}

		ELDER_API const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};


}
