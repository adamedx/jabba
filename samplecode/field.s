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
 

#	// Line Number 10 

    li      $t0,20 
    sw      $t0,-40($fp)
    li      $t0,4 
    sw      $t0,-44($fp)
    li      $t0,3 
    sw      $t0,-48($fp)

#	// Line Number 20 

    li      $t0,5 
    addi    $t0,$t0,-3 
    mul     $t0,$t0,64 
    li      $t1,7 
    addi    $t1,$t1,-2 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    li      $t1,17 
    sw      $t1,-64($t0)
      .data
_s0:     .asciiz " X[ 5 ].F[ 7 ] = " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    li      $t0,5 
    addi    $t0,$t0,-3 
    mul     $t0,$t0,64 
    li      $t1,7 
    addi    $t1,$t1,-2 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-64($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s1:     .asciiz " -- should be 17" 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    div     $t0,$t0,$t1 
    addi    $t0,$t0,-3 
    mul     $t0,$t0,64 
    lw      $t1,-44($fp)
    lw      $t2,-48($fp)
    add     $t1,$t1,$t2 
    addi    $t1,$t1,-2 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    li      $t1,23 
    sw      $t1,-64($t0)
      .data
_s2:     .asciiz " X[ 5 ].F[ 7 ] = " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    li      $t0,5 
    addi    $t0,$t0,-3 
    mul     $t0,$t0,64 
    li      $t1,7 
    addi    $t1,$t1,-2 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-64($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s3:     .asciiz " -- should be 23 " 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 30 

      .data
_s4:     .asciiz " X[ i / j ].F[ j + k ] = " 
      .text
    li      $v0,4 
    la      $a0,_s4 
    syscall 
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    div     $t0,$t0,$t1 
    addi    $t0,$t0,-3 
    mul     $t0,$t0,64 
    lw      $t1,-44($fp)
    lw      $t2,-48($fp)
    add     $t1,$t1,$t2 
    addi    $t1,$t1,-2 
    sll     $t1,$t1,2 
    add     $t0,$t0,$t1 
    sub     $t0,$fp,$t0 
    lw      $t1,-64($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s5:     .asciiz " -- should be 23 " 
      .text
    li      $v0,4 
    la      $a0,_s5 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s6:     .asciiz " i = " 
      .text
    li      $v0,4 
    la      $a0,_s6 
    syscall 
    lw      $t0,-40($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s7:     .asciiz " j = " 
      .text
    li      $v0,4 
    la      $a0,_s7 
    syscall 
    lw      $t0,-44($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s8:     .asciiz " i/j = " 
      .text
    li      $v0,4 
    la      $a0,_s8 
    syscall 
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    div     $t0,$t0,$t1 
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s9:     .asciiz " -- should be 20:4:5" 
      .text
    li      $v0,4 
    la      $a0,_s9 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s10:     .asciiz " j = " 
      .text
    li      $v0,4 
    la      $a0,_s10 
    syscall 
    lw      $t0,-44($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s11:     .asciiz " k = " 
      .text
    li      $v0,4 
    la      $a0,_s11 
    syscall 
    lw      $t0,-48($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s12:     .asciiz " j+k = " 
      .text
    li      $v0,4 
    la      $a0,_s12 
    syscall 
    lw      $t0,-44($fp)
    lw      $t1,-48($fp)
    add     $t0,$t0,$t1 
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s13:     .asciiz " -- should be 4:3:7" 
      .text
    li      $v0,4 
    la      $a0,_s13 
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
