#include <nds.h>
#include <logo1.h>
#include <schermataIniziale.h>
#include <schermataInizialeSopra.h>
#include <image.h>

// Mostra, all'inizio dell'esecuzione, i loghi delle software house che hanno creato il progetto
void loghi()
{
	consoleDemoInit();
	
	// set the mode for 2 text layers and two extended background layers
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

    videoSetModeSub(MODE_5_2D);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	
	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);
	dmaCopy(logo1Bitmap, bgGetGfxPtr(bg3), 256*256);
	dmaCopy(logo1Pal, BG_PALETTE, 256*2);
	
    int bgsub = bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(imageBitmap, bgGetGfxPtr(bgsub), sizeof(imageBitmap));
    dmaCopy(imagePal, BG_PALETTE_SUB, sizeof(imagePal));

	for(int i=0; i<100; i++)
	{
		swiWaitForVBlank();
	}
}

// Mostra la schermata del titolo
void schermataIniziale()
{
	int tasto;
	
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

    videoSetModeSub(MODE_5_2D);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	
	int bg = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(schermataInizialeSopraBitmap, bgGetGfxPtr(bg), sizeof(schermataInizialeSopraBitmap));
    dmaCopy(schermataInizialeSopraPal, BG_PALETTE, sizeof(schermataInizialeSopraPal));

    int bgsub = bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 0,0);
    dmaCopy(schermataInizialeBitmap, bgGetGfxPtr(bgsub), sizeof(schermataInizialeBitmap));
    dmaCopy(schermataInizialePal, BG_PALETTE_SUB, sizeof(schermataInizialePal));
	
	// Se vengono premuti il tasto start, il tasto A oppure viene toccato il touch screen termina il ciclo
	while(tasto != KEY_START && tasto != KEY_TOUCH && tasto != KEY_A)
	{
		scanKeys();
		tasto = keysHeld();
	}
}
