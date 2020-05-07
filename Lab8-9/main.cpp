#include <iostream>
#include "Tests.hpp"
#include "UI.hpp"
#define _CRT_SECURE_NO_WARNINGS


int main() {
    
    //TestAll();
    
    Repository repository{};
    Controller controller{ repository };
    UI ui{ controller };
    ui.run();
    
    return 0;
}
