#pragma once

#include <string>

enum class TileType : char
{
	BLOCK = '#',
	EMPTY = '.',
	ENEMY = 'E',
	PLAYER = 'P',
};

enum class CommandType
{
	QUIT,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	ATTACK,
	HELP,
	//AGAIN,
};

TileType get_tile_at_position(int x, int y);

struct Enemy
{
	int x;
	int y;
	int health_points = 50;
	int attack = 10;
	int defence = 2;
	std::string name = "Gob";
};

void set_enemy(Enemy enemy, int x, int y);
void erase_enemy(Enemy enemy, int x, int y);
Enemy get_enemy(int x, int y);

struct Player
{
	int x = 22;
	int y = 1;
	int health_points = 100;
	int max_health_points = 100;
	int attack = 20;
	int defence = 5;
	std::string name = "The Hero";
	int experience = 0;
	int health_regen = 5;
};

void set_player(Player player);
Player get_player();