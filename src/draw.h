#ifndef DRAW_H
#define DRAW_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <stdint.h>
#include <gccore.h>

void VIDEO_DrawInit();
void VIDEO_SetPixel(uint16_t x, uint16_t y, uint32_t rgb);
void VIDEO_UpdateBuffer();
void VIDEO_ClearBuffer(uint32_t rgb);

#endif