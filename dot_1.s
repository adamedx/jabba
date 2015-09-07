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
 
# ------------------------- start of function dot_product
dot_product:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
    li      $t0,1 
    sw      $t0,-40($fp)

#	// Line Number 10 

     .data 
_f0: .float 0.000000
     .text 
    l.s     $f2,_f0
    s.s     $f2,-44($fp)
lbl2: 
    lw      $t0,-40($fp)
    li      $t1,10 
    bgt     $t0,$t1,lbl1 
lbl0: 
#                         Start WHILE body 
    l.s     $f2,-44($fp)
    lw      $t0,-40($fp)
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    l.s     $f4,84($t0)
    lw      $t0,-40($fp)
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    l.s     $f6,44($t0)
    mul.s   $f8,$f4,$f6 
    add.s   $f10,$f2,$f8 
    s.s     $f10,-44($fp)
    lw      $t0,-40($fp)
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    b       lbl2 
#                         End WHILE body 
lbl1: 
    l.s     $f2,-44($fp)
    s.s     $f2,4($fp)
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function dot_product

# ------------------------- start of function main
main:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 

#	// Line Number 20 

    li      $t0,1 
    sw      $t0,-40($fp)
lbl5: 
    lw      $t0,-40($fp)
    li      $t1,10 
    bgt     $t0,$t1,lbl4 
lbl3: 
#                         Start WHILE body 

#	// Line Number 30 
#	// Initialize X

    lw      $t0,-40($fp)
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    lw      $t1,-40($fp)
    mtc1.d  $t1,$f2 
    cvt.s.w $f2,$f2 
    s.s     $f2,-48($t0)

#	// Initialize Y

    lw      $t0,-40($fp)
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    li      $t1,10 
    lw      $t2,-40($fp)
    sub     $t1,$t1,$t2 
    addi    $t1,$t1,1 
    mtc1.d  $t1,$f2 
    cvt.s.w $f2,$f2 
    s.s     $f2,-88($t0)

#	// Increment iterator
#	// Line Number 40 

    lw      $t0,-40($fp)
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    b       lbl5 
#                         End WHILE body 
lbl4: 
      .data
_s1:     .asciiz " The result of the dot_product SHOULD be 220.0" 
      .text
    li      $v0,4 
    la      $a0,_s1 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    la      $a0,-128($fp)
    la      $a1,-48($fp)
    li      $a2,40 
    jal     __move 
    la      $a0,-168($fp)
    la      $a1,-88($fp)
    li      $a2,40 
    jal     __move 
    la      $sp,-212($fp)
    jal     dot_product 
    l.s     $f2,-208($fp)
    s.s     $f2,-44($fp)
      .data
_s2:     .asciiz " The result of the dot_product is " 
      .text
    li      $v0,4 
    la      $a0,_s2 
    syscall 
    l.s     $f2,-44($fp)
    li      $v0,2 
    mov.s   $f12,$f2 
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
