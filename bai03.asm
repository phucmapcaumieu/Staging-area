.data 
a: 	.word 1, 2, 3, 4, 0
n: 	.word 
MAX:	.word	
asc:	.asciiz "Mang tang dan! \n"
nasc: 	.asciiz "Mang khong tang dan! \n"

.text
.globl main
main:	la 	$s0, a 	   	# load source array
	lw	$t0, ($s0)	# load a[0]
	la 	$s1, n		# load number of array	
	la	$s2, MAX	# load max size of array
	li	$s2, 20	# define that max size is 1000
	li	$t1, 0		# set i = 0 
	li	$t2, -1		# lastNonEqualZero = -1
	
# loop to calculate number of element
loop:	beq	$t1, $s2, set_n	# if i == 1000 then break and set n	
	bnez	$t0, update_iter# if *a != 0 then lastNonEqualZero = i
	j 	inc_loop
	
update_iter:
	move 	$t2, $t1	# lastNonEqualZero = i
	j 	inc_loop
	
inc_loop:
 	addi	$t1, $t1, 1	# i++ 
	addi	$s0, $s0, 4	# a += 1 (a is pointer)
	lw 	$t0, ($s0)	# load *a
	j	loop
	
set_n:	addi	$s1, $t2, 1	# n = lastNonEqualZero + 1
	addi	$s1, $s1, -10	# n -= 10 because ignore 10 padding byte in the end of array

# loop to check is asc or not
	ori	$t0, $s1, 0	# check whether n = 0 
	ori	$t0, $t0, 1	#	OR n = 1
	li	$t1, 1		# load temp register and set it to 1
	beq	$t0, $t1, ascending	# if (n=0 OR n=1 is true) then ascending 	
	
	la	$s0, a		# load array
	lw	$t1, ($s0)	# t1 = valueOf(a)
	addi	$s0, $s0, 4	# move to next cell
	lw	$t2, ($s0)	# t2 = valueOf(a)
	li	$t0, 1		# set i = 1	
	addi 	$s2, $s1, -1	# set n -= 1 in order to not access invalid value of array 
	
loop_check:
	beq	$t0, $s2, ascending	# if (i > n) then print result and exit
	slt	$t3,  $t1, $t2		# bool isLessthan = (a < b)	
	beqz	$t3, notAscending	# if (isLessthan) is false then notAscending
	move 	$t1, $t2		# set a[berofe] = a[current]
	addi	$s0, $s0, 4		# move to next cell
	lw	$t2, ($s0)		# t2 = valueOf(a)
	addi	$t0, $t0, 1		# i += 1
	j	loop_check		# loop
	
ascending:
	la	$a0, asc	# message asending
	li	$v0, 4		# load systemcall print out
	syscall			# print msg
	j	exit		# exit

notAscending:
	la	$a0, nasc	# message not asending
	li	$v0, 4		# load systemcall print out
	syscall			# print msg
	j 	exit
	
exit:	li 	$v0, 10		# exit program
	syscall			
	
	
	
	
	
	
	
	
	
	
	
	
