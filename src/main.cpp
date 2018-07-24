#include "twotriangles.h"
//#include <unistd.h>

int main() {
//    char cwd[1024];
//    getcwd(cwd, sizeof(cwd));

    if (System::Instance()->initialize(1024, 768, 1, false)) {
        System::Instance()->run(new Renderer());
    }
    return 0;
}