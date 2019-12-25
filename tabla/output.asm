segment .data 
	err_div0 db "Error al dividir entre 0"
	err_index db "Indice de vector fuera de rango"
segment .bss 
	__esp resd 1
	_x resd 1
	_A resd 1
;D:	function
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
;R27:	<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>
;R26:	<resto_parametros_funcion> ::= 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	return
;R29:	<declaraciones_funcion> ::= 
	_fib:
	push ebp
	mov ebp, esp
	sub esp, 0
	lea eax, [ebp+8]
	push dword eax
	pop dword eax
	mov eax, [eax]
	mov dword esp, ebp
	pop dword ebp 
	ret
;R22:	<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}
main:
	mov dword [__esp] , esp
	push dword 0
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
	push dword 80
;R81:	<exp> ::= <constante>
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _fib
	push dword eax
	pop dword ebx
	pop dword eax
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 1
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
	push dword 20
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;D:	=
	push dword 100
;R81:	<exp> ::= <constante>
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
;HOLA
	pop dword eax
	mov [_x], eax 
	push dword 0
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
;D:	+
	push dword 1
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
;D:	+
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax
;D:	+
;XD
	push dword _x
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax
	push dword 6
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	add eax, ebx
	push dword eax
;R56:	<escritura> ::= printf <exp>
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
