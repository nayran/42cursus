				section .text
				global _ft_strlen

_ft_strlen:
				push	rbp						;set function init on stack init
				mov		rax, 0					;rax = 0

increment:
				cmp		byte[rdi + rax], 0		;byte[rdi + x] == 0
				je		return					;	if (cmp == 1)return
				inc		rax						;x++
				jmp		increment				;goto increment

return:
				pop		rbp						;throw back to the init, not
				ret								;interfering on stack
