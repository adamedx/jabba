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
 

#	// arith.ds
#	// Start with simple integer and real arithmetic
#	// Line Number 10 

    li      $t0,1 
    sw      $t0,-40($fp)
    li      $t0,2 
    sw      $t0,-44($fp)
    li      $t0,3 
    sw      $t0,-48($fp)
      .data
_s0:     .asciiz " The value of 'i + j * k' should be (7) -- " 
      .text
    li      $v0,4 
    la      $a0,_s0 
    syscall 
    lw      $t0,-40($fp)
    lw      $t1,-44($fp)
    lw      $t2,-48($fp)
    mul     $t1,$t1,$t2 
    add     $t0,$t0,$t1 
    li      $v0,1 
    move    $a0,$t0 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
     .data 
_f1: .float 1.000000
     .text 
    l.s     $f2,_f1
    s.s     $f2,-52($fp)
     .data 
_f2: .float 3.141590
     .text 
    l.s     $f2,_f2
    s.s     $f2,-56($fp)

#	// Line Number 20 

    l.s     $f2,-52($fp)
    l.s     $f4,-56($fp)
    mul.s   $f6,$f2,$f4 
    s.s     $f6,-60($fp)

#	// Here's the move to k

    l.s     $f2,-60($fp)
    cvt.w.s $f2,$f2 
    mfc1.s  $t0,$f2 
    sw      $t0,-48($fp)
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s3:     .asciiz " We should get PI and 3 " 
      .text
    li      $v0,4 
    la      $a0,_s3 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s4:     .asciiz " The value of z and k are " 
      .text
    li      $v0,4 
    la      $a0,_s4 
    syscall 
    l.s     $f2,-60($fp)
    li      $v0,2 
    mov.s   $f12,$f2 
    syscall 
      .data
_s5:     .asciiz " and " 
      .text
    li      $v0,4 
    la      $a0,_s5 
    syscall 
    lw      $t0,-48($fp)
    li      $v0,1 
    move    $a0,$t0 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 

#	// Line Number 30 

    li      $t0,1 
    mtc1.d  $t0,$f2 
    cvt.s.w $f2,$f2 
    s.s     $f2,-52($fp)
    l.s     $f2,-52($fp)
    l.s     $f4,-56($fp)
    mul.s   $f6,$f2,$f4 
    s.s     $f6,-60($fp)
      .data
_s6:     .asciiz " We should, again, get PI " 
      .text
    li      $v0,4 
    la      $a0,_s6 
    syscall 
    li      $v0,4 
    la      $a0,endl 
    syscall 
      .data
_s7:     .asciiz " The value of Z is " 
      .text
    li      $v0,4 
    la      $a0,_s7 
    syscall 
    l.s     $f2,-60($fp)
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
