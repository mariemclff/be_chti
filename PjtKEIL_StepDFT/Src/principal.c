
#include "DriverJeuLaser.h"

int DFT_ModuleAuCarre(short int * signal, int index);

extern short int LeSignal;


// tableau de 64 cases et on met les calculs avec les 64 k

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
	
	int tab[64] ;
	
	for (int i = 0; i<64; i++){
		tab[i] = DFT_ModuleAuCarre( &LeSignal, i) ;
		//on tst on v�rifie que nous avons bien 16 � k=1, k=63

	}
	

//============================================================================	
	
	
while	(1)
	{
	}
}

