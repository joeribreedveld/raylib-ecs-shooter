#include "ecs/components/lifetime_component.h"
#include "ecs/systems/lifetime_system.h"
#include "ecs/entity.h"

void lifetime_system(float dt)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_lifetime[i]) {
			continue;
		}

		lifetimes[i] -= dt;

		if (lifetimes[i] <= 0.0f) {
			destroy_entity(i);
		}
	}
}
