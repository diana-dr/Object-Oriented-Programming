
#ifndef ui_h
#define ui_h

#include "controller.h"

typedef struct {
    Controller* controller;
} UI;

UI* createUI(Controller* controller);
void destroyUI(UI* user_interface);
void splitCommand(char command[], char *tok[40]);
int showMenu();
int listFiles_ui(UI* user_interface);
int addFile_ui(UI* user_interface, char *command);
int deleteFile_ui(UI* user_interface, char *command);
int updateFile_ui(UI* user_interface, char *command);
int listByType_ui(UI* user_interface, char *command);
void addInitialFiles(UI* user_interface);
int listByYear_ui(UI* user_interface, long year);
int listByArgument_ui(UI* user_interface, char *command);
DynamicArray* compareState(DynamicArray* array);
Document* getFileFromArchiveNumber(UI* user_interface, long archiveNumber);
int findGap(int gap);

#endif //LAB3_4_UI_H
