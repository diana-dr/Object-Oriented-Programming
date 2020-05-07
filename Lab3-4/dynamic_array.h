
#ifndef dynamic_array_h
#define dynamic_array_h

#include "domain.h"

typedef Document* TElem;

typedef struct {
    TElem *array;
    int size;
    int capacity;

} DynamicArray;

DynamicArray *initializeDynamicArray(int capacity);
void destroyArray(DynamicArray *dynamic_vector);
void resize(DynamicArray* dynamic_vector);
void addElement(DynamicArray *dynamic_vector, TElem element);
void deleteElement(DynamicArray *dynamic_vector, int position);
void updateElement(DynamicArray *dynamic_vector, TElem element, long position);
int getSize(DynamicArray *dynamic_vector);
TElem getElement(DynamicArray *dynamic_vector, int position);
int getPositionOfElement(DynamicArray* dynamic_vector, TElem element);

#endif //dynamic_array_h
