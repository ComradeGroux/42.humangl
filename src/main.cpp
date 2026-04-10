#include "init.hpp"

#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << "hello world" << std::endl;

	GLFWwindow*	window = createWindow();

	return 0;
}
