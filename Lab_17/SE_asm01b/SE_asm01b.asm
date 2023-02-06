.586P														
.MODEL FLAT, STDCALL										
includelib kernel32.lib	
;includelib SE_asm01a.lib

;////////////////////////////////////////////////////////////////////
SetConsoleTitleA PROTO :DWORD
GetStdHandle	 PROTO :DWORD
WriteConsoleA	 PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
;////////////////////////////////////////////////////////////////////

ExitProcess PROTO : DWORD
getmax PROTO : SDWORD, : DWORD
getmin PROTO : SDWORD, : DWORD

.STACK 4096

.CONST
;////////////////////////////////////////////////////////////////////
consoletitle db 'SE_asm01.asm', 0
helloworld   db 'getmax + getmin = ',0
;////////////////////////////////////////////////////////////////////

.DATA
Array SDWORD 0, 10, 20
LengthArray DWORD lengthof Array

res byte 40 dup(0)

consolehandle dd 0h

.CODE


main PROC

	INVOKE getmax, OFFSET Array, LengthArray
	mov ebx, eax

	INVOKE getmin, OFFSET Array, LengthArray
	mov edx, eax

	add ebx, edx

	push ebx
	push offset res
	call int_to_char

;////////////////////////////////////////////////////////////////////
	INVOKE SetConsoleTitleA, offset consoletitle

	INVOKE GetStdHandle, -11
	mov consolehandle, eax

	INVOKE WriteConsoleA, consolehandle, offset helloworld, sizeof helloworld, 0, 0
	INVOKE WriteConsoleA, consolehandle, offset res, sizeof res, 0, 0
;////////////////////////////////////////////////////////////////////
	

	push 0
	call ExitProcess
main ENDP

;////////////////////////////////////////////////////////////////////
int_to_char PROC uses eax ebx ecx edi esi,
					 pstr: dword,
					 intfield: dword

	mov edi, pstr
	mov esi, 0 
	mov eax, intfield
	cdq
	;-----------------
	mov ebx, 10
	idiv ebx
	;-----------------
	test eax,80000000h
	jz plus
	neg eax
	neg edx
	mov cl, '-'
	mov [edi],cl
	inc edi
plus:
	push dx
	inc esi
	test eax, eax
	jz fin
	cdq
	idiv ebx
	jmp plus
fin:
	mov ecx, esi
write:
	pop bx
	add bl,'0'
	mov [edi],bl
	inc edi
	loop write

	ret
int_to_char ENDP
;////////////////////////////////////////////////////////////////////

end main