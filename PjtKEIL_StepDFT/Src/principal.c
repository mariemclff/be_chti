
#include "DriverJeuLaser.h"

int DFT_ModuleAuCarre(short int * signal, int index);

extern short int LeSignal;


// tableau de 64 cases et on met les calculs avec les 64 k

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	
	int tab[64] ;
	
	for (int i = 0; i<64; i++){
		tab[i] = DFT_ModuleAuCarre( &LeSignal, i) ;
		//on tst on vérifie que nous avons bien 16 à k=1, k=63

	}
	

//============================================================================	
	
	
while	(1)
	{
	}
}

