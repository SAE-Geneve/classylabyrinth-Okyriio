#pragma once
#include "character.h"

class Enemy : public Character
{

public:
	Enemy(int x, int y, int healthpoints, int attack, int defence);
	Enemy();
	
};