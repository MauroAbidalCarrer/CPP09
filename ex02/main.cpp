#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <deque>

#include "PmergeMe.hpp"

// #define nb_lement 1000000


//methods
template <typename T, template < typename U, typename = std::allocator<U> > class ContainerT >
void insert_in_vec(int val, ContainerT<int>& container, size_t start_index)
{
    size_t end_index = container.size() - 1;
    while (start_index < end_index)
    {
        size_t half_size =  std::max((size_t)1,  (size_t)((end_index - start_index) / 2));
        size_t midle_index = start_index + half_size;
        if (container[midle_index] > val)
            end_index = midle_index - 1;
        else
            start_index = midle_index;
    }
    container.insert(container.begin() + start_index + 1, val);
}
template <typename T, template < typename U, typename = std::allocator<U> > class ContainerT >
void merge_insert_vector(ContainerT<int>& container)
{
    if (container.size() == 0)
        return ;
    ContainerT<std::pair<int, int> > pairs(container.size() / 2 );
    for (size_t i = 0; i * 2 < container.size(); i++)
        pairs[i] = std::pair<int, int> (std::min(container[i * 2], container[i * 2 + 1]), std::max(container[i * 2], container[i * 2 + 1]));
    bool is_odd = container.size() % 2;
    int straggler = container[container.size() - 1];
    std::sort(pairs.begin(), pairs.end());
    container.clear();
    for (size_t i = 0; i < pairs.size(); i++)
        container.push_back(pairs[i].first);
    for (size_t i = pairs.size() - 1; i >= 0; i--)
    {
        insert_in_vec<ContainerT<int> >(pairs[i].second, container, i);
        // std::cout << "Inserted " << pairs[i].secon << ", i = " << i << std::endl;
        if (i == 0)
            break;
    }
    if (is_odd)
        insert_in_vec<ContainerT<int> >(straggler, container, 0);
}

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
        // PmergeMe test;
        merge_insert_vector<std::vector<int> >(vec);
        clock_t end_time = clock();
        //debugging
        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::vector sort: " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

        // deque testing
        start_time = clock();
        merge_insert_vector<std::deque<int> >(deque);
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