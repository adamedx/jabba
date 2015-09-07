        .globl  factorial

# Implements:
#
# function int factorial( int n )
# {
#	if (n <= 0)
#		return( 1 );
#	else
#		return( n * factorial( n - 1 ));
# }

factorial:
        sw      $fp,0($sp)              # save the dynamic link.
        sw      $ra,-4($sp)             # save the return address
        move    $fp,$sp                 # make new frame pointer
#
# if (n <= 0)
#       return( 1 );
#
        lw      $t0,8($fp)              # load parameter 'n'
        bgtz    $t0,label1              # test if > 0
        li      $t1,1                   # load immediate 1
        sw      $t1,4($fp)              # save in return location
# 
        move    $sp,$fp                 # reset the top of stack
        lw      $ra,-4($sp)             # get the return address
        lw      $fp,0($sp)              # load the dynamic link
        jr      $ra                     # return
#
# else
#       return( n * factorial( n - 1 ));
#
label1: lw      $t0,8($fp)              # load parameter 'n'
        sub     $t1,$t0,1               # subtract 1
        sw      $t1,-40($fp)            # save in first parameter for call
        la      $sp,-48($fp)            # make new stack top pointer
        jal     factorial               # call factorial recursively

        lw      $t0,8($fp)              # load parameter 'n'
        lw      $t1,-44($fp)            # load recursive result value
        mul     $t2,$t1,$t0             # multiply
	sw	$t2,4($fp)		# save result
#
        move    $sp,$fp                 # reset the top of stack
        lw      $ra,-4($sp)             # get the return address
        lw      $fp,0($sp)              # load the dynamic link
        jr      $ra                     # return

################################################################

	.globl	FACTORIAL
	
# Implements:
# 
# function int FACTORIAL( int n )
# {
#	int result;
#
#	result := 1;
#	while (n > 0)
#	{
#		result := result * n;
#		n := n - 1;
#	}
# }	

FACTORIAL:
        sw      $fp,0($sp)              # save the dynamic link.
        sw      $ra,-4($sp)             # save the return address
        move    $fp,$sp                 # make new frame pointer
# result := 1;
        li		$t0,1		# Initialize the result
        sw		$t0,-40($fp)
# while (n > 0)
label2:
	lw	$t0,8($fp)		# load 'n'
	blez	$t0,label3		# branch if <= 0
#   result := result * n
        lw      $t0,8($fp)              # load 'n'
        lw      $t1,-40($fp)            # load 'result'
        mul     $t2,$t1,$t0             # multiply
        sw      $t2,-40($fp)            # save
#   n := n - 1
	lw      $t0,8($fp)              # load 'n'
	sub     $t1,$t0,1               # subtract 1
	sw      $t1,8($fp)              # save
		
	b       label2                  # goto top of loop
label3:
        lw      $t1,-40($fp)            # load 'result'
        sw      $t1,4($fp)              # save result in return location

        move    $sp,$fp                 # reset the top of stack
        lw      $ra,-4($sp)             # get the return address
        lw      $fp,0($sp)              # load the dynamic link
        jr      $ra                     # return

################################################################

        .data
string1:        .asciiz "The value of factorial( 5 ) is "
string2:        .asciiz "The value of FACTORIAL( 5 ) is "
endl:   .asciiz "\n"

################################################################

        .text
        .globl main
	.globl call			# used to set BREAKPOINTs

# Implements
#
# function void main()
# {
#	println(" The value of factorial( 5 ) is ", factorial( 5 ));
#	println(" The value of FACTORIAL( 5 ) is ", FACTORIAL( 5 ));
# }
main:
        sw      $fp,0($sp)              # save the dynamic link.
        sw      $ra,-4($sp)             # save the return address
        move    $fp,$sp                 # make new frame pointer
#
#       println("The value of factorial( 5 ) is ", factorial( 5 ));
#
        li      $t0,5                   # load the constant
        sw      $t0,-40($fp)            # save in parameter list
        la      $sp,-48($fp)            # make new stack top pointer
call:
        jal     factorial               # call factorial recursively

        li      $v0,4                   # system call code for PRINT_STR
        la      $a0,string1             # get address of string to print
        syscall                         # print string
        li      $v0,1                   # system call code for PRINT_INT
        lw      $a0,-44($fp)            # load function result value
        syscall
        li      $v0,4                   # system call code for PRINT_STR
        la      $a0,endl                # get address of NEWLINE string
        syscall                         # print string
#
#       println("The value of FACTORIAL( 5 ) is ", FACTORIAL( 5 ));
#
        li      $t0,5                   # load the constant
        sw      $t0,-40($fp)            # save in parameter list
        la      $sp,-48($fp)            # make new stack top pointer
        jal     FACTORIAL               # call factorial recursively

        li      $v0,4                   # system call code for PRINT_STR
        la      $a0,string2             # get address of string to print
        syscall                         # print string
        li      $v0,1                   # system call code for PRINT_INT
        lw      $a0,-44($fp)            # load function result value
        syscall
        li      $v0,4                   # system call code for PRINT_STR
        la      $a0,endl                # get address of NEWLINE string
        syscall                         # print string
#
#       finally, RETURN
#
        move    $sp,$fp                 # reset the top of stack
        lw      $fp,0($sp)              # load the dynamic link
        lw      $ra,-4($sp)             # get the return address
        jr      $ra                     # return
