#include <iostream>
#include "command.h"


int main ()
{
	Command command = Command();
	std::cout << "Welcome to the maze Chosen One";
	command.show_help();
	command.ExCommand();
}

