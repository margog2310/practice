#include <iostream>

void fizzbuzz(int nbr)
{
    for (int i = 1; i <= nbr; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "fizzbuzz" << std::endl;
        else if (i % 3 == 0)
            std::cout << "fizz" << std::endl;
        else if (i % 5 == 0)
            std::cout << "buzz" << std::endl; 
        else
            std::cout << i << std::endl;
    }
}

void fizzbuzzpop(int nbr)
{
    for (int i = 1; i <= nbr; ++i)
    {
        bool alreadyTrue { false };
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            alreadyTrue = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "buzz";
            alreadyTrue = true;
        }
        if (i % 7 == 0)
        {
            std::cout << "pop";
            alreadyTrue = true;
        }
        if (!alreadyTrue)
            std::cout << i;
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Enter a number number to count up to: ";
    int nbr {};
    std::cin >> nbr;

    //fizzbuzz(nbr);
    fizzbuzzpop(nbr);

    return 0;
}