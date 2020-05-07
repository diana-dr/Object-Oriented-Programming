#include "OperationStack.h"

Operation *createNewOperation(Document *file, char* operationType, int i)
{
    Operation *newOperation = (Operation*)malloc(sizeof(Operation));

    newOperation->file = copyFile(file);
    newOperation->position = i;

    if (operationType == NULL)
        newOperation->operationType = NULL;

    else
    {
        newOperation->operationType = (char *)malloc(sizeof(char) * (strlen(operationType) + 1));
        strcpy(newOperation->operationType, operationType);
    }

    return newOperation;
}

void destroyOperation(Operation *operation)
{
    if (operation == NULL)
        return ;

    destroyFile(operation->file);
    free(operation->operationType);
    free(operation);
}

Operation *copyOperation(Operation *operation)
{
    if (operation == NULL)
        return NULL;

    Operation *copyOfOperation = createNewOperation(operation->file, operation->operationType, operation->position);

    return copyOfOperation;
}

Document *getDocument(Operation* operation)
{
    return operation->file;
}

char *getOperationType(Operation *operation)
{
    return  operation->operationType;
}

int getOperationPosition(Operation *operation)
{
    return operation->position;
}

OperationList *createListOfOperations()
{
    OperationList* newList = (OperationList*)malloc(sizeof(OperationList));
    newList->size = 0;

    return newList;
}

void destroyListOfOperations(OperationList* listOfOperations)
{

    if (listOfOperations == NULL)
    {
        return ;
    }

    else {
        for (int i = 0; i < listOfOperations->size; i++) {
            destroyOperation(listOfOperations->operationList[i]);
        }
    }

    free(listOfOperations);
}

void addOperation(OperationList* list, Operation* operation)
{
    if (checkIfFullList(list))
        return ;

    list->operationList[list->size++] = copyOperation(operation);
}

Operation* returnLastOperation(OperationList *list)
{
    if (checkIfEmptyList(list))
        return NULL;

    list->size--;

    return list->operationList[list->size];
}

int checkIfFullList(OperationList *list)
{
    return list->size == 100;
}

int checkIfEmptyList(OperationList *list)
{
    return list->size == 0;
}