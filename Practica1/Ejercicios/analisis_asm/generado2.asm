segment .data

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
	mov dword [_x], 8

; IMPRESIÓN DE TODOS LOS ELEMENTOS
	push dword [_x]
	call print_int
	add esp, 4
	call print_endofline

	mov dword esp, [__esp]
	ret

