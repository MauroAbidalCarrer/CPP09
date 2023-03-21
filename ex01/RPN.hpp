#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>

class RPN
{
    private:
    std::stack<float> stack;

    public:
    //constructors and destructors
    RPN() : stack() { }
    RPN(char **expression) : stack()
    {
        for (; expression; expression++)
        {
            char *arg = *expression;
            if (is_number(arg))
                stack.push(atof(arg));
            else if (is_op(arg))
            {
                float second_nb = get_last_nb();
                float first_nb = get_last_nb();
                float res;
                switch (*arg)
                {
                case '+':
                    res = first_nb + second_nb;
                    break;
                case '-':
                    res = first_nb - second_nb;
                    break;
                case '/':
                    res = first_nb / second_nb;
                    break;
                case '*':
                    res = first_nb * second_nb;
                    break;
                }
                stack.push(res);
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
        if (arg[0] == '+' || arg[0] == '-')
            arg++;
        return isdigit(arg[0]) && isdigit(arg[1]) && arg[2] == 0;
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