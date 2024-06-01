;uncomment for correct debugging
;%include "io.inc"

section .data
    N1 db 5
    N2 db 3

section .bss
    op resb 1
    res_sum resb 1  ;esto se puede reducir a un registro para todo
    res_rest resb 1
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
    mov [res_rest], eax
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

error_div_cero:
    ; error generado por intento
    ; de dividir por cero
    mov eax, 1
    xor ebx, ebx
    int 0x80

global recibir_operacion  
recibir_operacion:
    ; realiza una operacion
    ; puede ser suma, resta
    ; multiplicación o división
    ; parametros:
    ;   1. EAX - primer operando
    ;   2. EDX - operacion
    ;   3. EBX - segundo operando
    
    call limpiar_registros
    mov eax, [esp+4]
    mov edx, [esp+8]
    mov ebx, [esp+12]
    
    cmp edx, '+'
    je suma
    
    cmp edx, '-'
    je resta
    
    cmp edx, '*'
    je multip
    
    cmp ebx, 0
    je error_div_cero
    
    cmp edx, '/'
    je division ; excepcion de coma flotante

    ret