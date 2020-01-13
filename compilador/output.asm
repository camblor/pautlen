segment .data 
	err_div0 db "Error al dividir entre 0", 0
	err_index db "Indice de vector fuera de rango", 0
segment .bss 
	__esp resd 1
	_x resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
	_tre:
	push ebp
	mov ebp, esp
	sub esp, 4
inicio_while0:
	lea eax, [ebp+8]
	push dword eax
	push dword 6
;R81:	<exp> ::= <constante>
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jl menor1
	push dword 0
	jmp fin_menor1
menor1:
	push dword 1
fin_menor1:
	pop eax
	cmp eax, 0
	je near fin_while0
	lea eax, [ebp+8]
	push dword eax
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp+8]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
	jmp near inicio_while0
fin_while0:
;R52:	<bucle> ::= while (<exp>) {<sentencias>}
;R41:	<bloque> ::= <bucle>
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
	push dword 3
;R81:	<exp> ::= <constante>
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _tre
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	pop dword eax
	mov [_x], eax 
	push dword _x
;R56:	<escritura> ::= printf <exp>
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
