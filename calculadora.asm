section .bss
    error_code resd 1

section .text

limpiar_registros:
    ; limpia los registros para ser utilizados
    pxor mm0, mm0
    pxor mm1, mm1
    jmp end_operation

suma:
    ; suma los dos operandos
    paddd mm0, mm1
    jmp end_operation
    
resta:
    ; resta los dos operandos
    psubd mm0, mm1
    jmp end_operation

multip:
    ; multiplica los dos operandos
    pmuludq mm0, mm1
    jmp end_operation

division:
    ; divide los dos operandos
    movd eax, mm0
    movd ebx, mm1 
    test ebx, ebx
    jz error_div_cero
    xor edx, edx
    idiv ebx

    movd mm0, eax
    test edx, edx
    jnz error_non_int_div
    jmp end_operation

error_div_cero:
    mov dword [error_code], 1
    jmp end_operation

error_non_int_div:
    mov dword [error_code], 3 
    jmp end_operation

end_operation:
    ; despues de una operacion con MMX, 
    ; la instruccion emms asegura una correcta limpieza de los registros FPU
    emms
    ret

global recibir_operacion  
recibir_operacion:
    ; realiza una operacion
    ; puede ser suma, resta
    ; multiplicación o división
    ; parametros:
    ;   1. ESP - array de parametros,
    ;    ESP es el stack pointer
    ;    [ESP] apunta al top stack
    ;    en el que esta el primer
    ;    operando, el operador y el
    ;    segundo operando
    
    call limpiar_registros
    movd mm0, [esp+4]
    mov edx, [esp+8]
    movd mm1, [esp+12]
    mov dword [error_code], 0 ; inicio error code en 0
    
    cmp edx, '+'
    je suma
    
    cmp edx, '-'
    je resta
    
    cmp edx, '*'
    je multip
    
    cmp edx, '/'
    je division

    ; Operacion invalida
    mov dword [error_code], 2
    ret

global obtener_codigo_error
obtener_codigo_error:
   mov eax, [error_code]
   ret
