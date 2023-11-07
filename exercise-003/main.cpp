#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <vector>
#include <cstdlib>

class VectorInt
{
    public:
        explicit VectorInt(int size) : _size(size)
        {
            _pData = new int[_size];
        }
        ~VectorInt()
        {
            delete[] _pData;
        }

        void push_back(int index, int value)
        {
            if (index >= _size)
            {
                int* temp = new int[index + 1];
                memcpy(temp, _pData, _size * sizeof(int)); 
                delete[] _pData;
                _pData = temp;
                _pData[index] = value;
                _size = index + 1;
            }
            else
            {
                _pData[index] = value;
            }
        }

        auto at(int index) -> int
        {
            if (index > _size) return 0;

            return _pData[index];
        }

        auto size() -> int
        {
            return _size;
        }

        const int operator[](const int index)
        {

        }
    private:
        int* _pData;
        int _size;
};

auto main(int argc, char **argv) -> int
{

    VectorInt vec(5);
    vec.at(2, 4);
    vec.at(5, 6);
    auto printVecValue = [](VectorInt& vec, int index){ fmt::print("Vec at: {} and value {}\n", index, vec.at(index)); };
    printVecValue(vec ,2);
    printVecValue(vec, 5);


    // int arr1[] = {4, 3, 2, 1};
    // int size = 4;
    // int* arr2 = new int[5];
    // memcpy(arr2, arr1, size * sizeof(int));
    // std::cout << arr2[3] << std::endl;

    return 0;
}
