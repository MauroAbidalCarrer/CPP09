#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

class RPN
{
    private:
    std::stack<float> stack;

    public:
    //constructors and destructors
    RPN() : stack() { }
    RPN(char **expression) : stack()
    {
        for (int exp_i = 0; expression[exp_i] != NULL; exp_i++)
        {
            char *arg = expression[exp_i];
            if (is_number(arg))
                stack.push(atof(arg));
            else if (is_op(arg))
            {
                float second_nb = get_last_nb();
                float first_nb = get_last_nb();
                switch (*arg)
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
        (void)rhs;
        return *this;
    }
    //methods
    void check_arg(char *arg)
    {
        if (is_number(arg))
            return ;
        if (is_op(arg))
            return ;
        throw RPNException();
    }
    bool is_number(char *arg)
    {
        arg += arg[0] == '+' || arg[0] == '-';
        int i = 0;
        for(; arg[i] && i < 2; i++)
        {
            if (!isdigit(arg[i]))
                return false;
        }
        return arg[i] == 0 && i > 0;
    }
    bool is_op(char *arg)
    {
        return ((arg[0] == '+' || arg[0] == '/' || arg[0] == '*' || arg[0] == '-') && arg[1] == 0);
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