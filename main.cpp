#include <iostream>
#include "tile.h"
#include "command.h"

void show_help()
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
void show_state()
{
	Player player = get_player();
	std::cout << "Maze :\n";
	//std::cout << "North : " << (char)get_tile_at_position(player.x, player.y - 1);
	//std::cout << "\nSouth : " << (char)get_tile_at_position(player.x, player.y + 1);
	//std::cout << "\nEast : " << (char)get_tile_at_position(player.x + 1, player.y);
	//std::cout << "\nWest : " << (char)get_tile_at_position(player.x - 1, player.y);
	for (int i = player.y - 4; i < player.y + 4; i++)
	{
		for (int j = player.x - 12; j < player.x + 12; j++)
		{
			std::cout << (char)get_tile_at_position(j, i);
		}
		std::cout << std::endl;
	}
	std::cout << "\nPlayer(" << player.x << "," << player.y << ") :\n";
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y - 1))
		show_description(get_enemy(player.x, player.y - 1));
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y + 1))
		show_description(get_enemy(player.x, player.y + 1));
	if (TileType::ENEMY == get_tile_at_position(player.x - 1, player.y))
		show_description(get_enemy(player.x - 1, player.y));
	if (TileType::ENEMY == get_tile_at_position(player.x + 1, player.y))
		show_description(get_enemy(player.x + 1, player.y));
	// DOne

}
CommandType get_command()
{
	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	switch (command_str[0])
	{
		/*case 'ag':
			return CommandType::AGAIN;
			again();*/
	case 'q':
		return CommandType::QUIT;
	case 'n':
		return CommandType::NORTH;
	case 's':
		return CommandType::SOUTH;
	case 'e':
		return CommandType::EAST;
	case 'w':
		return CommandType::WEST;
	case 'a':
		return CommandType::ATTACK;
	case 'h':
	default:
		show_help();
		return CommandType::HELP;
	}
}

int main()
{
	std::cout << "Welcome in the Maze!\n";
	show_help();
	while (true)
	{
		show_state();
		CommandType command_type = get_command();
		switch (command_type)
		{
		case CommandType::QUIT:
			std::cout << "Bye Hero!\n";
			return 0;
		case CommandType::NORTH:
			north();
			tick();
			break;
		case CommandType::SOUTH:
			south();
			tick();
			break;
		case CommandType::EAST:
			east();
			tick();
			break;
		case CommandType::WEST:
			west();
			tick();
			break;
		case CommandType::ATTACK:
			attack();
			tick();
			break;
		case CommandType::HELP:
		default:
			tick();
			break;
		}
	}
}