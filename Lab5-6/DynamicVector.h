#include <iostream>
#include <stdio.h>
#include <string.h>
//#include "domain.hpp"

template <typename Template>
class DynamicVector
{
private:
    Template *elements;
    int capacity, size;
public:
    DynamicVector()
    {
        capacity = 2;
        size = 0;
        elements = new Template[capacity];
    }

    ~DynamicVector()
    {
        capacity = 0;
        size = 0;
        delete []elements;
    }

    DynamicVector(const DynamicVector& other)
    {
        capacity = other.capacity;
        size = other.size;
        elements = new Template[capacity];
        for(int i = 0 ; i < other.size; ++ i)
            elements[i] = other.elements[i];
    }

    //function to add a T element
    void add(const Template element) {
        if(size == capacity)
        {
            capacity *= 2;
            Template* new_elements = new Template[capacity];
            for(int i = 0 ; i < capacity / 2 ; ++ i)
                new_elements[i] = elements[i];
            delete [] elements;
            elements = new_elements;
        }
        elements[size] = element;
        ++ size;
    }

    void remove(const Template element, int position) {
        if (this->elements == nullptr)
            return;

        if (position < 0 || position >= this->size)
            return;

        for (int i = position; i < this->size; i++)
            this->elements[i] = this->elements[i + 1];

        this->size--;
    }

    void update(const Template element, int position) {
        this->elements[position] = element;
    }

    DynamicVector& operator=(const DynamicVector& other)
    {

        if (this == &other)
            return *this;


        this->capacity = other.capacity;
        this->length = other.length;

        Template* aux =  new Template[this->capacity];

        delete [] this->arr;
        this->arr = aux;
        for(int i = 0 ; i < other.length; ++ i)
            this->arr[i] = other.arr[i];
        return *this;
    }

    //returns the size of the dynamic vector
    int getSize() const
    {
        return size;
    }

    //returns an element from a given position
    //enables us to use []
    inline Template& operator [] (int pos)
    {
        return elements[pos];
    }

    void clear()
    {
        capacity = 2;
        size = 0;
        delete []elements;
        elements = new Template[capacity];
    }

    Template* getElem(const int i)
    {
        return this->elements[i];
    }

    Template* getAllElements() const
    {
        return this->elements;
    }

};
