#include "draw.h"

uint32_t *framebuffer[3];
uint8_t curr_buffer;

uint32_t yuva(uint32_t rgb) {
    uint8_t r = (rgb >> 16) & 0xFF;
    uint8_t g = (rgb >> 8) & 0xFF;
    uint8_t b = rgb & 0xFF;

    uint8_t y, pb, pr, a;
    y = 16 + 0.257*r + 0.504*g + 0.098*b;
    pb = 128 - 0.148*r - 0.291*g + 0.439*b;
    pr = 128 + 0.439*r - 0.368*g - 0.071*b;
    a = (g == 0) ? 0 : (pr + pb + y);
    return (y << 24) | (pb << 16) | (a << 8) | pr;
}

void VIDEO_DrawInit() {
    VIDEO_Init();

    GXRModeObj *rmode = VIDEO_GetPreferredMode(NULL);
    rmode->fbWidth = 640;
    rmode->efbHeight = 480;
    rmode->viWidth = 640;
    rmode->viHeight = 480;
    VIDEO_Configure(rmode);

    framebuffer[0] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    framebuffer[1] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    framebuffer[2] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

    VIDEO_SetBlack(FALSE);

    curr_buffer = 0;
    VIDEO_SetNextFramebuffer(framebuffer[curr_buffer]);

    VIDEO_Flush();
}

inline void VIDEO_SetPixel(uint16_t x, uint16_t y, uint32_t rgb) {
    framebuffer[curr_buffer][x + y * SCREEN_WIDTH] = yuva(rgb);
}

void VIDEO_ClearBuffer(uint32_t rgb) {
    uint32_t color = yuva(rgb);
    for (int i = 0; i < (SCREEN_HEIGHT * SCREEN_WIDTH); i++) {
        framebuffer[curr_buffer][i] = color;
    }
}

void VIDEO_UpdateBuffer() {
    VIDEO_SetNextFramebuffer(framebuffer[curr_buffer]);

    curr_buffer = (curr_buffer == 2) ? 0 : (curr_buffer + 1);

    VIDEO_Flush();
    VIDEO_WaitVSync();
}