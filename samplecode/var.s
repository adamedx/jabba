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
 
# ------------------------- start of function F
F:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
    lw      $t0,4($fp)
    lw      $t1,0($gp)
    lw      $t2,-4($gp)
    lw      $t3,4($fp)
    lw      $t4,0($t3)
    mul     $t2,$t2,$t4 
    add     $t1,$t1,$t2 
    lw      $t2,8($fp)
    add     $t1,$t1,$t2 
    sw      $t1,0($t0)
      .data
_s0:     .asciiz " within the call, x = " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,4($fp)
    lw      $t1,0($t0)
    li      $v0,1 
    move    $a0,$t1 
    syscall 
      .data
_s1:     .asciiz " -- should be 31" 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function F

# ------------------------- start of function main
main:
__start:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 10 

    li      $t0,2 
    sw      $t0,0($gp)
    li      $t0,3 
    sw      $t0,-4($gp)
    li      $t0,4 
    sw      $t0,-40($fp)

#	// Line Number 20 

      .data
_s2:     .asciiz " before the call, i = " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    lw      $t0,-40($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s3:     .asciiz " -- should be 4" 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    li      $t0,17 
    sw      $t0,-48($fp)
    la      $t0,-40($fp)
    sw      $t0,-52($fp)
    la      $sp,-56($fp)
    jal     F 
      .data
_s4:     .asciiz " after the call, i = " 
      .text
    li      $v0,4 
    la      $a0,_s4 
    syscall 
    lw      $t0,-40($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s5:     .asciiz " -- should be 31 " 
      .text
    li      $v0,4 
    la      $a0,_s5 
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
