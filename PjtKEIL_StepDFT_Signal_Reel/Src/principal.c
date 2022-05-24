
#include "DriverJeuLaser.h"
#include "sony.h"
#include "DriverJeuLaser.h"
int DFT_ModuleAuCarre(short int * signal, int index);
void systick_callback(void);

extern short int LeSignal;
short int dma_buf[64];
int joueur = -1;
int n =0;
int score[4];


// tableau de 64 cases et on met les calculs avec les 64 k


	int tab[64] ;


int main(void){

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
Systick_Period_ff(36000);
Systick_Prio_IT( 2 , 	systick_callback);
SysTick_On ;
	

Init_TimingADC_ActiveADC_ff( ADC1, 72);
	//72 périodes d'horloge à 72MHz donne 1µs).
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	// 0 du premier argument traduit un remplissage linéaire de la RAM par opposition à un remplissage circulaire cyclique, valeur 1


SysTick_Enable_IT ;

	
	
// config son
Timer_1234_Init_ff(TIM4, 6522);
Active_IT_Debordement_Timer(TIM4,2, CallbackSon);
PWM_Init_ff(TIM3,3,720);
GPIO_Configure(GPIOB,0, OUTPUT, ALT_PPULL);



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
		//on tst on vérifie que nous avons bien 16 à k=1, k=63
		}
if (tab[17] > 0x000F12BA){
	if(joueur==0) {
		n++;
		if (n==15){
			score[0]++;
			n=0;
			StartSon();
		}
	}else{
		joueur = 0;
		n=0;
	}
}
else if (tab[19] > 0x000F12BA){
	if(joueur==1) {
		n++;
		if (n==15){
			score[1]++;
			n=0;
			StartSon();
		}
	}else{
		joueur = ;
		n=0;
	}
}

else if (tab[23] > 0x000F12BA){
	if(joueur==2) {
		n++;
		if (n==15){
			score[2]++;
			n=0;
			StartSon();
		}
	}else{
		joueur = 2;
		n=0;
	}
}else if (tab[24] > 0x000F12BA){
	if(joueur==3) {
		n++;
		if (n==15){
			score[3]++;
			n=0;
			StartSon();
		}
	}else{
		joueur = 3;
		n=0;
	}
}
}


			
		