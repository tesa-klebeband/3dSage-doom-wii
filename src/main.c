#include "engine.h"
#include "draw.h"

int main() {
    VIDEO_DrawInit();
    fatInitDefault();
    init();

    while(1) {
        display();
        VIDEO_UpdateBuffer();
    }

    return 0;
}
