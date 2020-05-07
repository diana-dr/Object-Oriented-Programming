#include "controller.h"

Controller* createController(Repository* repository, OperationList* undoList, OperationList* redoList)
{
    Controller* controller = (Controller*)malloc(sizeof(Controller));
    controller->repository = repository;
    controller->undoList = undoList;
    controller->redoList = redoList;

    return controller;
}

void destroyController(Controller* controller)
{
    destroyRepo(controller->repository);
    free(controller);
}

int addFile_controller(Controller* controller, Document* element)
{
    int result = add_repository(controller->repository, element);

    Operation* operation = createNewOperation(element, "add", getPositionOfElement(controller->repository->files, element));
    addOperation(controller->undoList, operation);
    destroyOperation(operation);

    return result;
}

int deleteFile_controller(Controller* controller, Document* element)
{
    int result = delete_repository(controller->repository, element);

    Operation* operation = createNewOperation(element, "delete", 0);
    addOperation(controller->undoList, operation);
    destroyOperation(operation);

    return result;
}

int updateFile_controller(Controller* controller, Document* old_element, Document* new_element)
{

    Operation *operation = createNewOperation(old_element, "update", 0);
    addOperation(controller->undoList, operation);

    int result = update_repository(controller->repository, old_element, new_element);

    destroyOperation(operation);

    return result;
}

int undo(Controller* controller)
{
    if (checkIfEmptyList(controller->undoList))
    {
        return 0;
    }

    Operation* operation = returnLastOperation(controller->undoList);

    if (strcmp(getOperationType(operation), "add") == 0)
    {
        addOperation(controller->redoList, operation);

        Document* file = getDocument(operation);

        delete_repository(controller->repository, file);
    }

    else if (strcmp(getOperationType(operation), "delete") == 0)
    {
        addOperation(controller->redoList, operation);

        Document* file = getDocument(operation);
        Document* copy_file = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file),
                getYearOfCreation(file));

        add_repository(controller->repository, copy_file);
    }

    else if (strcmp(getOperationType(operation), "update") == 0)
    {
        Document* file = getDocument(operation);
        // Document* newFile = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file),
                // getYearOfCreation(file));
        Document* oldFile = getElement(controller->repository->files, getPositionOfElement(controller->repository->files, file));

        Operation* redoOperation = createNewOperation(oldFile, "update", getPositionOfElement(controller->repository->files, file));
        addOperation(controller->redoList, redoOperation);

        setStateOfDeterioration(oldFile, getStateOfDeterioration(file));
        setYearOfCreation(oldFile, getYearOfCreation(file));
        setFileType(oldFile, getFileType(file));

    }

    destroyOperation(operation);

    return 1;

}

int redo(Controller* controller)
{
    if (checkIfEmptyList(controller->redoList))
    {
        return 0;
    }

    Operation* operation = returnLastOperation(controller->redoList);

    if (strcmp(getOperationType(operation), "add") == 0)
    {
        Document* file = getDocument(operation);

        Document* copy_file = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file),
                getYearOfCreation(file));

        addFile_controller(controller, copy_file);
    }

    else if (strcmp(getOperationType(operation), "delete") == 0)
    {
        Document* file = getDocument(operation);
        Document* copy_file = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file),
                getYearOfCreation(file));

        deleteFile_controller(controller, copy_file);
    }

    else if (strcmp(getOperationType(operation), "update") == 0)
    {
        Document* file = getDocument(operation);
        // Document* newFile = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file),
                //getYearOfCreation(file));
        Document* oldFile = getElement(controller->repository->files, operation->position);

        setStateOfDeterioration(oldFile, getStateOfDeterioration(file));
        setFileType(oldFile, getFileType(file));
        setYearOfCreation(oldFile, getYearOfCreation(file));
    }

    destroyOperation(operation);

    return 1;

}
