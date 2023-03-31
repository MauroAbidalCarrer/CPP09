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
    PmergeMe(const PmergeMe& other) { *this = other; }
    ~PmergeMe() { }
    //operator overloads
    PmergeMe& operator=(const PmergeMe& rhs)
    {
        (void)rhs;
        return *this;
    }
    typedef std::vector<int> int_vector_t;
    //methods
    template <typename T, template < typename U, typename = std::allocator<U> > class ContainerT >
    static void insert_in_vec(int val, ContainerT<int>& container, size_t start_index)
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
    static void merge_insert_vector(ContainerT<int>& container)
    {
        ContainerT<Pair> pairs/*() container.size() / 2 )*/;
        for (size_t i = 0; i * 2 < container.size(); i++)
            pairs.push_back(Pair(std::min(container[i * 2], container[i * 2 + 1]), std::max(container[i * 2], container[i * 2 + 1])));
            // pairs[i] = Pair(std::min(container[i * 2], container[i * 2 + 1]), std::max(container[i * 2], container[i * 2 + 1]));
        bool is_odd = container.size() % 2;
        int straggler = container[container.size() - 1];
        std::sort(pairs.begin(), pairs.end());
        container.clear();
        for (size_t i = 0; i < pairs.size(); i++)
            container.push_back(pairs[i].a);
        for (size_t i = pairs.size() - 1; i >= 0; i--)
        {
            insert_in_vec<ContainerT<int> >(pairs[i].b, container, i);
            // std::cout << "Inserted " << pairs[i].b << ", i = " << i << std::endl;
            if (i == 0)
                break;
        }
        if (is_odd)
            insert_in_vec<ContainerT<int> >(straggler, container, 0);
    }
    //nested classes
    class Pair
    {
        public:
        int a;
        int b;
        //constructors
        Pair() : a(0), b(0) { }
        Pair(int a, int b) : a(a), b(b) { }
        Pair(const Pair& other) : a(other.a), b(other.b) { }
        ~Pair() { }
        bool operator<(const Pair& rhs)
        {
            return a < rhs.a;
        }
        bool operator>(const Pair& rhs)
        {
            return a > rhs.a;
        }
    };
};
#endif