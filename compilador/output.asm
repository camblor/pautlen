segment .data 
	err_div0 db "Error al dividir entre 0", 0
	err_index db "Indice de vector fuera de rango", 0
segment .bss 
	__esp resd 1
	_x resd 1
	_resultado resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
	_fibonacci:
	push ebp
	mov ebp, esp
	sub esp, 8
	lea eax, [ebp+8]
	push dword eax
	push dword 0
;R81:	<exp> ::= <constante>
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	je igual0
	push dword 0
	jmp fin_igual0
igual0:
	push dword 1
fin_igual0:
	pop eax
	cmp eax, 0
	je near fin_then1
	push dword 0
;R81:	<exp> ::= <constante>
	pop dword eax
	mov dword esp, ebp
	pop dword ebp 
	ret
	jmp near fin_ifelse1
fin_then1:
fin_ifelse1:
;R50:	<condicional> ::= if (<exp>) {<sentencias>}
;R40:	<bloque> ::= <condicional>
	lea eax, [ebp+8]
	push dword eax
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	je igual2
	push dword 0
	jmp fin_igual2
igual2:
	push dword 1
fin_igual2:
	pop eax
	cmp eax, 0
	je near fin_then3
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword eax
	mov dword esp, ebp
	pop dword ebp 
	ret
	jmp near fin_ifelse3
fin_then3:
fin_ifelse3:
;R50:	<condicional> ::= if (<exp>) {<sentencias>}
;R40:	<bloque> ::= <condicional>
	lea eax, [ebp+8]
	push dword eax
	push dword 1
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _fibonacci
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-4]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
	lea eax, [ebp+8]
	push dword eax
	push dword 2
;R81:	<exp> ::= <constante>
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _fibonacci
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	lea eax, [ebp-8]
	push dword eax
; Cargar en eax la parte derecha de la asignación y en ebx la izquierda
	pop dword ebx
	pop dword eax
; Hacer la asignación efectiva
	mov dword [ebx] , eax
	lea eax, [ebp-4]
	push dword eax
	lea eax, [ebp-8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword esp, ebp
	pop dword ebp 
	ret
;R22:	<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}
main:
	mov dword [__esp] , esp
	push dword _x
	call scan_int
	add esp, 4
	push dword _x
	pop dword eax
	mov eax, [eax]
	push dword eax
;R88:	<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)
	call _fibonacci
	push dword eax
;R43:	<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>
	pop dword eax
	mov [_resultado], eax 
	push dword _resultado
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
