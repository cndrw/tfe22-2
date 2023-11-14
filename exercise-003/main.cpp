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
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;

    std::cout << vec.size() << std::endl;

    VectorInt vec2(vec);

    VectorInt vec3(2);

    vec3 = vec;

    for (int i = 0; i < vec3.size(); i++)
    {
        fmt::print("vec: {}  vec2: {}  vec3: {}\n", vec[i], vec2[i], vec3[i]);
    }

    vec.push_back(42);
    std::cout << vec.size() << std::endl;

}