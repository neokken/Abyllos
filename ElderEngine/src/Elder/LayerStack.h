#pragma once

#include "Elder/Core.h"
#include "Elder/Layer.h"


namespace Elder
{

	class LayerStack
	{
	public:
		ELDER_API LayerStack();
		ELDER_API ~LayerStack();

		ELDER_API void PushLayer(Layer* layer);
		ELDER_API void PushOverlay(Layer* layer);
		ELDER_API void PopLayer(Layer* layer);
		ELDER_API void PopOverlay(Layer* layer);


		ELDER_API std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		ELDER_API std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};


}