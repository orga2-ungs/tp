section .bss
    error_code resd 1

section .data
    one dq 1

section .text

limpiar_registros:
    ; limpia los registros para ser utilizados
    pxor mm0, mm0
    pxor mm1, mm1
    pxor mm2, mm2
    ret

suma:
    ; suma los dos operandos
    paddd mm0, mm1
    jmp finalizar_operacion
    
resta:
    ; resta los dos operandos
    psubd mm0, mm1
    jmp finalizar_operacion

multip:
    ; multiplica los dos operandos
    pmuludq mm0, mm1
    jmp finalizar_operacion

division:
    ; divide los dos operandos
    movd ebx, mm1 ; muevo dividendo a ebx para testear si es 0
    test ebx, ebx
    jz error_div_cero
    xor ebx, ebx
    pxor mm2, mm2 ; limpio mm2 para usarlo como cociente

division_loop:
    psubb mm0, mm1
    paddd mm2, [one]

    movd eax, mm0
    test eax, eax
    jz division_fin

    movd edx, mm1
    cmp eax, edx
    jae division_loop ; dividendo >= divisor

    jmp error_non_int_div ; dividendo < divisor, division no entera

division_fin:
    movq mm0, mm2
    mov dword [error_code], 0
    jmp finalizar_operacion
    
error_div_cero:
    mov dword [error_code], 1
    ret

error_non_int_div:
    mov dword [error_code], 3 
    ret

finalizar_operacion:
    ; despues de una operacion con MMX, 
    ; la instruccion emms asegura una correcta limpieza de los registros FPU
    movd eax, mm0
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
