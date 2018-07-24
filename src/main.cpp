#include "twotriangles.h"

int main() {
    if (System::Instance()->initialize(1024, 768, 1, false)) {
        System::Instance()->run(new Renderer());
    }
    return 0;
}