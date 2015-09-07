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
# //////////////////////////////////////////
# // sierpinski gasket
# // first, define our matrix
# // Line Number 10 
# // Line Number 20 
# // Program input:
MatrixGet:	
	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $t0,-12800
	li $t1,4
	li $t2,12
	add $t2,$t2,$fp
	lw $t2,0($t2)
	li $t3,80
	mult $t2,$t3
	mflo $t2
	li $t4,8
	add $t4,$t4,$fp
	lw $t4,0($t4)
	add $t2,$t2,$t4
	mult $t1,$t2
	mflo $t1
	sub $t0,$t0,$t1
	add $t0,$t0,$gp
	lw $t0,0($t0)
	li $t5,4
	add $t5,$t5,$fp
	sw $t0,0($t5)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
MatrixSet:	# // Line Number 30 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $t6,1
	li $t7,-12800
	li $s0,4
	li $s1,8
	add $s1,$s1,$fp
	lw $s1,0($s1)
	li $s2,80
	mult $s1,$s2
	mflo $s1
	li $s3,4
	add $s3,$s3,$fp
	lw $s3,0($s3)
	add $s1,$s1,$s3
	mult $s0,$s1
	mflo $s0
	sub $t7,$t7,$s0
	add $t7,$t7,$gp
	sw $t6,0($t7)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
MatrixReset:	
	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $s4,0
	li $s5,-12800
	li $s6,4
	li $s7,8
	add $s7,$s7,$fp
	lw $s7,0($s7)
	li $t0,80
	mult $s7,$t0
	mflo $s7
	li $t1,4
	add $t1,$t1,$fp
	lw $t1,0($t1)
	add $s7,$s7,$t1
	mult $s6,$s7
	mflo $s6
	sub $s5,$s5,$s6
	add $s5,$s5,$gp
	sw $s4,0($s5)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
# ////////////////////////////////////////
# // Line Number 40 
# // rnd
# // generates a "random" number between
# // 0 and maxint (2^31 - 1) given any
# // such number
# // seed for random generator
# // Line Number 50 
randmult:	# // Line Number 60 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $t2,12
	add $t2,$t2,$fp
	lw $t2,0($t2)
	li $t3,-25644
	add $t3,$t3,$gp
	lw $t3,0($t3)
	div $t2,$t3
	mflo $t2
	li $t4,-40
	add $t4,$t4,$fp
	sw $t2,0($t4)
	li $t5,12
	add $t5,$t5,$fp
	lw $t5,0($t5)
	li $t6,-25644
	add $t6,$t6,$gp
	lw $t6,0($t6)
	rem $t5,$t5,$t6
	li $t7,-44
	add $t7,$t7,$fp
	sw $t5,0($t7)
	li $s0,8
	add $s0,$s0,$fp
	lw $s0,0($s0)
	li $s1,-25644
	add $s1,$s1,$gp
	lw $s1,0($s1)
	div $s0,$s1
	mflo $s0
	li $s2,-48
	add $s2,$s2,$fp
	sw $s0,0($s2)
	li $s3,8
	add $s3,$s3,$fp
	lw $s3,0($s3)
	li $s4,-25644
	add $s4,$s4,$gp
	lw $s4,0($s4)
	rem $s3,$s3,$s4
	li $s5,-52
	add $s5,$s5,$fp
	sw $s3,0($s5)
	li $s6,-44
	add $s6,$s6,$fp
	lw $s6,0($s6)
	li $s7,-48
	add $s7,$s7,$fp
	lw $s7,0($s7)
	mult $s6,$s7
	mflo $s6
	li $t0,-40
	add $t0,$t0,$fp
	lw $t0,0($t0)
	li $t1,-52
	add $t1,$t1,$fp
	lw $t1,0($t1)
	mult $t0,$t1
	mflo $t0
	add $s6,$s6,$t0
	li $t2,-25644
	add $t2,$t2,$gp
	lw $t2,0($t2)
	rem $s6,$s6,$t2
	li $t3,-25644
	add $t3,$t3,$gp
	lw $t3,0($t3)
	mult $s6,$t3
	mflo $s6
	li $t4,-44
	add $t4,$t4,$fp
	lw $t4,0($t4)
	li $t5,-52
	add $t5,$t5,$fp
	lw $t5,0($t5)
	mult $t4,$t5
	mflo $t4
	add $s6,$s6,$t4
	li $t6,-25640
	add $t6,$t6,$gp
	lw $t6,0($t6)
	rem $s6,$s6,$t6
	li $t7,4
	add $t7,$t7,$fp
	sw $s6,0($t7)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
rnd:	
	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $s0,31415821
	li $s1,-40
	add $s1,$s1,$fp
	sw $s0,0($s1)
	li $s2,-25612
	add $s2,$s2,$gp
	lw $s2,0($s2)
	li $s3,-44
	add $s3,$s3,$fp
	sw $s2,0($s3)
	li $s4,-40
	add $s4,$s4,$fp
	lw $s4,0($s4)
	li $s5,-48
	add $s5,$s5,$fp
	sw $s4,0($s5)
	la $sp,-56($fp)
	jal randmult
	li $s6,-52
	add $s6,$s6,$fp
	lw $s6,0($s6)
	li $s7,1
	add $s6,$s6,$s7
	li $t0,-25640
	add $t0,$t0,$gp
	lw $t0,0($t0)
	rem $s6,$s6,$t0
	li $t1,-25612
	add $t1,$t1,$gp
	sw $s6,0($t1)
	li $t2,-25612
	add $t2,$t2,$gp
	lw $t2,0($t2)
	li $t3,-25644
	add $t3,$t3,$gp
	lw $t3,0($t3)
	div $t2,$t3
	mflo $t2
	li $t4,8
	add $t4,$t4,$fp
	lw $t4,0($t4)
	mult $t2,$t4
	mflo $t2
	li $t5,-25644
	add $t5,$t5,$gp
	lw $t5,0($t5)
	div $t2,$t5
	mflo $t2
	li $t6,4
	add $t6,$t6,$fp
	sw $t2,0($t6)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
# // Line Number 70 
# ////////////////////////////////////////////////
# // initmatrix
# // clears the matrix, which is our "screen"
# // for this program
initmatrix:	# // Line Number 80 
# // Line Number 90 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $t7,0
	li $s0,-40
	add $s0,$s0,$fp
	sw $t7,0($s0)
L2:
	li $s1,-40
	add $s1,$s1,$fp
	lw $s1,0($s1)
	li $s2,40
	slt $s1,$s1,$s2
	beqz $s1,L3
	li $s3,0
	li $s4,-44
	add $s4,$s4,$fp
	sw $s3,0($s4)
L0:
	li $s5,-44
	add $s5,$s5,$fp
	lw $s5,0($s5)
	li $s6,80
	slt $s5,$s5,$s6
	beqz $s5,L1
	li $s7,-40
	add $s7,$s7,$fp
	lw $s7,0($s7)
	li $t0,-48
	add $t0,$t0,$fp
	sw $s7,0($t0)
	li $t1,-44
	add $t1,$t1,$fp
	lw $t1,0($t1)
	li $t2,-52
	add $t2,$t2,$fp
	sw $t1,0($t2)
	la $sp,-56($fp)
	jal MatrixReset
	li $t3,-44
	add $t3,$t3,$fp
	lw $t3,0($t3)
	li $t4,1
	add $t3,$t3,$t4
	li $t5,-44
	add $t5,$t5,$fp
	sw $t3,0($t5)
	j L0
L1:
	li $t6,-40
	add $t6,$t6,$fp
	lw $t6,0($t6)
	li $t7,1
	add $t6,$t6,$t7
	li $s0,-40
	add $s0,$s0,$fp
	sw $t6,0($s0)
	j L2
L3:
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
# /////////////////////////////////////////////
# // GetInput()
# // normally, you would ask the user for this,
# // but we haven't implemented input (yet).
# // Line Number 100 
GetInput:	# // Line Number 110 
# // Line Number 120 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $s1,0
	li $s2,-25616
	li $s3,8
	li $s4,0
	mult $s3,$s4
	mflo $s3
	sub $s2,$s2,$s3
	add $s2,$s2,$gp
	sw $s1,0($s2)
	li $s5,39
	li $s6,-25620
	li $s7,8
	li $t0,0
	mult $s7,$t0
	mflo $s7
	sub $s6,$s6,$s7
	add $s6,$s6,$gp
	sw $s5,0($s6)
	li $t1,39
	li $t2,-25616
	li $t3,8
	li $t4,1
	mult $t3,$t4
	mflo $t3
	sub $t2,$t2,$t3
	add $t2,$t2,$gp
	sw $t1,0($t2)
	li $t5,0
	li $t6,-25620
	li $t7,8
	li $s0,1
	mult $t7,$s0
	mflo $t7
	sub $t6,$t6,$t7
	add $t6,$t6,$gp
	sw $t5,0($t6)
	li $s1,79
	li $s2,-25616
	li $s3,8
	li $s4,2
	mult $s3,$s4
	mflo $s3
	sub $s2,$s2,$s3
	add $s2,$s2,$gp
	sw $s1,0($s2)
	li $s5,39
	li $s6,-25620
	li $s7,8
	li $t0,2
	mult $s7,$t0
	mflo $s7
	sub $s6,$s6,$s7
	add $s6,$s6,$gp
	sw $s5,0($s6)
	li $t1,5
	li $t2,-25600
	add $t2,$t2,$gp
	sw $t1,0($t2)
	li $t3,5
	li $t4,-25604
	add $t4,$t4,$gp
	sw $t3,0($t4)
	li $t5,10
	li $t6,-25608
	add $t6,$t6,$gp
	sw $t5,0($t6)
	li $t7,29474
	li $s0,-25612
	add $s0,$s0,$gp
	sw $t7,0($s0)
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
# /////////////////////////////////////////////////////
# // printmatrix()
# // prints out our screen
printmatrix:	# // Line Number 130 
# // Line Number 140 
	.data
L4:	.asciiz	"X"
	.text
	.data
L5:	.asciiz	" "
	.text
	.data
L10:	.asciiz	""
	.text
# // Line Number 150 

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $s1,0
	li $s2,-40
	add $s2,$s2,$fp
	sw $s1,0($s2)
L11:
	li $s3,-40
	add $s3,$s3,$fp
	lw $s3,0($s3)
	li $s4,40
	slt $s3,$s3,$s4
	beqz $s3,L12
	li $s5,0
	li $s6,-44
	add $s6,$s6,$fp
	sw $s5,0($s6)
L8:
	li $s7,-44
	add $s7,$s7,$fp
	lw $s7,0($s7)
	li $t0,80
	slt $s7,$s7,$t0
	beqz $s7,L9
	li $t1,-40
	add $t1,$t1,$fp
	lw $t1,0($t1)
	li $t2,-48
	add $t2,$t2,$fp
	sw $t1,0($t2)
	li $t3,-44
	add $t3,$t3,$fp
	lw $t3,0($t3)
	li $t4,-52
	add $t4,$t4,$fp
	sw $t3,0($t4)
	la $sp,-60($fp)
	jal MatrixGet
	li $t5,-56
	add $t5,$t5,$fp
	lw $t5,0($t5)
	beqz $t5,L6
	la $a0,L4
	li $v0,4
	syscall 
	j L7
L6:
	la $a0,L5
	li $v0,4
	syscall 
L7:
	li $t6,-44
	add $t6,$t6,$fp
	lw $t6,0($t6)
	li $t7,1
	add $t6,$t6,$t7
	li $s0,-44
	add $s0,$s0,$fp
	sw $t6,0($s0)
	j L8
L9:
	la $a0,L10
	li $v0,4
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	li $s1,-40
	add $s1,$s1,$fp
	lw $s1,0($s1)
	li $s2,1
	add $s1,$s1,$s2
	li $s3,-40
	add $s3,$s3,$fp
	sw $s1,0($s3)
	j L11
L12:
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
# ////////////////////////////////////
# // main()
main:	
__start:
	la $a3,0($sp)
# // a triangle whose coords lie in the matrix;
# // Line Number 160 
# // current iteration -- we'll quit to avoid infinite loop
# // our current spot in the matrix
# // index of the vertix we want to move towards...
# // Line Number 170 
# // initialize our "screen"
# // do the sierpinski thang....
# // chooses a vertex of the triangle
# // Line Number 180 
# // these two lines move you halfway to the
# // chosen vertex from the current position
# // Line Number 190 
# // print the matrix;

	sw $fp,0($sp)
	sw $ra,-4($sp)
	move $fp,$sp
	li $s4,0
	li $s5,-64
	add $s5,$s5,$fp
	sw $s4,0($s5)
	li $s6,1000000000
	li $s7,-25640
	add $s7,$s7,$gp
	sw $s6,0($s7)
	li $t0,10000
	li $t1,-25644
	add $t1,$t1,$gp
	sw $t0,0($t1)
	la $sp,-80($fp)
	jal GetInput
	li $t2,-25616
	add $t2,$t2,$gp
	li $t3,-40
	add $t3,$t3,$fp
	la $a1,0($t2)
	la $a0,0($t3)
	li $a2,24
	jal __copy
	la $sp,-80($fp)
	jal initmatrix
L13:
	li $t4,-64
	add $t4,$t4,$fp
	lw $t4,0($t4)
	li $t5,-25608
	add $t5,$t5,$gp
	lw $t5,0($t5)
	slt $t4,$t4,$t5
	beqz $t4,L14
	li $t6,3
	li $t7,-80
	add $t7,$t7,$fp
	sw $t6,0($t7)
	la $sp,-88($fp)
	jal rnd
	li $s0,-84
	add $s0,$s0,$fp
	lw $s0,0($s0)
	li $s1,-76
	add $s1,$s1,$fp
	sw $s0,0($s1)
	li $s2,-76
	add $s2,$s2,$fp
	lw $s2,0($s2)
	li $s3,3
	rem $s2,$s2,$s3
	li $s4,-76
	add $s4,$s4,$fp
	sw $s2,0($s4)
	li $s5,-76
	add $s5,$s5,$fp
	lw $s5,0($s5)
	move $a0,$s5
	li $v0,1
	syscall 
	la $a0,__endline__
	li $v0,4
	syscall 
	li $s6,-68
	add $s6,$s6,$fp
	lw $s6,0($s6)
	li $s7,-40
	li $t0,8
	li $t1,-76
	add $t1,$t1,$fp
	lw $t1,0($t1)
	mult $t0,$t1
	mflo $t0
	sub $s7,$s7,$t0
	add $s7,$s7,$fp
	lw $s7,0($s7)
	li $t2,-68
	add $t2,$t2,$fp
	lw $t2,0($t2)
	sub $s7,$s7,$t2
	li $t3,2
	div $s7,$t3
	mflo $s7
	add $s6,$s6,$s7
	li $t4,-68
	add $t4,$t4,$fp
	sw $s6,0($t4)
	li $t5,-72
	add $t5,$t5,$fp
	lw $t5,0($t5)
	li $t6,-44
	li $t7,8
	li $s0,-76
	add $s0,$s0,$fp
	lw $s0,0($s0)
	mult $t7,$s0
	mflo $t7
	sub $t6,$t6,$t7
	add $t6,$t6,$fp
	lw $t6,0($t6)
	li $s1,-72
	add $s1,$s1,$fp
	lw $s1,0($s1)
	sub $t6,$t6,$s1
	li $s2,2
	div $t6,$s2
	mflo $t6
	add $t5,$t5,$t6
	li $s3,-72
	add $s3,$s3,$fp
	sw $t5,0($s3)
	li $s4,-72
	add $s4,$s4,$fp
	lw $s4,0($s4)
	li $s5,-80
	add $s5,$s5,$fp
	sw $s4,0($s5)
	li $s6,-68
	add $s6,$s6,$fp
	lw $s6,0($s6)
	li $s7,-84
	add $s7,$s7,$fp
	sw $s6,0($s7)
	la $sp,-88($fp)
	jal MatrixSet
	li $t0,-64
	add $t0,$t0,$fp
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	li $t2,-64
	add $t2,$t2,$fp
	sw $t0,0($t2)
	j L13
L14:
	la $sp,-80($fp)
	jal printmatrix
	move $sp,$fp
	lw $ra,-4($sp)
	lw $fp,0($sp)
	jr $ra
