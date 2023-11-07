#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
// #include "config.h"

#include <vector>
#include <cstdlib>

#include "vectorint.hpp"

int main()
{
    VectorInt vec(5);
    vec[2] = 42;
    vec.push_back(23);
    vec.resize(7);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i]  << std::endl;
    }
    return 0; 
}