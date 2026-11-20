#include <iostream>
#include <random>
#include <chrono>

int main()
{
    // Mersenne Twister random nbr generator, initialised using system clock
    //std::mt19937 mt { static_cast<std::mt19937::result_type>(
        //std::chrono::steady_clock::now().time_since_epoch().count())};

    // initialised using system's random device -> asks OS for a pseudo-random nbr
    //std::mt19937 mt { std::random_device{}() };
    std::random_device rd{};
    std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // 8 random ints to expand seed values
    std::mt19937 mt { ss }; // initialise algo with seed_seq

    std::uniform_int_distribution die6{1, 6}; // generates a random nbr between 1 and 6

    for (int count {1}; count <= 20; ++count)
    {
        std::cout << die6(mt) << " ";
        if (count % 10 == 0)
            std::cout << std::endl;
    }
}