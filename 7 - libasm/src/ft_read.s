			section .text
			global _ft_read

_ft_read:
			mov		rax, 0x2000003		; mac read = 0x2000003 linux = 0
			syscall
			ret
