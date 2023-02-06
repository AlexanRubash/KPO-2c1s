.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
ExitProcess PROTO : DWORD
.STACK 4096
.CONST
.DATA

Wchar_t0 WORD 0
Int0 SDWORD 50331648


.CODE
main PROC
START :
push - 1
call ExitProcess
main ENDP
end main
