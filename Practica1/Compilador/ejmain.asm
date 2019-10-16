segment .data 
	err_div0 db "Error al dividir entre 0"
segment .bss 
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
	_b1 resd 1
	_j resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
	push dword _x
	call scan_int
	add esp, 4
	push dword _z
	call scan_int
	add esp, 4
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
	push dword _x
;--------Escrito Operando--------
	pop dword eax
	mov dword eax, [eax]
	imul eax, -1
	push eax
	pop dword eax
	mov [_j], eax 
;--------Escribir Operando--------
	push dword _j
;--------Escrito Operando--------
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;--------Escribir Operando--------
	push dword _x
;--------Escrito Operando--------
;--------Escribir Operando--------
	push dword _z
;--------Escrito Operando--------
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;--------Escribir Operando--------
	push dword _z
;--------Escrito Operando--------
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
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