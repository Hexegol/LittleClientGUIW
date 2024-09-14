#pragma once
#include "Module.h"

namespace Cheat
{
	class Hitbox : public Module
	{
	public:
		Hitbox();
		~Hitbox();
		void EnableHitbox();
		void DisableHitbox();
	};
}


