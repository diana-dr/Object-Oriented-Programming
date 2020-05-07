
#include "repository.h"

Repository* createRepo()
{
    Repository* repo = (Repository*)malloc(sizeof(Repository));
    repo->files = initializeDynamicArray(30);

    return repo;
}

void destroyRepo(Repository *repository)
{
    if (repository == NULL)
        return ;

    destroyArray(repository->files);
    free(repository);
}

int searchForElement(Repository *repository, Document *element)
{
    for (int i = 0; i < repository->files->size; i++)
    {
        if (getArchiveNumber(element) == getArchiveNumber(repository->files->array[i]))
        {
            return i;
        }
    }
    return 0;
}

int add_repository(Repository *repository, Document *element)
{
    if (searchForElement(repository, element) == 0)
    {
        addElement(repository->files, element);
        return 1;
    }

    return 0;
}

int delete_repository(Repository *repository, Document *element)
{
    int position = searchForElement(repository, element);

    if (position != -1)
    {
        deleteElement(repository->files, position);
        return 1;
    }

    return 0;
}

int update_repository(Repository *repository, Document *old_element, Document *new_element)
{
    int findOldElement = searchForElement(repository, old_element);
    int findNewElement = searchForElement(repository, new_element);

    if (findNewElement != -1 || findOldElement != -1)
        return 0;

    updateElement(repository->files, new_element, getArchiveNumber(old_element));
    return -1;
}

