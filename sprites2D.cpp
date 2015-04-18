#include <nds.h>
#include <maxmod9.h>
#include <stdlib.h>
#include "image.h"
typedef struct  
{
   u16* gfx;
   SpriteSize size;
   SpriteColorFormat format;
   int rotationIndex;
   int paletteAlpha;
   int x;
   int y;
}MySprite;

MySprite sprites = 	{0, SpriteSize_16x16, SpriteColorFormat_256Color, 0, 0, 20, 96};

void CreaPG()
{
	oamInit(&oamMain, SpriteMapping_1D_32, true);
	vramSetBankB(VRAM_B_MAIN_SPRITE);
//allocate some space for the sprite graphics
	sprites.gfx = oamAllocateGfx(&oamMain, sprites.size, sprites.format);
	oamSet(	&oamMain, 							//main graphics engine context
					0,           				//oam index (0 to 127)  
					sprites.x,					//x and y pixel location of the sprite
					sprites.y, 			
					0,							//priority, lower renders last (on top)
					sprites.paletteAlpha,		//palette index 
					sprites.size,
					sprites.format,
					sprites.gfx,				//pointer to the loaded graphics
					sprites.rotationIndex,		//sprite rotation data  
					false,						//double the size when rotating?
					false,						//hide the sprite?
					false, false, 				//vflip, hflip
					false
					);
//send the updates to the hardware
	oamUpdate(&oamMain);
}
