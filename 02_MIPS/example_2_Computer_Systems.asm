# "Computer Systems" in MIPS assembly
	# .text assembler directive
	.text

	# main as a global function
	.globl	main
	
# The label 'main'
main:
	# Run the print_string syscall which has code 4
	li	$v0,4		# Code for syscall: print_string
	la	$a0, msg	# Pointer to string (load the address of msg)
	syscall
	li	$v0,10		# Code for syscall: exit
	syscall

	# .data assembler directive
	.data

	# The .asciiz assembler directive
msg:	.asciiz	"Computer Systems\n"