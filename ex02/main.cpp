#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <deque>

#include "PmergeMe.hpp"

// #define nb_lement 1000000

int main(int ac, char **av) {
    // int nb_numbers = ac >= 2 ? ac  nb_element;
    try
    {
        int nb_element = ac - 1; 
        std::vector<int> vec;
        for (int i = 1; i < ac; i++)
            vec.push_back(atoi(av[i]));
        
        //check for duplicates
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (std::count(vec.begin(), vec.end(), vec[i]) > 1)
            {
                std::cerr << "duplicate " << vec[i] << " in sequence" << std::endl;
                return 1;
            }
        }
        
        //generate containers
        // std::vector<int> vec(nb_element);
        // for (size_t i = 0; i < vec.size(); i++)
        //     vec[i] = i;
        // std::srand(std::time(NULL));
        // std::random_shuffle(vec.begin(), vec.end());

        //copy vec deque
        std::deque<int> deque;
        for (size_t i = 0; i < vec.size(); i++)
            deque.push_back(vec[i]);
        
        //vector testing
        std::cout << "Before: ";
        for (int i = 0; i < ac - 1; i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        clock_t start_time = clock();
        PmergeMe::merge_insert_vector<std::vector<int> >(vec);
        clock_t end_time = clock();
        //debugging
        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::vector sort: " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

        // deque testing
        start_time = clock();
        PmergeMe::merge_insert_vector<std::deque<int> >(deque);
        end_time = clock();
        std::cout << "Time to process a range of " << nb_element << " elements with std::deque sort:   " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
        // std::cout << "After: ";
        // for (size_t i = 0; i < deque.size(); i++)
        //     std::cout << deque[i] << " ";
        // std::cout << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    //vec  //  1 2 4
    //sort //  3 5 7
}