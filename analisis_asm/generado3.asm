segment .data
	_y dd 10
	_o dd 2
segment .bss
	_x resd 1
	__esp resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp


	;scanf x
	push dword _x
	call scan_int
	add esp, 4

	; x = (x * 2 ) -y
	push dword [_x]
	pop dword eax
	mul dword [_o]

	push dword [_y]
	pop dword ebx

	sub eax, ebx

	mov [_x], eax

; IMPRESIÓN DE X
	push dword [_x]
	call print_int
	add esp, 4
	call print_endofline

	mov dword esp, [__esp]
	ret
