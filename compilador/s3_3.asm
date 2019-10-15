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
	mov ebp, esp
	sub esp, 4*1
	lea eax, [ebp + 1+8]
	lea eax, [ebp -4*1]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword [ebx], eax;--------Escribir Operando--------2:0
	push dword 2
;--------Escrito Operando--------
	lea eax, [ebp + 1+8]
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	imul ebx
	push dword eax
	pop eax
	mov dword eax, [eax]
	mov esp, ebp
	pop ebp 
ret
_main:
	mov dword [__esp] , esp
;--------Escribir Operando--------2:0
	push dword 2
;--------Escrito Operando--------
	pop dword eax
	mov [_z], eax 
;--------Escribir Operando--------z:1
	push dword _z
;--------Escrito Operando--------
	pop eax
	mov eax, [eax]
	push eax
	call _doble
	add esp, 4*1
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
