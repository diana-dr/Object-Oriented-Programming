
#ifndef domain_h
#define domain_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {

    long archiveCatalogueNumber;
    char *stateOfDeterioration;
    char *fileType;
    long yearOfCreation;

} Document;

long getArchiveNumber(Document *element);
char* getStateOfDeterioration(Document *element);
char* getFileType(Document *element);
long getYearOfCreation(Document *element);
Document *createDocument(long archiveCatalogueNumber, char *stateOfDeterioration, char *fileType, long yearOfCreation);
void destroyFile(Document *element);
void setArchiveNumber(Document *element, long newArchiveNumber);
void setStateOfDeterioration(Document *element, char* newStateOfDeterioration);
void setFileType(Document *element, char* newFileType);
void setYearOfCreation(Document *element, long newYearOfCreation);
Document* copyFile(Document *file);

#endif