#pragma once
#include "Module.h"
namespace Cheat
{
	class Velocity : public Module
	{
	public:
		Velocity();
		~Velocity();
		void EnableAntiKb();
		void DisableAntiKb();
	};
}


