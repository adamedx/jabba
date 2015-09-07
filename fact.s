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
 
# ------------------------- start of function factorial
factorial:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
    lw      $t0,8($fp)
    li      $t1,0 
    bgt     $t0,$t1,lbl1 
lbl0: 
#                         Start THEN clause 
    li      $t0,1 
    sw      $t0,4($fp)
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
#                         Start ELSE clause 
lbl1: 
    lw      $t0,8($fp)
    addi    $t0,$t0,-1 
    sw      $t0,-40($fp)
    la      $sp,-48($fp)
    jal     factorial 
    lw      $t0,8($fp)
    lw      $t1,-44($fp)
    mul     $t0,$t0,$t1 
    sw      $t0,4($fp)
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
#                         Finish ELSE clause 
lbl2: 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function factorial

# ------------------------- start of function FACTORIAL
FACTORIAL:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 10 

    li      $t0,1 
    sw      $t0,-40($fp)
lbl5: 
    lw      $t0,8($fp)
    li      $t1,0 
    ble     $t0,$t1,lbl4 
lbl3: 
#                         Start WHILE body 

#	// Line Number 20 

    lw      $t0,-40($fp)
    lw      $t1,8($fp)
    mul     $t0,$t0,$t1 
    sw      $t0,-40($fp)
    lw      $t0,8($fp)
    addi    $t0,$t0,-1 
    sw      $t0,8($fp)
    b       lbl5 
#                         End WHILE body 
lbl4: 
    lw      $t0,-40($fp)
    sw      $t0,4($fp)
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function FACTORIAL

# ------------------------- start of function main
main:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 30 

    li      $t0,5 
    sw      $t0,-40($fp)
      .data
_s0:     .asciiz "The value of factorial(" 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,-40($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s1:     .asciiz ") is " 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    lw      $t0,-40($fp)
    sw      $t0,-44($fp)
    la      $sp,-52($fp)
    jal     factorial 
    lw      $t0,-48($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s2:     .asciiz "The value of FACTORIAL(" 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    lw      $t0,-40($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
      .data
_s3:     .asciiz ") is " 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    lw      $t0,-40($fp)
    sw      $t0,-44($fp)
    la      $sp,-52($fp)
    jal     FACTORIAL 
    lw      $t0,-48($fp)
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
