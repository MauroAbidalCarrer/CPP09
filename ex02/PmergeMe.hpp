#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>

class PmergeMe
{
    public:
    //constructors and destructors
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    //operator overloads
    PmergeMe& operator=(const PmergeMe& rhs);
    //methods
    // template <typename T, template < typename U, typename = std::allocator<U> > class ContainerT >
    // void insert_in_vec(int val, ContainerT<int>& container, size_t start_index);
    // template <typename T, template < typename U, typename = std::allocator<U> > class ContainerT >
    // void merge_insert_vector(ContainerT<int>& container);
    //nested classes
    // class Pair
    // {
    //     public:
    //     int a;
    //     int b;
    //     //constructors
    //     Pair() : a(0), b(0) { }
    //     Pair(int a, int b) : a(a), b(b) { }
    //     Pair(const Pair& other) : a(other.a), b(other.b) { }
    //     ~Pair() { }
    //     bool operator<(const Pair& rhs)
    //     {
    //         return a < rhs.a;
    //     }
    //     bool operator>(const Pair& rhs)
    //     {
    //         return a > rhs.a;
    //     }
    // };
};
#endif