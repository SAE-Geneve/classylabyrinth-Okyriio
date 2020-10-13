#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "command.h"
#include "Enemy.h"
#include "Player.h"

class World
{
private:
	// Map of the local space.
	std::string local_world =
		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";

	// Local player stuff.
	Player local_player;// = Player(22, 1, 5, 1, 2);

	// Map that map space to enemies.
	std::map<std::pair<int, int>, Enemy> local_enemy;
	
	int xy_local(int x, int y)
	{
		// We want the local array to be bound to the borders.
		if (x < 0) x = 0;
		if (x > 23) x = 23;
		if (y < 0) y = 0;
		if (y > 7) y = 7;
		// Return the position within the local world of the cursor.
		// As the array is singular dimention we use the largest value to
		// split it.
		return x + y * 24;
	}
	
public:
	World();
	char get_tile_at_position(int x, int y);
	void set_player(Player player, int x, int y);
	void erase_enemy(Enemy enemy,int x, int y);
	Player get_player();
	Enemy get_enemy(int x, int y);
	void set_enemy(Enemy enemy, int x,  int y);
	void show_description(Enemy enemy);
	int xy_local();
};
//enum class TileType : char
//{
//	BLOCK = '#',
//	EMPTY = '.',
//	ENEMY = 'E',
//	PLAYER = 'P',
//};
//
//enum class CommandType
//{
//	QUIT,
//	NORTH,
//	SOUTH,
//	EAST,
//	WEST,
//	ATTACK,
//	HELP,
//	//AGAIN,
//};


