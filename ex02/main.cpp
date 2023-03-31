#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "PmergeMe.hpp"

# define VEC_SIZE 75

int main(int ac, char** av) {
    // if (ac <= 1) 
    // {
    //     cerr << "Error: ac < 2." << endl;
    //     return 1;
    // }
    try
    {
        (void)ac;
        (void)av;
        // std::vector<int> vec;
        // vec.push_back(5);
        // vec.push_back(2);
        // vec.push_back(3);
        // vec.push_back(1);
        // vec.push_back(4);
        // vec.push_back(7);
        // vec.push_back(6);

        

        std::vector<int> vec(VEC_SIZE);
        for (size_t i = 0; i < vec.size(); i++)
            vec[i] = i;
        // obtain a time-based seed:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));

        for(size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " "/* << std::endl */;
        std::cout << std::endl;
        PmergeMe::merge_insert_vector(vec);

        for(size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " "/* << std::endl */;
        std::cout << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    //vec  //  1 2 4
    //sort //  3 5 7
}