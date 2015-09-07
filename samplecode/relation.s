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
 
    li      $t0,0 
    sw      $t0,-40($fp)
    li      $t0,1 
    sw      $t0,-44($fp)

#	// Line Number 10 

    li      $t0,3 
    sw      $t0,-48($fp)
    li      $t0,17 
    sw      $t0,-52($fp)
    lw      $t0,-44($fp)
    lw      $t1,-48($fp)
    slt     $t0,$t0,$t1 
    sw      $t0,-56($fp)
      .data
_s0:     .asciiz "The value of 'b' is " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,-56($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s1:     .asciiz " -- should be 1" 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    li      $t0,0 
    lw      $t1,-44($fp)
    lw      $t2,-48($fp)
    ble     $t1,$t2,lbl1 
lbl0: 
    lw      $t1,-40($fp)
    li      $t2,0 
    beq     $t1,$t2,lbl1 
    li      $t0,1 
lbl1: 
    sw      $t0,-56($fp)
      .data
_s2:     .asciiz "The value of 'b' is " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    lw      $t0,-56($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s3:     .asciiz " -- should be 0" 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 20 

    li      $t0,0 
    lw      $t1,-40($fp)
    li      $t2,0 
    beq     $t1,$t2,lbl4 
lbl3: 
    lw      $t1,-52($fp)
    lw      $t2,-40($fp)
    div     $t1,$t1,$t2 
    lw      $t2,-48($fp)
    ble     $t1,$t2,lbl4 
    li      $t0,1 
lbl4: 
    sw      $t0,-56($fp)
      .data
_s4:     .asciiz "The value of 'b' is " 
      .text
    li      $v0,4 
    la      $a0,_s4 
    syscall 
    lw      $t0,-56($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s5:     .asciiz " -- should be 0 " 
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
