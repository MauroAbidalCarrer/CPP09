#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{    
    if (ac < 2)
    {
        std::cout << "ac = " << ac << std::endl;
        std::cout << "Error" << std::endl;
        return 1;
    }
    try
    {
        std::string arguments;
        for (int i = 1; i < ac; i++)
            arguments.append(av[i]);
        RPN rpn(arguments.data());
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}