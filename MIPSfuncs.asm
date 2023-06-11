endloop:

	jal next       # return to main


# while loop
WhileLoop:

	lw $t0, addNumbersvarM              # load the variable into $t0
	li $t1, 0               # load the number into $t1
	bne $t0, $t1, endloop   # break loop if true 

	j WhileLoop       # loop back


# while loop
WhileLoop:

	lw $t0, addNumbersvarN              # load the variable into $t0
	li $t1, 0               # load the number into $t1
	bne $t0, $t1, endloop   # break loop if true 

	j WhileLoop       # loop back


# while loop
WhileLoop:

	lw $t0, globalx              # load the variable into $t0
	li $t1, 1               # load the number into $t1
	bne $t0, $t1, endloop   # break loop if true 

	j WhileLoop       # loop back

