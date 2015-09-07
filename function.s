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
 
# ------------------------- start of function nested
nested:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
      .data
_s0:     .asciiz " Nested: Global = " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,0($gp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s1:     .asciiz " :: First = " 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    lw      $t0,8($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s2:     .asciiz " :: Second = " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    lw      $t0,4($fp)
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
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function nested

# ------------------------- start of function main
main:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 10 

    li      $t0,1 
    sw      $t0,0($gp)
    li      $t0,1 
    sw      $t0,-40($fp)
    li      $t0,3 
    sw      $t0,-44($fp)
    la      $sp,-48($fp)
    jal     nested 

#	// Line Number 20 
#	// Second round

    lw      $t0,0($gp)
    addi    $t0,$t0,1 
    sw      $t0,0($gp)
    li      $t0,1 
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    li      $t0,3 
    addi    $t0,$t0,-1 
    sw      $t0,-44($fp)
    la      $sp,-48($fp)
    jal     nested 

#	// Third round

    lw      $t0,0($gp)
    addi    $t0,$t0,1 
    sw      $t0,0($gp)

#	// Line Number 30 

    li      $t0,1 
    addi    $t0,$t0,1 
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    li      $t0,3 
    addi    $t0,$t0,-2 
    sw      $t0,-44($fp)
    la      $sp,-48($fp)
    jal     nested 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function main


# Code Generation Completed 
