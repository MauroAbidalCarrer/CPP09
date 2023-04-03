#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: no file to open specified." << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange yes("data.csv");

        yes.print_btc_amount_values(av[1]);
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}