#ifndef MY_INTEGER_VECTOR_HPP
#define MY_INTEGER_VECTOR_HPP

#include <cstddef>

class VectorInt {
public:
    VectorInt(int size);
    ~VectorInt();
    void push_back(int value);
    int at(int index);
    int size();
    void resize(int size);
    void clear(); 
    int& operator[](const size_t index);
private:
    int* mp_Data;
    int m_size;
    int m_capacity;
};

#endif