#include <nds.h>
#include <stdio.h>
#include <maxmod9.h>

void KeysPress(int k);
void Sfondo();
void CreaPG();

int main(void)
{
	videoSetMode(MODE_5_2D);	
	consoleDemoInit();
	scanKeys();
	int c = keysHeld();
	Sfondo();
	CreaPG();
	while(true) 
	{
		swiWaitForVBlank();			
		if(c!=0)
		{
			KeysPress(c);
			//iprintf("-key:%i\n",c);
			c = 0;
		}
		else 
		{//Nessun tasto premuto
			scanKeys();
			c = keysHeld();
		}
	}
	return 0;	
}
