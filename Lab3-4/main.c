
#include "ui.h"

int main()
{
    OperationList* undoList = createListOfOperations();
    OperationList* redoList = createListOfOperations();

    Repository* repository = createRepo();
    Controller *controller = createController(repository, undoList, redoList);
    UI* ui = createUI(controller);

    char input_command[100];
    char copy_input[100];
    addInitialFiles(ui);
    showMenu();
    while(1)
    {
        printf("Choose: ");
        gets(input_command);
        strcpy(copy_input, input_command);
        char *option = strtok(copy_input, " ,=/");

        if (strcmp(option, "exit") == 0) {
            break;
        }

        else if (strcmp(option, "add") == 0) {
            addFile_ui(ui, input_command);
        }

        else if (strcmp(option, "delete") == 0) {
            deleteFile_ui(ui, input_command);
        }

        else if (strcmp(option, "update") == 0) {
            updateFile_ui(ui, input_command);
        }

        else if (strcmp(option, "list") == 0) {
            if (strcmp(option, input_command) == 0)
                listFiles_ui(ui);
            else
            {
                listByArgument_ui(ui, input_command);
            }
        }

        else if (strcmp(option, "undo") == 0) {
            if (undo(ui->controller) != 1) {
                printf("No more undo!\n");
            }
        }

        else if (strcmp(option, "redo") == 0) {
            if(redo(ui->controller) != 1) {
                printf("No more redo!\n");
            }
        }

        else
            printf("Invalid input_command!\n");
    }

    destroyListOfOperations(undoList);
    destroyListOfOperations(redoList);
    destroyUI(ui);

    return 0;
}

