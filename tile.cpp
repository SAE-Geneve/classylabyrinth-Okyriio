#include "tile.h"

World::World()
{
	local_player = Player(22, 1, 5, 1, 2);
}

char World:: get_tile_at_position(int x, int y)
{
	//Done
	return (char)local_world[xy_local(x, y)];
}

void World:: set_player(Player player, int x, int y)
{
	// Erase the local player.
	local_world[xy_local(local_player.x, local_player.y)] = '.';
	local_player = player;
	// Reinclude the new player.
	local_world[xy_local(player.x, player.y)] = 'P';
}

Player World::get_player()
{
	return local_player;
}

void World::erase_enemy(Enemy enemy, int x, int y)
{
	enemy.x = x;
	enemy.y = y;
	local_world[xy_local(x, y)] = '.';

	//if (local_world.){
	//	std::cout << "\nYou won the Maze";
	//	return;
	//}

	bool isWin = true;
	for (char cell : local_world)
	{
		if (cell == 'E')
		{
			isWin = false;
		}
	}

	if (isWin == true)
	{
		std::cout << "\nYou won the Maze Hero\n" << "\nWrite q to quit Hero\n";
	}
}
void World::set_enemy(Enemy enemy, int x, int y)
{
	// Set the location of the enemy.
	enemy.x = x;
	enemy.y = y;
	local_enemy[{x, y}] = enemy;
}


Enemy World::get_enemy(int x, int y)
{
	Enemy enemy;
	enemy.x = x;
	enemy.y = y;
	// Get the local position in the world (if it exist).
	// Then check if there is an enemy at this position?
	if (local_enemy.find({ x,y }) == local_enemy.end())
	{
		// If an enemy is at the position.
		local_enemy[{x, y}] = enemy;
	}
	else
	{
		// if not then create it and store it at the location.
		return local_enemy[{x, y}];
	}
	
	// return the enemy at the position.
	return enemy;
}

void World::show_description(Enemy enemy)
{
	std::cout << "Health Points\n" << enemy.healthpoints << "\nAttack\n" << enemy.attack << "\n Defense\n" << enemy.defence;
}