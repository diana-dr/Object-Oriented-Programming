
#ifndef controller_h
#define controller_h

#include "repository.h"
#include "OperationStack.h"

typedef struct{
    Repository* repository;
    OperationList* undoList;
    OperationList* redoList;
} Controller;

Controller* createController(Repository* repository, OperationList *undoList, OperationList *redoList);
void destroyController(Controller* controller);
int addFile_controller(Controller* controller, Document* element);
int deleteFile_controller(Controller* controller, Document* element);
int updateFile_controller(Controller* controller, Document* old_element, Document* new_element);
int redo(Controller* controller);
int undo(Controller* controller);

#endif //controller
