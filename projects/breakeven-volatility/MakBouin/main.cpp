#include <iostream>
#include <vector>
#include "break_even_volatility.hpp"

int main(int argc, char* argv[])
{
    time_series hihi("/Users/Marcello/Documents/My Documents/Academic/2016 Master/Master 203/S3/C++/Test/data.csv", "EuroStoxx 50");
    std::cout << hihi.get_dataname() << std::endl;
    std::vector<time_t> datadate = hihi.get_date();
    std::cout << datadate[998] << std::endl;
    
    time_t targett = c_str_timet("18/12/2017");
    std::cout << targett << std::endl;
    
    std::vector<ptrdiff_t> temp = hihi.get_datapos("18/12/2017", 30);
    
    std::cout << temp[0] << " and " << temp[1] <<std::endl;
    std::vector<double> data = hihi.get_data(temp[0], temp[1]);
    std::cout << data[0] << " and " << data[data.size() - 1] << std::endl;
    
    return 0;
}

/*
EuroStoxx 50
1513551600
1513551600
978 and 998
5017.45 and 5242.28
*/
