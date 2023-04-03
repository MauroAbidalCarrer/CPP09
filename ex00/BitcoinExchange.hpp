#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <regex.h>
# include <regex.h>
# include <cstring>
# include <iomanip>

class BitcoinExchange
{
    private:
    std::map<std::string, float> bitcoin_prices;

    public:
    //constructors and destructors
    BitcoinExchange();
    BitcoinExchange(const char * database_file);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    //overloads
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    
    //methods
    void print_btc_amount_values(const char * input_file_path);
    bool validate_date(std::string d);
    bool validate_value(std::string v);

    //nested classes
    class BitcoinExchangeException : public std::exception
    {
        std::string err_msg;
        public: 
        BitcoinExchangeException(std::string err_msg) : err_msg(err_msg) { }
        ~BitcoinExchangeException() throw() { }
        const char* what() const throw()
        {
            return err_msg.data();
        }
    };
};
#endif