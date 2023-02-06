.586P												
.MODEL FLAT, STDCALL										
includelib kernel32.lib										

ExitProcess PROTO : DWORD
getmax PROTO : SDWORD, : DWORD
getmin PROTO : SDWORD, : DWORD

.STACK 4096

.CONST

.DATA
Array SDWORD 1, 2, 3, 4, 70, 6, 7, 8, 9, 0
LengthArray DWORD lengthof Array

.CODE

;////////////////////////////////////////////////////////////////////
main PROC

	INVOKE getmax, OFFSET Array, LengthArray

	INVOKE getmin, OFFSET Array, LengthArray

	push 0
	call ExitProcess
main ENDP
;////////////////////////////////MAX////////////////////////////////////

getmax PROC uses ESI ECX, PtrArr: SDWORD, ArrLength: DWORD
    
	mov ECX, ArrLength
	mov ESI, PtrArr

	mov EAX, -2147483648

CYCLE:
		
	cmp EAX, [ESI]
	jl max
	ret_to_CYCLE:

	add esi, 4

loop CYCLE
	ret

max:
	mov EAX, [ESI]
	jmp ret_to_CYCLE


getmax ENDP

;/////////////////////////////////MIN///////////////////////////////////

getmin PROC uses ESI ECX, PtrArr: SDWORD, ArrLength: DWORD
    
	mov ECX, ArrLength
	mov ESI, PtrArr

	mov EAX, 2147483647

CYCLE:
		
	cmp EAX, [ESI]
	jg min
	ret_to_CYCLE:

	add esi, 4

loop CYCLE
	ret

min:
	mov EAX, [ESI]
	jmp ret_to_CYCLE


getmin ENDP

end main