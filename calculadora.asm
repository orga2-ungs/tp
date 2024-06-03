;uncomment for correct debugging
;%include "io.inc"

section .bss
    error_code resd 1

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
    ret
    
resta:
    ; resta los dos operandos
    ; parametros: 
    ;   1. EAX - primer operando
    ;   2. EBX - segundo operando
    cmp ebx, eax
    jg error_resta
    sub eax, ebx
    ret

multip:
    ; multiplica los dos operandos
    ; parametros: 
    ;   1. EAX - primer operando
    ;   2. EBX - segundo operando
    mul ebx
    ret

division:
    ; divide los dos operandos
    ; parametros: 
    ;   1. EAX - dividendo
    ;   2. EBX - divisor
    xor edx, edx 
    div ebx
    test edx, edx
    jnz error_non_int_div
    ret

error_resta:
    ; resultado de resta negativo
    mov dword [error_code], 4
    ret

error_div_cero:
    mov dword [error_code], 1
    ret

error_non_int_div:
    mov dword [error_code], 3 
    ret 

global recibir_operacion  
recibir_operacion:
    ; realiza una operacion
    ; puede ser suma, resta
    ; multiplicación o división
    ; parametros:
    ;   1. ESP - array de parametros,
    ;    en el que esta el primer
    ;    operando, el operador y el
    ;    segundo operando
    
    call limpiar_registros
    mov eax, [esp+4]
    mov edx, [esp+8]
    mov ebx, [esp+12]
    mov dword [error_code], 0
    
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

    ; operacion no valida
    mov dword [error_code], 2
    ret

global obtener_codigo_error
obtener_codigo_error:
   ; devuelve codigo de error
   ; 1 - division por cero
   ; 2 - operacion no valida
   ; 3 - resultado de division no entero
   mov eax, [error_code]
   ret
