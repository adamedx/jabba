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
__start:
main:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 10 

    li      $t0,1 
    sw      $t0,-52($fp)
    li      $t0,2 
    sw      $t0,-56($fp)

#	// Line Number 20 

    li      $t0,3 
    sw      $t0,-60($fp)
    la      $a0,-64($fp)
    la      $a1,-52($fp)
    li      $a2,12 
    jal     __move 
      .data
_s0:     .asciiz "thing.second = 2?" 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,-56($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s1:     .asciiz "thing2.second = 2?" 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    lw      $t0,-68($fp)
    li      $v0,1 
    move    $a0,$t0 
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
