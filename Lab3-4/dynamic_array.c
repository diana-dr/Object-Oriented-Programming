
#include "dynamic_array.h"

DynamicArray *initializeDynamicArray(int capacity)
{
    DynamicArray *dynamic_vector = (DynamicArray*)malloc(sizeof(DynamicArray));

    dynamic_vector->array = (TElem*)malloc(capacity * sizeof(TElem));

    dynamic_vector->size = 0;
    dynamic_vector->capacity = capacity;

    return dynamic_vector;
}

void destroyArray(DynamicArray *dynamic_vector)
{
    if (dynamic_vector == NULL)
        return ;

    for (int i = 0; i < dynamic_vector->size; i++)
        destroyFile(dynamic_vector->array[i]);

    free(dynamic_vector->array);
    free(dynamic_vector);
}

void resize(DynamicArray* dynamic_vector)
{
    dynamic_vector->capacity *= 2;

    TElem* array2 = (TElem*)malloc(dynamic_vector->capacity * sizeof(TElem));

    for (int i = 0; i < dynamic_vector->size; i++)
        array2[i] = dynamic_vector->array[i];

    free(dynamic_vector->array);

    dynamic_vector->array = array2;
}

void addElement(DynamicArray *dynamic_vector, TElem element)
{
    if (dynamic_vector == NULL)
        return ;

    if (dynamic_vector->array == NULL)
        return ;

    if (dynamic_vector->size >= dynamic_vector->capacity)
        resize(dynamic_vector);

    dynamic_vector->array[dynamic_vector->size++] = element;
}

void deleteElement(DynamicArray *dynamic_vector, int position)
{
    if (dynamic_vector == NULL)
        return ;

    if (dynamic_vector->array == NULL)
        return ;

    if (position < 0 || position >= dynamic_vector->size)
        return ;

    for (int i = position; i < dynamic_vector->size; i++)
        dynamic_vector->array[i] = dynamic_vector->array[i + 1];

    dynamic_vector->size--;

}

void updateElement(DynamicArray *dynamic_vector, TElem element, long position)
{
    if (dynamic_vector == NULL)
        return ;

    if (dynamic_vector->array == NULL)
        return ;

    dynamic_vector->array[position] = element;
}

int getSize(DynamicArray *dynamic_vector)
{
    return dynamic_vector->size;
}

TElem getElement(DynamicArray* dynamic_vector, int position)
{
    return dynamic_vector->array[position];
}

int getPositionOfElement(DynamicArray* dynamic_vector, TElem element)
{

    for (int i = 0; i < dynamic_vector->size; i++)
    {
        if (dynamic_vector->array[i]->archiveCatalogueNumber == element->archiveCatalogueNumber)
            return i;
    }

    return 8;
}