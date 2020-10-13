#pragma once
#include "character.h"

class Player : public Character
{
public:
	Player();
	Player(int x, int y, int healthpoints, int attack, int defence);
	int experience = 0;
	int health_regen = 5;
};