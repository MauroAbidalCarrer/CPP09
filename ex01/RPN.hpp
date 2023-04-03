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
    RPN() : stack() { }
    RPN(const char *expression) : stack()
    {
        for (int exp_i = 0; expression[exp_i] != 0; exp_i++)
        {
            char arg = expression[exp_i];
            if (arg == ' ')
                continue ;
            if (is_number(arg))
                stack.push(arg - '0');
            else if (is_op(arg))
            {
                float second_nb = get_last_nb();
                float first_nb = get_last_nb();
                switch (arg)
                {
                case '+':
                    stack.push(first_nb + second_nb);
                    break;
                case '-':
                    stack.push(first_nb - second_nb);
                    break;
                case '/':
                    stack.push(first_nb / second_nb);
                    break;
                case '*':
                    stack.push(first_nb * second_nb);
                    break;
                }
            }
            else
                throw RPNException();
        }
        if (!stack.empty())
            std::cout << get_last_nb() << std::endl;
    }
    RPN(const RPN& other) 
    {
        *this = other;
    }
    ~RPN() { }
    //operator overloads
    RPN& operator=(const RPN& rhs)
    {
        stack = rhs.stack;
        return *this;
    }
    //methods
    bool is_number(char arg)
    {
        return arg >= '0' && arg <= '9';
    }
    bool is_op(char arg)
    {
        return arg == '+' || arg == '/' || arg == '*' || arg == '-';
    }
    float get_last_nb()
    {
        if (stack.empty())
            throw RPNException();
        float nb = stack.top();
        stack.pop();
        return nb;
    }
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