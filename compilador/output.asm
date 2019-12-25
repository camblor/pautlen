segment .data 
	err_div0 db "Error al dividir entre 0"
	err_index db "Indice de vector fuera de rango"
segment .bss 
	__esp resd 1
	_resultado resd 1
	_vector resd 1
;D:	function
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
;R27:	<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>
;R27:	<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>
;R27:	<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>
;R25:	<resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
	_or:
	push ebp
	mov ebp, esp
	sub esp, 4
;D:	=
;D:	||
	lea eax, [ebp+16]
	push dword eax
;D:	||
	lea eax, [ebp+12]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	or eax, ebx
	push dword eax
	lea eax, [ebp+8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	or eax, ebx
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-4]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
;D:	return
	lea eax, [ebp-4]
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
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;D:	=
;D:	false
	push dword 0
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;D:	=
;D:	true
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 2
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;D:	=
;D:	false
	push dword 0
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov [eax], ebx
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;D:	=
	push dword 0
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
	push dword 2
;R81:	<exp> ::= <constante>
	pop dword eax
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 2
	jg  fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx+eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _or
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	pop dword eax
	mov [_resultado], eax 
	push dword _resultado
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_boolean
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
