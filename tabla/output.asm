segment .data 
	err_div0 db "Error al dividir entre 0"
	err_index db "Indice de vector fuera de rango"
segment .bss 
	__esp resd 1
	_x1 resd 1
	_x2 resd 1
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
	_fib:
	push ebp
	mov ebp, esp
	sub esp, 12
;D:	=
	push dword 120
;herewegoagain
;R81:	<exp> ::= <constante>
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-4]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
;D:	=
	push dword 400
;herewegoagain
;R81:	<exp> ::= <constante>
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-8]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
;D:	=
;D:	true
	push dword 1
;R81:	<exp> ::= <constante>
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-12]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
;TOCAVENIR
	lea eax, [ebp-4]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;TOCAVENIR
	lea eax, [ebp-8]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;TOCAVENIR
	lea eax, [ebp-12]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
;TOCAVENIR
	lea eax, [ebp+16]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;TOCAVENIR
	lea eax, [ebp+12]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;TOCAVENIR
	lea eax, [ebp+8]
	push dword eax
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
;D:	return
;TOCAVENIR
	lea eax, [ebp+12]
	push dword eax
	pop dword eax
	mov eax, [eax]
	mov dword esp, ebp
	pop dword ebp 
	ret
;R22:	<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}
main:
	mov dword [__esp] , esp
;D:	=
	push dword 3
;herewegoagain
;R81:	<exp> ::= <constante>
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
;HOLA
	pop dword eax
	mov [_x2], eax 
;D:	=
	push dword 4
;herewegoagain
;R81:	<exp> ::= <constante>
	push dword 80
;herewegoagain
;R81:	<exp> ::= <constante>
;D:	true
	push dword 1
;R81:	<exp> ::= <constante>
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _fib
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
;HOLA
	pop dword eax
	mov [_x1], eax 
;XD
	push dword _x1
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
