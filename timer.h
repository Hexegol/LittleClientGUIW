#pragma once
#include "Module.h"
namespace Cheat
{
	class timer : public Module
	{
	public:
		timer();
		~timer();
		void ChangeSpeed(float value);
	};
}


