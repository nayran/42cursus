			section .text
			global _ft_strcpy

_ft_strcpy:
			push	rbp
			mov		rax, 0					;src = rsi && dest = rdi

compare:
			cmp		byte[rsi + rax], 0		;src[rax] == 0
			je		return					;if(1) return
			mov		cl, byte[rsi + rax]
			mov		byte[rdi + rax], cl		;dest[rax] = src[rax]
			inc		rax						;rax++
			jmp		compare					;goto compare

return:
			mov		byte[rdi + rax], 0		;dest[rax] = 0
			mov		rax, rdi				;return dest
			pop		rbp
			ret
