	PRESERVE8
	THUMB   
		
	import LongueurSon
	import Son
		
	include DriverJeuLaser.inc
		
	export SortieSon
	export CallbackSon
	export IndTable

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
	
SortieSon dcw 0
IndTable dcd 0


	
; ===============================================================================================
	
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici	

StartSon proc
	; on met indice table à 0
	push {lr}
	mov r0, #0
	str r0, [r1]	
	pop {lr}
	bx lr
	endp 

CallbackSon proc

;si (IndTable <= longueur plage)
	push {lr, r4-r7}

	ldr r1, =IndTable ; r1 contient @ IndTable
	ldr r0, [r1] ; r0 contient valeur IndTable
	ldr r3, =LongueurSon ; r3 contient @ LongueurSon
	ldr r2, [r3] ; r2 contient valeur LongueurSon
	
	cmp r0, r2
	bgt finTable
	
	
	ldr r4, =Son ; r4 contient @ Son
	
	ldrsh r6, [r4, r0, lsl #1] 
	
	ldr r5, =SortieSon ; r5 contient @ SortieSon
	
; mise à l'échelle

	add r6, #32768
	mov r7, #720
	mul r6, r6, r7
	asr r6, #16

;	Sortir Rx
	
	str r6, [r5]
	
	push {r0-r1}
	mov r0, r6
	bl PWM_Set_Value_TIM3_Ch3
	pop {r0-r1}
	
	;	IndTable ++ 
	add r0, #1
	str r0, [r1]
	bl fin
	
finTable
	bl StartSon
	
fin
	
	pop {lr, r4-r7}
	
	bx lr
	
	endp
		
		
	END