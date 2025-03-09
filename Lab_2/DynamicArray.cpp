#include "DynamicArray.h"
#include <cstring>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    this->m_scaling_factor = scaling_factor;
    this->m_capacity = capacity;
    this->m_length = 0;
    m_data = new int[capacity];
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this->m_scaling_factor = scaling_factor;
    this->m_length = length;
    this->m_capacity = length;
    m_data = new int[length];
    for (unsigned int i = 0; i < length; i++) {
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");

    for (unsigned int i = 0; i < m_length; i++) {
        str += std::to_string(m_data[i]);
        if (i < m_length - 1) {
            str += " ";
        }
    }

    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;

    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    return found;
}

void DynamicArray::append(int value) {
    if (m_length == m_capacity) {
        m_capacity = (m_capacity * m_scaling_factor);
        int* temp_data = new int[m_capacity];

        for (unsigned int i = 0; i < m_length; i++) {
            temp_data[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp_data;
    }

    m_data[m_length] = value;
        m_length++;
}

void DynamicArray::prepend(int value) {
    if (m_length == m_capacity) {
        m_capacity = m_capacity * m_scaling_factor;
    }
    int* temp_data = new int[m_capacity];

    for (unsigned int i = 0; i < m_length; i++) {
        temp_data[i + 1] = m_data[i];
    }

    temp_data[0] = value;

    delete[] m_data;
    m_data = temp_data;

    m_length++;
}

void DynamicArray::remove_last() {

}

void DynamicArray::remove_first() {
    //..............
    // TODO
    //..............
}

void DynamicArray::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}
