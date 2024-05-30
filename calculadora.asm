%include "io.inc"

section .data
    N1 db 5
    N2 db 3

section .bss

    op resb 1
    res_mul resb 1

section .text

limpieza:
    ; limpia los registros para ser utilizados
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx

multip:
    ; multiplica dos numeros
    ; parametros: 
    ;   1. EAX - primer numero
    ;   2. EBX - segundo numero
    mul ebx
    mov [res_mul], ebx
    
    ret
    

global CMAIN
CMAIN:
    mov ebp, esp
    
    call limpieza
    
    ; multiplicacion
    mov al, [N1]    ; parte baja de EAX
    mov bl, [N2]    ; parte baja de EBX
    call multip
    
    ret