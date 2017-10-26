#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    double x1 = 1., y1 = 0.;
    double x2 = 0., y2 = 1.;

    double distance = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    std::cout << "distance = " << distance << std::endl;
    return 0;
}

