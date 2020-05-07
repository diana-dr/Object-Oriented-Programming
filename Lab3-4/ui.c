
#include "ui.h"

UI* createUI(Controller* controller)
{
    UI* user_interface = (UI*)malloc(sizeof(user_interface));
    user_interface->controller = controller;

    return user_interface;
}

void destroyUI(UI* user_interface)
{
    destroyController(user_interface->controller);
    free(user_interface);
}

void splitCommand(char command[], char *splitedCommand[40])
{
    int parameters_number = 0;
    char *stingsOfCommand = strtok(command, " ,?!=/");

    while(stingsOfCommand != NULL)
    {
        strcpy(splitedCommand[parameters_number], stingsOfCommand);
        stingsOfCommand = strtok(NULL, " ,?!=/");
        parameters_number++;
    }
}

int showMenu()
{

    printf("The following operations are allowed:\n");
    printf("Adding a new file:    add <archiveCatalogueNumber> <stateOfDeterioration> <fileType> <yearOfCreation>\n");
    printf("Update a file:        update <archiveCatalogueNumber> <newStateOfDeterioration> <newFileType> <newYearOfCreation>\n");
    printf("Delete a file:        delete <archiveCatalogueNumber>\n");
    printf("List all files:       list\n");
    printf("List files by type:   list <fileType>\n");
    printf("List files by year:   list <yearOfCreation>\n");
    printf("Undo operation:       undo\n");
    printf("Redo operation:       redo\n");
    printf("Exit:                 exit\n");

    return 0;
}

int listFiles_ui(UI* user_interface)
{
    printf("|      Archive Number       |      State Of Deterioration      |     File Type     |    Year Of Creation    |\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < getSize(user_interface->controller->repository->files); i++) {

        Document *file = getElement(user_interface->controller->repository->files, i);

        printf("| %25ld | %32s | %17s |  %21ld | \n", getArchiveNumber(file), getStateOfDeterioration(file),
                getFileType(file), getYearOfCreation(file));
    }
    return 1;
}

int addFile_ui(UI* user_interface, char *command)
{
    Document* file;
    char *input_command[5];
    char *string;

    for (int i = 0; i < 5; i++)
        input_command[i] = malloc(sizeof(char) * 1000);

    splitCommand(command, input_command);

    long archiveCatalogueNumber = strtol(input_command[1], &string, 10);
    long yearOfCreation = strtol(input_command[4], &string, 10);

    file = createDocument(archiveCatalogueNumber, input_command[2], input_command[3], yearOfCreation);

    int result = addFile_controller(user_interface->controller, file);

    if (result == 0)
        printf("The addition cold not be made!\n");
    else
        printf("The file was added successfully!\n");

    return 1;

}

int deleteFile_ui(UI* user_interface, char *command)
{
    char *input_command[5];

    for (int i = 0; i < 5; i++)
        input_command[i] = malloc(sizeof(char) * 100);

    splitCommand(command, input_command);

    int archiveNumber = atoi(input_command[1]);

    for (int i = 0; i < user_interface->controller->repository->files->size; i++)
    {
        Document *file = getElement(user_interface->controller->repository->files, i);
        if (getArchiveNumber(file) == archiveNumber)
        {
            int result = deleteFile_controller(user_interface->controller, file);

            if (result == 0)
                printf("The file cold not be deleted!\n");
            else
                printf("The file was deleted successfully!\n");
        }
    }
    return 1;

}

int updateFile_ui(UI* user_interface, char *command)
{
    char *input_command[5];

    for (int i = 0; i < 5; i++)
        input_command[i] = malloc(sizeof(char) * 1000);

    splitCommand(command, input_command);

    long archiveNumber = atoi(input_command[1]);
    char *newStateOfDeterioration = input_command[2];
    char *newFileType = input_command[3];
    long newYearOfCreation = atoi(input_command[4]);

    Document *oldFile = getFileFromArchiveNumber(user_interface, archiveNumber);
    Document* newFile = createDocument(archiveNumber, newStateOfDeterioration,
                                       newFileType, newYearOfCreation);
    if (oldFile != NULL)
        updateFile_controller(user_interface->controller, oldFile, newFile);

    setStateOfDeterioration(oldFile, newStateOfDeterioration);
    setFileType(oldFile, newFileType);
    setYearOfCreation(oldFile, newYearOfCreation);

    if (oldFile == newFile)
        printf("The file could not be updated!\n");
    else
        printf("File updated!\n");

    return 1;

}

Document* getFileFromArchiveNumber(UI* user_interface, long archiveNumber)
{
    for (int i = 0; i < user_interface->controller->repository->files->size; i++) {
        if (getArchiveNumber(user_interface->controller->repository->files->array[i]) == archiveNumber) {
            return user_interface->controller->repository->files->array[i];
        }
    }
}

int listByArgument_ui(UI* user_interface, char *command)
{
    char *input_command[5];

    for (int i = 0; i < 5; i++)
        input_command[i] = malloc(sizeof(char) * 1000);

    splitCommand(command, input_command);

    char* fileType;
    long yearOfCreation = strtol(input_command[1], &fileType, 10);

    if (yearOfCreation == 0)
        listByType_ui(user_interface, fileType);
    else
        listByYear_ui(user_interface, yearOfCreation);

    return 1;
}

int listByType_ui(UI* user_interface, char *fileType)
{

    printf("|      Archive Number       |      State Of Deterioration      |     File Type     |    Year Of Creation    |\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < user_interface->controller->repository->files->size; i++)
    {
        Document *file = getElement(user_interface->controller->repository->files, i);
        if (strcmp(getFileType(file), fileType) == 0)
        {
            printf("| %25ld | %32s | %17s |  %21ld | \n", getArchiveNumber(file), getStateOfDeterioration(file),
                   getFileType(file), getYearOfCreation(file));
        }
    }
    return 1;
}

DynamicArray* compareState(DynamicArray* givenArray)
{
    int i, j;
    Document* key;

    for (i = 1; i < getSize(givenArray); i++) {
        key = givenArray->array[i];
        j = i - 1;

        while (j >= 0 && strcmp(givenArray->array[j]->stateOfDeterioration, key->stateOfDeterioration) > 0)
        {
            givenArray->array[j + 1] = givenArray->array[j];
            j = j - 1;
        }
        givenArray->array[j + 1] = key;
    }

    return givenArray;
}

int listByYear_ui(UI* user_interface, long year)
{
    DynamicArray* array = compareState(user_interface->controller->repository->files);

    printf("|      Archive Number       |      State Of Deterioration      |     File Type     |    Year Of Creation    |\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < getSize(array); i++)
    {
        Document *file = getElement(array, i);
        if (getYearOfCreation(file) < year)
        {
            printf("| %25ld | %32s | %17s |  %21ld | \n", getArchiveNumber(file), getStateOfDeterioration(file),
                   getFileType(file), getYearOfCreation(file));
        }
    }

    return 1;
}

void addInitialFiles(UI* user_interface)
{
    Document *file1 = createDocument(1291, "extremely deteriorated", "article", 1855);
    Document *file2 = createDocument(6902, "deteriorated", "lecture", 1950);
    Document *file3 = createDocument(5678, "new", "manual", 2006);
    Document *file4 = createDocument(7876, "deteriorated", "glossary", 1989);
    Document *file5 = createDocument(6172, "very deteriorated", "journal", 1899);
    Document *file6 = createDocument(9991, "extremely deteriorated", "technical notes", 1930);
    Document *file7 = createDocument(8181, "new", "yearbook", 2015);
    Document *file8 = createDocument(7171, "deteriorated", "notebook", 1955);

    addFile_controller(user_interface->controller, file1);
    addFile_controller(user_interface->controller, file2);
    addFile_controller(user_interface->controller, file3);
    addFile_controller(user_interface->controller, file4);
    addFile_controller(user_interface->controller, file5);
    addFile_controller(user_interface->controller, file6);
    addFile_controller(user_interface->controller, file7);
    addFile_controller(user_interface->controller, file8);

}