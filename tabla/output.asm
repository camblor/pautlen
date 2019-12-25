segment .data 
	err_div0 db "Error al dividir entre 0"
	err_index db "Indice de vector fuera de rango"
segment .bss 
	__esp resd 1
	_A resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
	push dword 0
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 1
	jg  fin_indice_fuera_rango
	mov dword edx, _A
	lea eax, [edx+eax*4]
	push dword eax
;D:	=
	push dword 40
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;ASIGNANDO A 1
	push dword 1
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 1
	jg  fin_indice_fuera_rango
	mov dword edx, _A
	lea eax, [edx+eax*4]
	push dword eax
;D:	=
	push dword 30
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;ASIGNANDO A 1
	push dword 0
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 1
	jg  fin_indice_fuera_rango
	mov dword edx, _A
	lea eax, [edx+eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
;R56:	<escritura> ::= printf <exp>
;AESCRIBIR
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword 1
;herewegoagain
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 1
	jg  fin_indice_fuera_rango
	mov dword edx, _A
	lea eax, [edx+eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
;R56:	<escritura> ::= printf <exp>
;AESCRIBIR
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	jmp fin
fin_indice_fuera_rango:
	push dword err_index
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
division_cero:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
fin:
	mov dword esp, [__esp]
	ret
