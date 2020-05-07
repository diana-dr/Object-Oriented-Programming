
#ifndef operation_stack_h
#define operation_stack_h

#include "domain.h"


typedef struct{

    Document* file;
    char* operationType;
    int position;

} Operation;

Operation *createNewOperation(Document *file, char* operationType, int position);
void destroyOperation(Operation *operation);
Operation *copyOperation(Operation *operation);
Document *getDocument(Operation* operation);
char *getOperationType(Operation *operation);
int getOperationPosition(Operation *operation);

typedef struct{

    Operation *operationList[100];
    int size;

} OperationList;

OperationList *createListOfOperations(void);
void destroyListOfOperations(OperationList* listOfOperations);
void addOperation(OperationList* list, Operation* operation);
Operation* returnLastOperation(OperationList *list);
int checkIfFullList(OperationList *list);
int checkIfEmptyList(OperationList *list);

#endif