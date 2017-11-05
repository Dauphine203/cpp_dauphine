#include <iostream>
#include <iomanip>
#include <cmath>
#include "discount_factor.hpp"
int i = 0;
int main(int argc, char* argv[])
{
    print_discount_factor(0.04, 1.5);
    return 0;
}


namespace
{
    int i = 0;
    int k = 4;
    int j = 2;
}

file1.cpp
namespace xxx1
{
    int i = 0;
}
using namespace xxx1;


file2.cpp
namespace xxx2
{
    int i = 0;
}

file3.cpp
using namespace xxx1;
using namespace xxx2;

func()
{
}

/*static int i = 0;
static int k = 4;
static int j = 2;*/

void func()
{
    std::cout << i << std::endl;
}
