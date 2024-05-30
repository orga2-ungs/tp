%include "io.inc"

section .data
    N1 db 5
    N2 db 3

section .bss
    op resb 1
    res_sum resb 1
    res_mul resb 1
    res_div resb 1

section .text

limpiar_registros:
    ; limpia los registros para ser utilizados
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    
suma:
    ; suma los dos operandos
    ; parametros: 
    ;   1. EAX - primer operando
    ;   2. EBX - segundo operando
    add eax, ebx
    mov [res_sum], eax
    ret
    
resta:
    ; resta los dos operandos
    ; parametros: 
    ;   1. EAX - primer operando
    ;   2. EBX - segundo operando
    sub eax, ebx
    mov [res_sum], eax
    ret

multip:
    ; multiplica los dos operandos
    ; parametros: 
    ;   1. EAX - primer operando
    ;   2. EBX - segundo operando
    mul ebx
    mov [res_mul], ebx
    ret

division:
    ; divide los dos operandos
    ; parametros: 
    ;   1. EAX - dividendo
    ;   2. EBX - divisor
    div ebx
    mov [res_div], ebx
    ret
    

global CMAIN
CMAIN:
    mov ebp, esp
    
    call limpiar_registros
    
    ; operacion
    mov al, [N1]    ; parte baja de EAX
    mov bl, [N2]    ; parte baja de EBX
    call division
    
    ret