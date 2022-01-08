	.text
	.globl _prog
_prog:
	push %rbp
	mov %rsp, %rbp
	sub $32, %rsp
	mov $2, %rax
	push %rax
	mov $4, %rax
	push %rax
	mov $3, %rax
	pop %rdi
	imul %rdi, %rax
	pop %rdi
	cqo
	idiv %rdi
	push %rax
	mov $1, %rax
	push %rax
	mov $5, %rax
	pop %rdi
	add %rdi, %rax
	pop %rdi
	sub %rdi, %rax
	mov %rbp, %rsp
	pop %rbp
	ret	