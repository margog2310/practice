#include <cstdlib>
#include <iostream>
#include <limits>
#include <chrono>
#include <random>

void restartGame();

namespace Random {
    inline std::mt19937 generateSeed()
    {
        std::random_device rd{};
        std::seed_seq ss {static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count(),
            rd(), rd(), rd(), rd(), rd(), rd(), rd())};
        return std::mt19937{ss};
    }
    inline std::mt19937 mt {generateSeed()};
    inline int getRandomNumber(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }
}
// ignore everything in buffer until end of buffer or next newline encountered
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// checks if there's any unexpected input left before end of buffer or next newline
bool hasUnexpectedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n'; 
}
// return true if extraction failed and false otherwise
bool clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof()) // if stream closed, shut down program
            std::exit(0);
        std::cin.clear(); // reset buffer
        ignoreLine(); // flush buffer
        return true;
    }
    return false;
}

int guessNumber(int min, int max, int count)
{
    while (1)
    {
        std::cout << "Guess #" << count << ": ";
        int guess {};
        std::cin >> guess;
    
        if (clearFailedExtraction())
        {
            std::cout << "Error: Invalid input. Please try again." << std::endl;
            continue;
        }
        if (guess < min || guess > max)
        {
            std::cout << "Error: Guess is out of bounds. Please try again." << std::endl;
            continue;
        }
        ignoreLine();
        return guess;
    }
}

void playGame(int min, int max, int guesses)
{
    while (1)
    {
        std::cout << "I'm thinking of a number between " << min << " and " << max 
            << ". You have " << guesses << " tries to guess it." << std::endl;
        int random {Random::getRandomNumber(min, max)};
        
        for (int count {1}; count <= guesses; ++count)
        {
            int guess {guessNumber(min, max, count)};
            if (guess > random)
            {
                std::cout << "Your guess is too high." << std::endl;
                continue ;
            }
            else if (guess < random)
            {
                std::cout << "Your guess is too low." << std::endl;
                continue ;
            }
            else
            {
                std::cout << "Correct! You win!" << std::endl;
                break ;
            }
        }
        std::cout << "Sorry you lose. The correct answer was " << random << std::endl;
        restartGame();
    }
}

void restartGame()
{
    while (1)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char answer {};
        std::cin >> answer;

        if (clearFailedExtraction())
            continue ; 
        if (hasUnexpectedInput())
            ignoreLine();
        if (answer == 'y')
            return ;
        else if (answer == 'n')
        {
            std::cout << "Thank you for playing!" << std::endl;
            exit(0);
        }
    }
}

int main()
{
    constexpr int guesses {7};
    constexpr int min {1};
    constexpr int max {100};

    playGame(min, max, guesses);   
}