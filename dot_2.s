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
 
# ------------------------- start of function initialize
initialize:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
    li      $t0,1 
    sw      $t0,-40($fp)
lbl2: 
    lw      $t0,-40($fp)
    li      $t1,10 
    bgt     $t0,$t1,lbl1 
lbl0: 
#                         Start WHILE body 

#	// Line Number 10 

    lw      $t0,4($fp)
    lw      $t1,-40($fp)
    addi    $t1,$t1,-1 
    sll     $t1,$t1,2 
    sub     $t0,$t0,$t1 
    lw      $t2,-40($fp)
    mtc1.d  $t2,$f2 
    cvt.s.w $f2,$f2 
    s.s     $f2,0($t0)
    lw      $t0,-40($fp)
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    b       lbl2 
#                         End WHILE body 
lbl1: 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function initialize

# ------------------------- start of function provide
provide:
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
    lw      $t0,-40($fp)
    addi    $t0,$t0,-1 
    sll     $t0,$t0,2 
    sub     $t0,$fp,$t0 
    li      $t1,10 
    lw      $t2,-40($fp)
    addi    $t2,$t2,-1 
    sll     $t2,$t2,2 
    sub     $t2,$fp,$t2 
    l.s     $f2,80($t2)
    mtc1.d  $t1,$f6 
    cvt.s.w $f6,$f6 
    sub.s   $f4,$f6,$f2 
    li      $t1,1 
    mtc1.d  $t1,$f8 
    cvt.s.w $f8,$f8 
    add.s   $f10,$f4,$f8 
    s.s     $f10,-44($t0)
    lw      $t0,-40($fp)
    addi    $t0,$t0,1 
    sw      $t0,-40($fp)
    b       lbl5 
#                         End WHILE body 
lbl4: 

#	// Line Number 30 

    la      $a0,40($fp)
    la      $a1,-44($fp)
    li      $a2,40 
    jal     __move 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
 
    move    $sp,$fp 
    lw      $ra,-4($sp)
    lw      $fp,0($sp)
    jr      $ra 
# ------------------------- end of function provide

# ------------------------- start of function dot_product
dot_product:
    sw      $fp,0($sp)
    sw      $ra,-4($sp)
    move    $fp,$sp 
 
    li      $t0,1 
    sw      $t0,-40($fp)
     .data 
_f0: .float 0.000000
     .text 
    l.s     $f2,_f0
    s.s     $f2,-44($fp)

#	// Line Number 40 

lbl8: 
    lw      $t0,-40($fp)
    li      $t1,10 
    bgt     $t0,$t1,lbl7 
lbl6: 
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
    b       lbl8 
#                         End WHILE body 
lbl7: 
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
 

#	// Line Number 50 



	Syntax Error at Line # 61 
		Last tokens were: 
			 integer local -124 >> ADDRESS_OF << 

# Code Generation Completed 
