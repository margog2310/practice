#include <iostream>
#include <iomanip>

double getNumber()
{
    std::cout << "Enter a double value: ";
    double x {};
    std::cin >> x;
    return x;
}

char getOp()
{
    std::cout << "Enter +, -, * or /: ";
    char op {};
    std::cin >> op;
    return op;
}

double performOp(double x1, double x2, char op)
{
    if (op == '+')
        return x1 + x2;
    else if (op == '-')
        return x1 - x2;
    else if (op == '*')
        return x1 * x2;
    return x1 / x2;
}

int main()
{
    double x1 = {getNumber()};
    double x2 = {getNumber()};
    char op = {getOp()};

    std::cout << static_cast<double>(x1) << " " << op << " " 
                << static_cast<double>(x2) << " is " 
                << static_cast<double>(performOp(x1, x2, op))
                << std::endl;  
}