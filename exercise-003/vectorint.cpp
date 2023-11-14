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

VectorInt::VectorInt(VectorInt& src)
{
    mp_Data = new int(1);
    copy_data(src);
    std::cout << "Copy Constructor called\n";
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

auto VectorInt::operator=(const VectorInt& src) -> VectorInt&
{
    copy_data(src);
    return *this;
}

void VectorInt::copy_data(const VectorInt& src)
{
    m_size =  src.m_size;
    m_capacity = src.m_capacity;
    delete[] mp_Data;
    mp_Data = new int[m_size];

    if (src.mp_Data)
    {
        memcpy(mp_Data, src.mp_Data, src.m_size * sizeof(int));
    }
    else 
    {
        std::cout << "source Data was null\n";
    }

}
