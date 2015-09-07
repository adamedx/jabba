	.data
___endline:	.asciiz	"\n"
	.text
	.data
L0:	.asciiz	" withing the call, x = "
	.text
F:	
	la $a0,L0
	li $v0,4
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
# // Line Number 10 
# // Line Number 20 
	.data
L1:	.asciiz	" before the call, i = "
	.text
	.data
L2:	.asciiz	" after the call, i = "
	.text
main:	
	la $a0,L1
	li $v0,4
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	la $a0,L2
	li $v0,4
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
