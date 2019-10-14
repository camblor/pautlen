segment .data
	err_div0 db "Error al dividir entre 0"
segment .bss
	__esp resd 1
	_z resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
_doble:
push ebp
mov ebp, eps
sub esp, 4
mov dword eax, [ebp+8 +4*0]mov dword [ebp-4*1], eax;
;--------Escribir Operando--------
	push dword _(null);
;--------Escrito Operando--------
mov dword eax, [ebp+8 +4*0]mov esp, ebp;
pop ebp;
ret
main:
	mov dword [__esp] , esp
;--------Escribir Operando--------
	push dword 2
;--------Escrito Operando--------
	pop dword eax
	mov eax, [eax]
	mov [_z], eax
;--------Escribir Operando--------
	push dword _z
;--------Escrito Operando--------
call _doble
add esp, 4
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
