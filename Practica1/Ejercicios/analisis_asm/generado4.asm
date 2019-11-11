segment .data
	_y dd 10
    _b3 dd 0
segment .bss
	_x resd 1
    _b1 resd 1
    _b2 resd 1
	__esp resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp
	
    ; SCANF B1 Y B2
	push dword _b1
	call scan_boolean
	add esp, 4

    push dword _b2
	call scan_boolean
	add esp, 4

    ;BOOLEAN OPERATION
    push dword [_b1]
	push dword [_b2]
	pop dword eax
	pop dword ebx
	and eax, ebx
    
    ;NOT CON SALTOS
    cmp eax, 0
    jne to1

    mov eax, 1
    jmp end

    to1: mov eax, 0


    ;IMPRESION DE B3
    end:
    push dword eax
    pop dword [_b3]
    push dword [_b3]
	call print_boolean
	add esp, 4
	call print_endofline


; FIN
	mov dword esp, [__esp]
	ret

