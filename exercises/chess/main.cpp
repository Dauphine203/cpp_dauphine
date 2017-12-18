#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

// WINDOWS
// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake

// LINUX // MACOS
// mkdir build
// cd build
// cmake ..
// make

void print_chess()
{
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "| Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |" << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "| Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "| Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
    std::cout << "| Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw | " << std::endl;
    std::cout << "+----+----+----+----+----+----+----+----+ " << std::endl;
}

void get_move(std::string input, std::array<int, 4>& pos)
{
    static std::array<std::string, 4> tmp;

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    input[input.find('-')] = ',';
    std::size_t i = 0;
    std::string token;
    std::istringstream iss(input);
    while(std::getline(iss, token, ','))
    {
        tmp[i++] = token;
    }
    if(i<4)
    {
        throw std::runtime_error("too few position arguments");
    }

    std::transform(tmp.cbegin(), tmp.cend(), pos.begin(), [](auto&& arg) { return stoi(arg); });
}

int main(int argc, char* argv)
{
    std::string input;
    std::cout << "Enter your move: ro,co - rd,cd" << std::endl;
    std::getline(std::cin, input);
    std::array<int, 4> pos;
    try
    {
        get_move(a, pos);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

