#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <limits.h>

class PmergeMe
{
    public:
    //constructors and destructors
    PmergeMe(int ac, char **av)
    {
        std::vector<int> v;
        std::list<int> l;
        for (int i = 1; i < ac; i++) {
            long val = atol(av[i]);
            if (std::string(av[i]).length() > 10)
                throw Exception("Error: number too long, do not test me...");
            if (val <= 0)
                throw Exception("Error: encoutered non positive integers, do not test me...");
            if (val > INT_MAX)
                throw Exception("Error: encoutered integer bigger than INT_MAX,do not test me...");
            v.push_back(val);
            l.push_back(val);
        }

        std::cout << "Before:";
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;

        clock_t start_time = clock();
        sort(v.begin(), v.end());
        clock_t end_time = clock();
        std::cout << "After:";
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;
        std::cout << "Time to process a range of " << v.size() << " elements with vector sort: " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

        start_time = clock();
        l.sort();
        end_time = clock();
        std::cout << "After:";
        for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;
        std::cout << "Time to process a range of " << l.size() << " elements with list sort: " << ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
    }
    PmergeMe(const PmergeMe& other)
    {
        *this = other;
    }
    ~PmergeMe()
    {
        
    }
    //operator overloads
    PmergeMe& operator=(const PmergeMe& rhs)
    {
        (void)rhs;
        return *this;
    }
    //nested classes
    class Exception : public std::exception
    {
        private:
        std::string errormsg;

        public:
        Exception(std::string err_msg)
        {
            errormsg = err_msg;
        }
        ~Exception() throw () {}

        const char* what() const throw()
        {
            return errormsg.c_str();
        }
    };
};
#endif