			section .text
			global _ft_write

_ft_write:
			mov		rax, 0x2000004		; macwrite = 0x2000004 - linux = 1
			syscall						; call function
			ret
