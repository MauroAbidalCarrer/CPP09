#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "PmergeMe.hpp"

using namespace std;

int main(int ac, char** av) {
    if (ac <= 1) 
    {
        cerr << "Error: ac < 2." << endl;
        return 1;
    }
    try
    {
        PmergeMe yes(ac, av);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}