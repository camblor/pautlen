segment .data 
	err_div0 db "Error al dividir entre 0"
segment .bss 
	__esp resd 1
	_m resd 1
	_v resd 4
segment .text
	global main
	extern scan_int, print_int, scan_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp] , esp
;--------Escribir Operando--------0:0
	push dword 0
	pop dword eax
	mov [_m], eax 
inicio_while1:
;--------Escribir Operando--------m:1
	push dword _m
;--------Escribir Operando--------4:0
	push dword 4
pop dword eax
 pop dword ebx
mov dword ebx, [ebx]
cmp eax, ebx
jle menor_igual
push dword 0
menor_igual:
push dword 1
	pop eax
	cmp eax, 0
	je near fin_while1
;--------Escribir Operando--------m:1
	push dword _m
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;--------Escribir Operando--------m:1
	push dword _m
;--------Escribir Operando--------10:0
	push dword 10
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	imul ebx
	push dword eax
;--------Escribir Operando--------m:1
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl  fin_indice_fuera_rango
	cmp eax, 3
	jg  fin_indice_fuera_rango
	mov dword edx, _v
	lea eax, [edx+eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax;--------Escribir Operando--------m:1
	push dword _m
;--------Escribir Operando--------1:0
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov [_m], eax 
	jmp near inicio_while1
fin_while1:
	jmp fin
division_cero:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
fin_indice_fuera_rango:
	jmp fin
fin:
	mov dword esp, [__esp]
	ret
