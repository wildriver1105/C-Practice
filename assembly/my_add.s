	.text
	.globl	_my_add
	.p2align	2
_my_add:
	.cfi_startproc
	add	w0, w0, w1
	ret
	.cfi_endproc
