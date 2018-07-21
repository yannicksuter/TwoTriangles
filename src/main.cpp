#include "twotriangles.h"

int main() {
    if (System::Instance()->Initialize(1024, 768, 1, false)) {
        System::Instance()->Run();
    }
    return 0;
}