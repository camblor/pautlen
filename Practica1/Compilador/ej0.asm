segment .data 
	err_div0 db "Error al dividir entre 0"
segment .bss 
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
;--------Escribir Operando--------8:0
	push dword 8
;--------Escrito Operando--------
	pop dword eax
	mov [_x], eax 
	push dword _y
	call scan_int
	add esp, 4
;--------Escribir Operando--------y:1
	push dword _y
;--------Escrito Operando--------
;--------Escribir Operando--------x:1
	push dword _x
;--------Escrito Operando--------
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax
	pop dword eax
	mov [_z], eax 
;--------Escribir Operando--------z:1
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