
#include "DriverJeuLaser.h"

int DFT_ModuleAuCarre(short int * signal, int index);
void systick_callback(void);

extern short int LeSignal;
short int dma_buf[64];


// tableau de 64 cases et on met les calculs avec les 64 k


	int tab[64] ;


int main(void){

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
Systick_Period_ff(36000);
Systick_Prio_IT( 2 , 	systick_callback);
SysTick_On ;
	
	
Init_TimingADC_ActiveADC_ff( ADC1, 72);
	//72 p�riodes d'horloge � 72MHz donne 1�s).
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	// 0 du premier argument traduit un remplissage lin�aire de la RAM par opposition � un remplissage circulaire cyclique, valeur 1


SysTick_Enable_IT ;

	
	
	
	

//============================================================================	
	
	
while	(1)
	{
	}
}
void systick_callback(void){

	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	
	for (int i = 0; i<64; i++){
		tab[i] = DFT_ModuleAuCarre( dma_buf , i) ;
		//on tst on v�rifie que nous avons bien 16 � k=1, k=63

	}
	

}
