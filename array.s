# Starting Code Generation 

      .globl main

      .data

endl: .asciiz "\n" 

      .text 


 
__movetop:    # A routine to move BIG things 
    lw      $a3,0($a1)
    sw      $a3,0($a0)
    addi    $a0,$a0,-4 
    addi    $a1,$a1,-4 
    addi    $a2,$a2,-4 
__move:
    bgtz    $a2,__movetop 
    jr      $ra 
 
# ------------------------- start of function main
main:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// ARRAY.ds
#	// Some type definitions, and then
#	// Some array calculations
#	// Line Number 10 
#	// Notice that this also uses GLOBAL variables
#	// Line Number 20 
#	// Assignments to scalars

    li      $t0,5 
    sw      $t0,-40($fp)
    li      $t0,1 
    sw      $t0,-44($fp)
    li      $t0,3 
    sw      $t0,-48($fp)

#	// Assignments to X
#	// Line Number 30 

    li      $t0,2 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    li      $t1,17 
    sw      $t1,-52($t0)
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    add     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    li      $t1,23 
    sw      $t1,-52($t0)
      .data
_s0:     .asciiz " The value of X[ 2 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    li      $t0,2 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    lw      $t1,-52($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s1:     .asciiz " -- should be 17 " 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s2:     .asciiz " The value of X[ j+j ] is " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    lw      $t0,-44($fp)
    lw      $t1,-44($fp)
    add     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    lw      $t1,-52($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s3:     .asciiz " -- should be 17" 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s4:     .asciiz " The value of X[ 6 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s4 
    syscall 
    li      $t0,6 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    lw      $t1,-52($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s5:     .asciiz " -- should be 23" 
      .text
    li      $v0,4 
    la      $a0,_s5 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s6:     .asciiz " The value of X[ i+j ] is " 
      .text
    li      $v0,4 
    la      $a0,_s6 
    syscall 
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    add     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    lw      $t1,-52($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s7:     .asciiz " -- should be 23 " 
      .text
    li      $v0,4 
    la      $a0,_s7 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 40 
#	// Assignments to Y

    li      $t0,2 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,2 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    li      $t1,29 
    sw      $t1,-92($t0)
      .data
_s8:     .asciiz " The value of Y[ 2 ][ 2 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s8 
    syscall 
    li      $t0,2 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,2 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-92($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s9:     .asciiz " -- should be 29" 
      .text
    li      $v0,4 
    la      $a0,_s9 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s10:     .asciiz " The value of Y[j+j][j+j] is " 
      .text
    li      $v0,4 
    la      $a0,_s10 
    syscall 
    lw      $t0,-44($fp)
    lw      $t1,-44($fp)
    add     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    lw      $t1,-44($fp)
    lw      $t2,-44($fp)
    add     $t1,$t1,$t2 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-92($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s11:     .asciiz " -- should be 29" 
      .text
    li      $v0,4 
    la      $a0,_s11 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    lw      $t0,-48($fp)
    lw      $t1,-48($fp)
    mul     $t0,$t0,$t1 
    lw      $t1,-44($fp)
    sub     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    lw      $t2,-40($fp)
    lw      $t3,-44($fp)
    mul     $t2,$t2,$t3 
    addi    $t2,$t2,-1 
    sll     $t2,$t2,2 
    add     $t0,$t0,$t2 
    sub     $t0,$fp,$t0 
    li      $t2,31 
    sw      $t2,-92($t0)
      .data
_s12:     .asciiz " The value of Y[ 8 ][ 5 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s12 
    syscall 
    li      $t0,8 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,5 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-92($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s13:     .asciiz " -- should be 31 " 
      .text
    li      $v0,4 
    la      $a0,_s13 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 50 

      .data
_s14:     .asciiz " The value of Y[ k*i-i-2 ][ i + k - 2 * j - 1 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s14 
    syscall 
    lw      $t0,-48($fp)
    lw      $t1,-40($fp)
    mul     $t0,$t0,$t1 
    lw      $t1,-40($fp)
    sub     $t0,$t0,$t1 
    addi    $t0,$t0,-2 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    lw      $t2,-40($fp)
    lw      $t3,-48($fp)
    add     $t2,$t2,$t3 
    lw      $t3,-44($fp)
    mul     $t3,$t3,2 
    sub     $t2,$t2,$t3 
    addi    $t2,$t2,-1 
    addi    $t2,$t2,-1 
    sll     $t2,$t2,2 
    add     $t0,$t0,$t2 
    sub     $t0,$fp,$t0 
    lw      $t2,-92($t0)
    li      $v0,1 
    move    $a0,$t2 
    syscall 
      .data
_s15:     .asciiz " -- should be 31 " 
      .text
    li      $v0,4 
    la      $a0,_s15 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Reference GLOBAL variables

    li      $t0,2 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$gp,$t0 
    li      $t1,17 
    sw      $t1,0($t0)
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    add     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$gp,$t0 
    li      $t1,23 
    sw      $t1,0($t0)
      .data
_s16:     .asciiz " The value of gX[ 2 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s16 
    syscall 
    li      $t0,2 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$gp,$t0 
    lw      $t1,0($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s17:     .asciiz " -- should be 17 " 
      .text
    li      $v0,4 
    la      $a0,_s17 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s18:     .asciiz " The value of gX[ 6 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s18 
    syscall 
    li      $t0,6 
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$gp,$t0 
    lw      $t1,0($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s19:     .asciiz " -- should be 23 " 
      .text
    li      $v0,4 
    la      $a0,_s19 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 60 

    li      $t0,2 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,2 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$gp,$t0 
    li      $t1,29 
    sw      $t1,-40($t0)
    lw      $t0,-48($fp)
    lw      $t1,-48($fp)
    mul     $t0,$t0,$t1 
    lw      $t1,-44($fp)
    sub     $t0,$t0,$t1 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    lw      $t2,-40($fp)
    lw      $t3,-44($fp)
    mul     $t2,$t2,$t3 
    addi    $t2,$t2,-1 
    sll     $t2,$t2,2 
    add     $t0,$t0,$t2 
    sub     $t0,$gp,$t0 
    li      $t2,31 
    sw      $t2,-40($t0)
      .data
_s20:     .asciiz " The value of gY[ 2 ][ 2 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s20 
    syscall 
    li      $t0,2 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,2 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$gp,$t0 
    lw      $t1,-40($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s21:     .asciiz " -- should be 29" 
      .text
    li      $v0,4 
    la      $a0,_s21 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s22:     .asciiz " The value of gY[ 8 ][ 5 ] is " 
      .text
    li      $v0,4 
    la      $a0,_s22 
    syscall 
    li      $t0,8 
    addi    $t0,$t0,-1 
    mul     $t0,$t0,40 
    li      $t1,5 
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$gp,$t0 
    lw      $t1,-40($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s23:     .asciiz " -- should be 31" 
      .text
    li      $v0,4 
    la      $a0,_s23 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function main


# Code Generation Completed 
