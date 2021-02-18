			section .text
			global _ft_strcmp

_ft_strcmp:
			push	rbp
			mov		rax, 0

compare:
			cmp		byte[rsi + rax], 0
			je		zero
			cmp		byte[rdi + rax], 0
			je		zero
			mov		cl, byte[rsi + rax]
			cmp		cl, byte[rdi + rax]
			jne		zero
			inc		rax
			jmp		compare

zero:
			mov		cl, byte[rsi + rax]
			cmp		cl, byte[rdi + rax]
			jz		equal
			jg		low 
			jl		high

equal:
			mov		rax,0
			pop		rbp
			ret

high:
			mov		rax, 1
			pop		rbp
			ret

low:
			mov		rax, -1
			pop		rbp
			ret
