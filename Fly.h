#pragma once
#include "Module.h"

namespace Cheat
{
	class Fly : public Module
	{
	public:
		Fly();
		~Fly();
		void EnableFly();
		void DisableFly();
	};
}

