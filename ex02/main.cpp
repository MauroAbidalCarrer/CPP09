#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <deque>

#include "PmergeMe.hpp"

#define NB_ELEMENTS 1000000

int main() {
    try
    {
        //generate containers
        std::vector<int> vec(NB_ELEMENTS);
        for (size_t i = 0; i < vec.size(); i++)
            vec[i] = i;
        std::srand(std::time(NULL));
        std::random_shuffle(vec.begin(), vec.end());
        //copy vec deque
        std::deque<int> deque;
        for (size_t i = 0; i < vec.size(); i++)
            deque.push_back(vec[i]);
        
        //vector testing
        clock_t start_time = clock();
        PmergeMe::merge_insert_vector<std::vector<int> >(vec);
        clock_t end_time = clock();
        std::cout << "Time to process a range of " << NB_ELEMENTS << " elements with std::vector sort: " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

        // deque testing
        start_time = clock();
        PmergeMe::merge_insert_vector<std::deque<int> >(deque);
        end_time = clock();
        std::cout << "Time to process a range of " << NB_ELEMENTS << " elements with std::deque sort:   " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    //vec  //  1 2 4
    //sort //  3 5 7
}