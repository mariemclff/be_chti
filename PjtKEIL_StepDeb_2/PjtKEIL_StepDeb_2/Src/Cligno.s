	PRESERVE8
	THUMB   
		
    import GPIOB_Set
	import GPIOB_Clear
	export timer_callback
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly
 

;Section RAM (read write):
	area    maram,data,readwrite
		

;char FlagCligno;
		
FlagCligno dcd 0

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

	
;void timer_callback(void)
;{

timer_callback proc
;	if (FlagCligno==1)
;	{

	ldr r1, =FlagCligno
	ldr r0, [r1]
	cmp r0, #1
	beq toto
	
	
;	}
;	else
;	{
	
;		FlagCligno=1;
	mov r0, #1
	str r0,[r1]
;		GPIOB_Clear(1);
	mov r0, #1
	push {lr,r0-r3}
	bl GPIOB_Clear
	pop {lr,r0-r3}
	bx lr
;	}

toto
;		FlagCligno=0;
	mov r0, #0
	str r0,[r1]
;		GPIOB_Set(1);
	mov r0, #1
	push {lr,r0-r3}
	bl GPIOB_Set
	pop {lr,r0-r3}
	bx lr
	
	endp
;
;
;
;




		
		
	END	