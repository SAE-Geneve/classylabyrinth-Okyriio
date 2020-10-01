#include <vector>
#include "command.h"
#include <iostream>
namespace {

	void cross_attack(Player player, Enemy enemy)
	{
		// Max is there to avoid giving health point in case too high defence.
		player.health_points -= std::max(0, enemy.attack - player.defence);
		enemy.health_points -= std::max(0, player.attack - enemy.defence);
		set_player(player);
		set_enemy(enemy, enemy.x, enemy.y);
		if (enemy.health_points <= 0)
		{
			std::cout << "The enemy died by your hands Hero \n";
			erase_enemy(enemy, enemy.x, enemy.y);
		}
		if (player.health_points <= 0)
		{
			std::cout << " You died loser\n";
		}
	}
}

void north()
{
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.x, player.y - 1);
	if (tile_type != TileType::EMPTY)
		return;
	player.y -= 1;
	set_player(player);
}

void south()
{
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.x, player.y + 1);
	if (tile_type != TileType::EMPTY)
		return;
	player.y += 1;
	set_player(player);//Done
}

void east()
{
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.x + 1, player.y);
	if (tile_type != TileType::EMPTY)
		return;
	player.x += 1;
	set_player(player);// Done
}

void west()
{
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.x - 1, player.y);
	if (tile_type != TileType::EMPTY)
		return;
	player.x -= 1;
	set_player(player);//Done
}

void attack()
{
	Player player = get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y - 1))
		enemy_vec.push_back(get_enemy(player.x, player.y - 1));
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y + 1))
		enemy_vec.push_back(get_enemy(player.x, player.y + 1));
	if (TileType::ENEMY == get_tile_at_position(player.x - 1, player.y))
		enemy_vec.push_back(get_enemy(player.x - 1, player.y));
	if (TileType::ENEMY == get_tile_at_position(player.x + 1, player.y))
		enemy_vec.push_back(get_enemy(player.x + 1, player.y));
	for (const auto& enemy : enemy_vec)
		cross_attack(player, enemy);
}

void tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = get_player();
	player.health_points += player.health_regen;
	player.health_points =
		std::min(player.health_points, player.max_health_points);
}
void show_description(Enemy enemy)
{
	std::cout << "Health Points\n" << enemy.health_points << "\nAttack\n" << enemy.attack << "\n Defense\n" << enemy.defence;
}