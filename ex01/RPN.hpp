#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <cstdlib>

class RPN
{
    private:
    std::stack<float, std::list<float> > stack;

    public:
    //constructors and destructors
    RPN();
    RPN(const char *expression);
    RPN(const RPN& other);
    ~RPN();
    //operator overloads
    RPN& operator=(const RPN& rhs);
    //methods
    bool is_number(char arg);
    bool is_op(char arg);
    float get_last_nb();
    //nested classes
    class RPNException : public std::exception
    {
        public: 
        const char* what() const throw()
        {
            return "Error";
        }
    };
};
#endif