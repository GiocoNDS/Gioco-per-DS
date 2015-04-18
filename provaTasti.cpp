#include <nds.h>
#include <stdio.h>

const int width = 256;
const int height = 192;

void KeysPress(int keys)
{
	int sx = 0,sy = 0;
	switch (keys)
	{
		case KEY_UP: /* iprintf("-UP"); */
			sy--;
			if(sy < 0) 
				sy = 0;
			break;
		case KEY_LEFT: /* iprintf("-LEFT"); */
			sx--;
			if(sx < 0) 
				sx = 0;
			break;
		case KEY_DOWN: /* iprintf("-DOWN"); */
			sy++; 
			if(sy >= height - height) 
				sy = height - (height + 1);
			break;
		case KEY_RIGHT: /* iprintf("-RIGHT"); */
			sx++;
			if(sx >= width - width)
				sx = width - (width + 1);
			break;
		case KEY_A: /* iprintf("-A"); */break;
		case KEY_B: /* iprintf("-B"); */break;
		case KEY_X: /* iprintf("-X"); */break;
		case KEY_Y: /* iprintf("-Y"); */break;
		case KEY_L:/*  iprintf("-L"); */break;
		case KEY_R: /* iprintf("-R"); */break;
		case KEY_START: consoleClear(); 
			/* iprintf("\nSTART\n"); */break;
		case KEY_SELECT: /* iprintf("\nSELECT\n"); */break;
		case KEY_TOUCH: /*iprintf("\nTOUCH\n");*/break;
	}
	REG_BG0HOFS = sx;
    REG_BG0VOFS = sy;
}
