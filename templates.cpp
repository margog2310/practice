#include "templates.hpp"

int main()
{
    std::cout << "add() tests:" << std::endl;
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

    std::cout << "mult() tests:" << std::endl;
    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

    std::cout << "sub() tests:" << std::endl;
    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}