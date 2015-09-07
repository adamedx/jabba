	.data
__endline__:	.asciiz	"\n"
	.text
__copystart:    # routine to copy BIG types
	lw      $a3,0($a1)
	sw      $a3,0($a0)
	addi    $a0,$a0,-4
	addi    $a1,$a1,-4
	addi    $a2,$a2,-4
__copy:
	bgtz    $a2,__copystart
	jr      $ra
main:	
__start:
	la $a3,0($sp)
# // Line Number 10 
	.data
L0:	.asciiz	"Pos: "
	.text
	.data
L1:	.asciiz	"Neg: "
	.text
	.data
L2:	.asciiz	"True: "
	.text
	.data
L3:	.asciiz	"False: "
	.text
# // Line Number 20 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $t0,10
	sw $t0,-40($fp)
	lw $t1,-40($fp)
	neg $t1,$t1
	sw $t1,-44($fp)
	la $a0,L0
	li $v0,4
	syscall 
	lw $t2,-40($fp)
	move $a0,$t2
	li $v0,1
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	la $a0,L1
	li $v0,4
	syscall 
	lw $t3,-44($fp)
	move $a0,$t3
	li $v0,1
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	li $t4,5
	sw $t4,-48($fp)
	lw $t5,-48($fp)
	seq $t5,$t5,$0
	sw $t5,-52($fp)
	la $a0,L2
	li $v0,4
	syscall 
	lw $t6,-48($fp)
	move $a0,$t6
	li $v0,1
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	la $a0,L3
	li $v0,4
	syscall 
	lw $t7,-52($fp)
	move $a0,$t7
	li $v0,1
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
