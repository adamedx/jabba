	.globl	main
	.text

main:	
#
#	println("Hello, world");
#
	li	$v0,4			# system call code for PRINT_STR
	la	$a0,hello		# get address of string to print
	syscall				# print string
	.data
hello:	.asciiz "Hello, world"
endl:	.asciiz "\n"
	.text
	li	$v0,4			# system call code for PRINT_STR
	la	$a0,endl		# get address of NEWLINE string
	syscall				# print string
#
#	finally, RETURN
#
	jr	$ra			# return 

