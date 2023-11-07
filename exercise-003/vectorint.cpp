#include "vectorint.hpp"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstddef>

VectorInt::VectorInt(int size) : m_size(size), m_capacity(size)
{
    mp_Data = new int[size];
    for (int i = 0; i < m_size; i++)
    {
        mp_Data[i] = 0;
    }
}

VectorInt::~VectorInt() 
{
    if(mp_Data != nullptr) 
    {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}

void VectorInt::push_back(int value)
{
    m_size++;
    if (m_size <= m_capacity) 
    {
        mp_Data[m_size - 1] = value;
        return;
    }
    m_capacity = 2 * m_size;
    resize(m_size);
    mp_Data[m_size - 1] = value;
}

int VectorInt::at(int index)
{
    return mp_Data[index];
}

int VectorInt::size()
{
    return m_size;
}

void VectorInt::resize(int size)
{
    m_size = m_size > size ? size : m_size;  
    // m_capacity = m_size > m_capacity ? m_capacity * 2 : m_capacity;
    std::cout << "new capacity " << m_capacity << std::endl;

    int* temp = new int[m_capacity];
    memcpy(temp, mp_Data, m_size * sizeof(int)); 
    delete[] mp_Data;
    mp_Data = temp;
    m_size = size;
}

void VectorInt::clear()
{
    this->resize(0);
}

int& VectorInt::operator[](const size_t index)
{
    return mp_Data[index];
}
