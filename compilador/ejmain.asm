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
	cmp eax, 0
	jne to1_1
	mov eax, 1
	jmp notend_1
to1_1:
	mov eax, 0
notend_1:
	push dword eax
;--------NOTEND--------
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
