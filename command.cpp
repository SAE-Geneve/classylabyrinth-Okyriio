#include "command.h"
#include <vector>
#include <iostream>


Command::Command()
{
	world_ = World();
}

char Command::get_command()
{
	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	return(command_str[0]);

}
void Command::ExCommand(){
	
	switch (get_command()){
	case 'q':
		std::cout << "Bye Hero!";
		return;
	case 'n':
		north();
		break;
	case 's':
		south();
		break;
	case 'e':
		east();
		break;
	case 'w':
		west();
		break;
	case 'a':
		attack();
		break;
	case 'h':
	default:
		show_help();
		break;
	}
}
	
void Command::show_state(){
	Player player = world_.get_player();
	std::cout << "Maze :\n" << "\nPlayer(X:" << player.x<< ", Y:" << player.y << ") :\n";
	for (int i = player.y - 1; i < player.y + 2; i++) {
		for (int j = player.x - 4; j < player.x + 2; j++) {
			std::cout << (char)world_.get_tile_at_position(j, i);
		}
		std::cout << std::endl;
	}
}

void Command::north()
{
	Player player = world_.get_player();
	if (world_.get_tile_at_position(player.x, player.y-1) != '.')
	{

		return; }

	player.y -= 1;
}

void Command::south()
{

	Player player = world_.get_player();
	if (world_.get_tile_at_position(player.x, player.y + 1) != '.')
	{

		return; }

	player.y -= 1;
}

void Command::east()
{

	Player player = world_.get_player();
	if (world_.get_tile_at_position(player.x+1, player.y ) != '.')
	{

		return; }

	player.y -= 1;
}

void Command::west()
{

	Player player = world_.get_player();
	if (world_.get_tile_at_position(player.x-1, player.y ) != '.')
	{

		return; }

	player.y -= 1;
}
void Command::attack()
{

	Player player = world_.get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (world_.get_tile_at_position(player.x, player.y - 1) == 'E')
		enemy_vec.push_back(world_.get_enemy(player.x, player.y - 1));
	if (world_. get_tile_at_position(player.x, player.y + 1)=='E')
		enemy_vec.push_back(world_.get_enemy(player.x, player.y + 1));
	if (world_.get_tile_at_position(player.x - 1, player.y) == 'E')
		enemy_vec.push_back(world_.get_enemy(player.x - 1, player.y));
	if (world_.get_tile_at_position(player.x + 1, player.y)=='E')
		enemy_vec.push_back(world_.get_enemy(player.x + 1, player.y));
}
void Command::tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = world_.get_player();
	player.healthpoints += player.health_regen;
	/*player.healthpoints =
		std::min(player.healthpoints, player.max_health_points);*/
}

void Command::show_help()
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit  -> quit the game.\n";
	std::cout << "\t[n]orth -> move north.\n";
	std::cout << "\t[s]outh - > move south.\n";
	std::cout << "\t[e]ast -> move east.\n";
	std::cout << "\t[w]est -> move west.\n";
	std::cout << "\t[a]ttack\n";
	std::cout << "\t[t]ick\n";//Done
}