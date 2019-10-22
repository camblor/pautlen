segment .data 
	err_div0 db "Error al dividir entre 0"
segment .bss 
	__esp resd 1
	_m resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
;--------Escribir Operando--------0:0
	push dword 0
	pop dword eax
	mov [_m], eax 
;--------Escribir Operando--------m:1
	push dword _m
;--------Escribir Operando--------5:0
	push dword 5
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg mayor1
	push dword 0
	jmp fin_mayor1
mayor1:
	push dword 1
fin_mayor1:
	pop eax
	cmp eax, 0
	je near fin_then1
;--------Escribir Operando--------2:0
	push dword 2
	call print_int
	add esp, 4
	call print_endofline
	jmp near fin_ifelse1
fin_then1:
;--------Escribir Operando--------3:0
	push dword 3
	call print_int
	add esp, 4
	call print_endofline
fin_ifelse1:
	jmp fin
division_cero:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
fin:
	mov dword esp, [__esp]
	ret
