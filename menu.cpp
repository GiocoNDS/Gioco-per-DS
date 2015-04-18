// Librerie
#include <nds.h>
#include <stdio.h>

// Immagini
#include <bgMenu.h>
#include <schermataIniziale.h>

void initialize()
{
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

    videoSetModeSub(MODE_5_2D);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	
	// Mette lo sfondo sullo schermo superiore
    int bg = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(bgMenuBitmap, bgGetGfxPtr(bg), 256*256);
    dmaCopy(bgMenuPal, BG_PALETTE, 256*2);

	// Mette lo sfondo sullo schermo inferiore
    int bgsub = bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(bgMenuBitmap, bgGetGfxPtr(bgsub), 256*256);
    dmaCopy(bgMenuPal, BG_PALETTE_SUB, 256*2);
}

void menuFunction()
{
	initialize();
}
