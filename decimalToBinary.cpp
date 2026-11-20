#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter a number from 0 to 255: ";
    int nbr {};
    std::cin >> nbr;

    for (int i = 7; i >= 0; i--)
    {
        if (nbr >= static_cast<int>(pow(2, i)))
        {
            std::cout << 1;
            nbr -= static_cast<int>(pow(2, i));
        }
        else
            std::cout << 0;
    }
    std::cout << std::endl;
}