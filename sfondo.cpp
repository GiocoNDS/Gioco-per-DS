#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "image2.h"

void Sfondo()
{
	videoSetModeSub(MODE_5_2D);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	
	int bg3 = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(imageBitmap,bgGetGfxPtr(bg3),sizeof(imageBitmap));
    dmaCopy(imagePal,BG_PALETTE,sizeof(imagePal));
	
	int bg3sub = bgInitSub(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(image2Bitmap, bgGetGfxPtr(bg3sub), sizeof(image2Bitmap));
    dmaCopy(image2Pal, BG_PALETTE_SUB,sizeof(image2Pal));
}
