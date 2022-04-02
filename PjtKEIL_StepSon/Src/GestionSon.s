	PRESERVE8
	THUMB   
		
	import LongueurSon
	import Son
		
	export SortieSon
	export CallbackSon
	export IndTable

; ====================== zone de r�servation de donn�es,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
	
SortieSon dcw 0
IndTable dcd 0


	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; �crire le code ici	

CallbackSon proc

;si (IndTable <= longueur plage)
	push {lr, r4-r7}

	ldr r1, =IndTable ; r1 contient @ IndTable
	ldr r0, [r1] ; r0 contient valeur IndTable
	ldr r3, =LongueurSon ; r3 contient @ LongueurSon
	ldr r2, [r3] ; r2 contient valeur LongueurSon
	
	cmp r0, r2
	bgt fin
	
	ldr r4, =Son ; r4 contient @ Son
	
	ldrsh r6, [r4, r0, lsl #1] 
	
	ldr r5, =SortieSon ; r5 contient @ SortieSon
	
; mise � l'�chelle

	add r6, #32768
	mov r7, #720
	mul r6, r6, r7
	asr r6, #16

;	Sortir Rx
	
	str r6, [r5]

fin

;	IndTable ++ 
	
	add r2, #1
	str r2, [r1]
	
	pop {lr, r4-r7}
	
	bx lr
	
	endp
		
		
	END