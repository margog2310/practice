#include <iostream>

namespace Constants {
    constexpr double gravity {9.8};
}

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double h {};
    std::cin >> h;
    return h;
}

double calculateBallHeight(int second, double height)
{
    double dist {Constants::gravity * (second * second) / 2};
    if (height - dist > 0.0)
        std::cout << "At " << second << " seconds, the ball is at height: "
                << height - dist << " meters" << std::endl;
    else
        std::cout << "At " << second << " seconds, the ball is on the ground."
                << std::endl;
    return height - dist;
}

int main()
{
    double towerHeight {getTowerHeight()};
    int seconds {0};

    while (calculateBallHeight(seconds, towerHeight) > 0.0)
        ++seconds;
}