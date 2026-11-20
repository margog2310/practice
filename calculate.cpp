#include <iostream>

int calculate(int first, int second, char op)
{
    switch(op)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    case '%':
        return first % second;
    default:
        std::cout << "Error: unknown arithmetic operator" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    std::cout << "Enter an integer: ";
    int first {};
    std::cin >> first;

    std::cout << "Enter another integer: ";
    int second {};
    std::cin >> second;

    std::cout << "Enter +, -, *, / or %: ";
    char op {};
    std::cin >> op;

    std::cout << first << " " << op << " " << second 
                << " = " << calculate(first, second, op) << std::endl;
}