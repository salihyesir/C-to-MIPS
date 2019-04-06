.text
.globl main
main:
	li $t0,44
	sb $t0,virgul_degiskeni
	li $t0,95
	sb $t0,ayir_degiskeni
	li $t0,1
	li $t1,115
	la $t2,sira_degiskeni
	mul $t0,1
	add $t2,$t2,$t0
	sb $t1,-1($t2)
	li $t0,2
	li $t1,105
	la $t2,sira_degiskeni
	mul $t0,1
	add $t2,$t2,$t0
	sb $t1,-1($t2)
	li $t0,3
	li $t1,114
	la $t2,sira_degiskeni
	mul $t0,1
	add $t2,$t2,$t0
	sb $t1,-1($t2)
	li $t0,4
	li $t1,97
	la $t2,sira_degiskeni
	mul $t0,1
	add $t2,$t2,$t0
	sb $t1,-1($t2)
	li $t0,5
	li $t1,58
	la $t2,sira_degiskeni
	mul $t0,1
	add $t2,$t2,$t0
	sb $t1,-1($t2)
	li $t0,0
	sw $t0,i_degiskeni
for_loop_0:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $t1,15
	slt $t0,$t0,$t1
	beq $t0,$zero,e0
	j f0
ef0:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	addi $t0,$t0,1
	sw $t0,i_degiskeni
	j for_loop_0
	f0:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $t1,1000
	lw $t2,i_degiskeni
	div $t1,$t2
	mfhi,$t1
	li $t2,100
	add $t1,$t1,$t2
	li $t2,60
	sub $t1,$t1,$t2
	li $t2,14
	li $t3,7
	div $t2,$t3
	mflo,$t2
	add $t1,$t1,$t2
	lw $t2,i_degiskeni
	seq $t2,$t2,$zero
	add $t1,$t1,$t2
	lw $t2,i_degiskeni
	li $t3,10
	or $t2,$t2,$t3
	add $t1,$t1,$t2
	lw $t2,i_degiskeni
	li $t3,10
	and $t2,$t2,$t3
	sub $t1,$t1,$t2
	la $t2,arr_degiskeni
	mul $t0,4
	add $t2,$t2,$t0
	sw $t1,($t2)
	lw $t0,i_degiskeni
	la $t1,arr_degiskeni
	li $t3,4
	mult $t0,$t3
	mflo $t0
	add $t1,$t1,$t0
	lw $t4,($t1)
	li $t0,45
	slt $t4,$t4,$t0
beq $t4,$zero,else_1
	lw $t0,i_degiskeni
	lw $t1,i_degiskeni
	la $t3,arr_degiskeni
	li $t5,4
	mult $t1,$t5
	mflo $t1
	add $t3,$t3,$t1
	lw $t6,($t3)
	lw $t1,i_degiskeni
	li $t3,10
	or $t1,$t1,$t3
	seq $t1,$t1,$zero
	add $t6,$t6,$t1
	lw $t1,i_degiskeni
	li $t3,10
	and $t1,$t1,$t3
	seq $t1,$t1,$zero
	sub $t6,$t6,$t1
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	sw $t6,($t1)
j end_1
else_1:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	lw $t1,i_degiskeni
	la $t2,arr_degiskeni
	li $t4,4
	mult $t1,$t4
	mflo $t1
	add $t2,$t2,$t1
	lw $t5,($t2)
	lw $t1,i_degiskeni
	seq $t1,$t1,$zero
	add $t5,$t5,$t1
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	sw $t5,($t1)
j end_1
end_1:
add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $t1,3
	div $t0,$t1
	mfhi,$t0
	li $t1,0
	seq $t0,$t0,$t1
	beq $t0,$zero,end_2
	lw $t0,i_degiskeni
	lw $t1,i_degiskeni
	la $t2,arr_degiskeni
	li $t4,4
	mult $t1,$t4
	mflo $t1
	add $t2,$t2,$t1
	lw $t5,($t2)
	lw $t1,i_degiskeni
	add $t5,$t5,$t1
	li $t1,10
	sub $t5,$t5,$t1
	lw $t1,i_degiskeni
	li $t2,14
	slt $t1,$t1,$t2
	add $t5,$t5,$t1
	lw $t1,i_degiskeni
	li $t2,5
	xor $t1,$t1,$t2
	seq $t1,$t1,$zero
	sub $t5,$t5,$t1
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	sw $t5,($t1)
	j end_2
end_2:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $v0, 1
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	lw $a0,($t1)
	syscall
	li $v0, 4
	la $a0,virgul
	syscall
	j ef0
e0:
	add $t0,$t0,$zero
	li $t0,1
	sw $t0,i_degiskeni
for_loop_3:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $t1,15
	slt $t0,$t0,$t1
	beq $t0,$zero,e3
	j f3
ef3:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	addi $t0,$t0,1
	sw $t0,i_degiskeni
	j for_loop_3
	f3:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	la $t1,arr_degiskeni
	li $t3,4
	mult $t0,$t3
	mflo $t0
	add $t1,$t1,$t0
	lw $t4,($t1)
	sw $t4,key_degiskeni
	lw $t0,i_degiskeni
	li $t1,1
	sub $t0,$t0,$t1
	sw $t0,j_degiskeni
while_loop_4:
	add $t0,$t0,$zero
	lw $t0,j_degiskeni
	li $t1,0
	sge $t0,$t0,$t1
	lw $t1,j_degiskeni
	la $t2,arr_degiskeni
	li $t4,4
	mult $t1,$t4
	mflo $t1
	add $t2,$t2,$t1
	lw $t5,($t2)
	lw $t1,key_degiskeni
	sgt $t5,$t5,$t1
	and $t0,$t0,$t5
	beq $t0,$zero,e4
	lw $t0,j_degiskeni
	li $t1,1
	add $t0,$t0,$t1
	lw $t1,j_degiskeni
	la $t2,arr_degiskeni
	li $t5,4
	mult $t1,$t5
	mflo $t1
	add $t2,$t2,$t1
	lw $t6,($t2)
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	sw $t6,($t1)
	lw $t0,j_degiskeni
	addi $t0,$t0,-1
	sw $t0,j_degiskeni
	j while_loop_4
e4:
	add $t0,$t0,$zero
	lw $t0,j_degiskeni
	li $t1,1
	add $t0,$t0,$t1
	lw $t1,key_degiskeni
	la $t2,arr_degiskeni
	mul $t0,4
	add $t2,$t2,$t0
	sw $t1,($t2)
	j ef3
e3:
	add $t0,$t0,$zero
	li $v0, 4
	la $a0,sira
	syscall
	li $t0,0
	sw $t0,i_degiskeni
for_loop_5:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	li $t1,15
	slt $t0,$t0,$t1
	beq $t0,$zero,e5
	j f5
ef5:
	add $t0,$t0,$zero
	lw $t0,i_degiskeni
	addi $t0,$t0,1
	sw $t0,i_degiskeni
	j for_loop_5
	f5:
	add $t0,$t0,$zero
	li $v0, 4
	la $a0,ayir
	syscall
	lw $t0,i_degiskeni
	li $v0, 1
	la $t1,arr_degiskeni
	mul $t0,4
	add $t1,$t1,$t0
	lw $a0,($t1)
	syscall
	j ef5
e5:
	add $t0,$t0,$zero
	li $v0,10
	syscall

.data
arr_degiskeni: .word 0:15
ayir_degiskeni: .word 0
i_degiskeni: .word 0
j_degiskeni: .word 0
key_degiskeni: .word 0
sira_degiskeni: .byte 0:5
virgul_degiskeni: .word 0
#Program sozdizimsel olarak gecerlidir
