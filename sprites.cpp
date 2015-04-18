#include <nds.h>
#include <maxmod9.h>
#include "Vegeta.h"

void CreaPG()
{
	int spritesX=100, spritesY=100;
	videoSetMode(MODE_0_2D);
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	vramSetBankA(VRAM_A_MAIN_SPRITE);
	u16* gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	dmaCopy(VegetaTiles, gfx, 32*32);
	dmaCopy(VegetaPal, SPRITE_PALETTE, VegetaPalLen);
	oamSet(	&oamMain, 							//main graphics engine context
			0,           						//oam index (0 to 127)  
			spritesX,							//x and y pixel location of the sprite
			spritesY,
			0,
			0,									//palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_32x32,
			SpriteColorFormat_256Color,
			gfx,								//pointer to the loaded graphics
			-1,									//sprite rotation data  
			false,								//double the size when rotating?
			false,								//hide the sprite?
			false, false, 						//vflip, hflip
			false								//apply mosaic
			);
	swiWaitForVBlank();
	oamUpdate(&oamMain);
}
