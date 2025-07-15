#ifndef TEAM_COMPONENT_H
#define TEAM_COMPONENT_H

#include "config.h"

#include <stdbool.h>

enum team_type {
	TEAM_NONE = 0,
	TEAM_PLAYER,
	TEAM_ENEMY,
};

extern enum team_type teams[MAX_ENTITIES];

extern bool has_team[MAX_ENTITIES];

#endif