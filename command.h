#pragma once
#include "tile.h"

class Command {
public:
	Command();
	void north();
	void south();
	void east();
	void west();
	void attack();
	void tick();
	void show_state();
	char get_command();
	void ExCommand();
    void show_help();
	World world_;

};