
#ifndef repository_h
#define repository_h

#include "dynamic_array.h"

typedef struct
{
    DynamicArray *files;
} Repository;

Repository* createRepo();
void destroyRepo(Repository *repository);
int searchForElement(Repository *repository, Document *element);
int add_repository(Repository *repository, Document *element);
int delete_repository(Repository *repository, Document *element);
int update_repository(Repository *repository, Document *old_element, Document *new_element);


#endif //LAB3_4_REPOSITORY_H
