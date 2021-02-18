			section .text
			global _ft_strdup
			extern _malloc
			extern _ft_strlen
			extern _ft_strcpy

_ft_strdup:
			call	_ft_strlen
			cmp		rax, 0		;strlen > 0
			inc		rax			;strlen + 1 '\0'
			push	rdi
			mov		rdi, rax
			call	_malloc		
			cmp		rax, 0
			je		error
			pop		rdi
			mov		rsi, rdi
			mov		rdi, rax
			call	_ft_strcpy
			ret

error:
			xor		rax, rax		;return null
