segment .data 
	err_div0 db "Error al dividir entre 0"
segment .bss 
	__esp resd 1
	_b1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
	push dword _b1
	call scan_boolean
	add esp, 4
;--------Escribir Operando--------
	push dword _b1
;--------Escrito Operando--------
;--------NOT--------
	pop dword eax
	cmp dword [eax], 0
	je no_es0_0
	cmp dword [eax], 1
	je no_es1_0
	jmp no_fin_0
	no_es0_0:
	push dword 1
	jmp no_fin_0
	no_es1_0:
	push dword 0
	no_fin_0:
	call print_boolean
	add esp, 4
	call print_endofline
;--------Escribir Operando--------
	push dword _b1
;--------Escrito Operando--------
;--------NOT--------
	pop dword eax
	cmp dword [eax], 0
	je no_es0_1
	cmp dword [eax], 1
	je no_es1_1
	jmp no_fin_1
	no_es0_1:
	push dword 1
	jmp no_fin_1
	no_es1_1:
	push dword 0
	no_fin_1:
;--------NOT--------
	pop dword eax
	cmp dword eax, 0
	je no_es0_2
	cmp dword eax, 1
	je no_es1_2
	jmp no_fin_2
	no_es0_2:
	push dword 1
	jmp no_fin_2
	no_es1_2:
	push dword 0
	no_fin_2:
	call print_boolean
	add esp, 4
	call print_endofline
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
