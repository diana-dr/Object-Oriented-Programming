
#include "domain.h"

Document *createDocument(long archiveCatalogueNumber, char *stateOfDeterioration, char *fileType, long yearOfCreation)
{
    Document *newFile = (Document*)malloc(sizeof(Document));

    newFile->archiveCatalogueNumber = archiveCatalogueNumber;

    newFile->stateOfDeterioration = (char*)malloc(sizeof(char) * (strlen(stateOfDeterioration) + 1));
    strcpy(newFile->stateOfDeterioration, stateOfDeterioration);

    newFile->fileType = (char*)malloc(sizeof(char) * (strlen(fileType) + 1));
    strcpy(newFile->fileType, fileType);

    newFile->yearOfCreation = yearOfCreation;

    return newFile;
}

void destroyFile(Document *element)
{
    if (element == NULL)
    {
        return ;
    }

    free(element->stateOfDeterioration);
    free(element->fileType);

    free(element);
}

long getArchiveNumber(Document *element)
{
    return element->archiveCatalogueNumber;
}

char* getStateOfDeterioration(Document *element)
{
    return element->stateOfDeterioration;
}

char* getFileType(Document *element)
{
    return element->fileType;
}

long getYearOfCreation(Document *element)
{
    return element->yearOfCreation;
}

void setArchiveNumber(Document *element, long newArchiveNumber)
{
    element->archiveCatalogueNumber = newArchiveNumber;
}

void setStateOfDeterioration(Document *element, char* newStateOfDeterioration)
{
    strcpy(element->stateOfDeterioration, newStateOfDeterioration);
}

void setFileType(Document *element, char* newFileType)
{
    strcpy(element->fileType, newFileType);
}

void setYearOfCreation(Document *element, long newYearOfCreation)
{
    element->yearOfCreation = newYearOfCreation;
}

Document* copyFile(Document *file)
{
    if (file == NULL)
        return NULL;

    Document *copyOfFile = createDocument(getArchiveNumber(file), getStateOfDeterioration(file), getFileType(file), getYearOfCreation(file));

    return copyOfFile;
}