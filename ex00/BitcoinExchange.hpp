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

class BitcoinExchange
{
    private:
    std::map<std::string, float> bitcoin_prices;

    public:
    //constructors and destructors
    BitcoinExchange() : bitcoin_prices() { }
    BitcoinExchange(const char * database_file) : bitcoin_prices()
    {
        std::ifstream csv_file_stream(database_file);
        // Read bitcoin prices over time from csv file
        if (!csv_file_stream.is_open())
            throw BitcoinExchangeException(std::string("Error: could not open ") + std::string(database_file));
        std::string line;
        while (std::getline(csv_file_stream, line))
        {
            std::istringstream line_stream(line);
            std::string date_str;
            float price;
            std::getline(line_stream, date_str, ',');
            line_stream >> price;
            bitcoin_prices[date_str] = price;
        }
        csv_file_stream.close();  
    }
    BitcoinExchange(const BitcoinExchange& other)
    {
        *this = other;
    }
    ~BitcoinExchange() {}
    //overloads
    BitcoinExchange& operator=(const BitcoinExchange& rhs)
    {
        bitcoin_prices = rhs.bitcoin_prices;
        return *this;
    }
    
    //methods
    void print_btc_amount_values(const char * input_file_path)
    {
        std::ifstream input_file(input_file_path);
        if (!input_file.is_open())
            throw BitcoinExchangeException(std::string("Error: could not open ") + std::string(input_file_path));
        std::string line;
        while (std::getline(input_file, line))
        {
            std::istringstream line_stream(line);
            std::string date_str;
            std::getline(line_stream, date_str, '|');
            std::map<std::string, float>::const_iterator it = bitcoin_prices.lower_bound(date_str);
            float value;
            line_stream >> value;
            if (line_stream.fail() || !validate_date(date_str) || !validate_value(line))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            --it;
            float exchange_rate = it->second;
            std::cout << date_str << " => " << value << " = " << exchange_rate * value << std::endl;
        }
        input_file.close();
    }
    bool validate_date(std::string d)
    {
        for (size_t i = 0; i < 4; i++)
            if (!isdigit(d[i]))
                return false;
        for (size_t i = 5; i < 7; i++)
            if (!isdigit(d[i]))
                return false;
        for (size_t i = 8; i < 10; i++)
            if (!isdigit(d[i]))
                return false;
        return d[4] == '-' && d[7] == '-' && d[10] == ' ';
    }
    bool validate_value(std::string v)
    {
        if (v[12] != ' ')
            return false;
        for (size_t i = 13; i < 18 && i < v.length(); i++)
            if (!isdigit(v[i]))
                return false;
        return true;
    }

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