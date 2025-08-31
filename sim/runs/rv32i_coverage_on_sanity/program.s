	.file	"rv32i_coverage.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	bbuf
	.data
	.align	2
	.type	bbuf, @object
	.size	bbuf, 16
bbuf:
	.string	"xV4\022\252\273\314\335"
	.zero	7
	.globl	hbuf
	.align	2
	.type	hbuf, @object
	.size	hbuf, 16
hbuf:
	.half	22136
	.half	4660
	.half	-21555
	.half	0
	.half	-1
	.half	-32768
	.half	32767
	.half	4369
	.globl	wbuf
	.align	2
	.type	wbuf, @object
	.size	wbuf, 32
wbuf:
	.word	305419896
	.word	-559038737
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.globl	results
	.bss
	.align	2
	.type	results, @object
	.size	results, 256
results:
	.zero	256
	.globl	test_complete
	.section	.sbss,"aw",@nobits
	.align	2
	.type	test_complete, @object
	.size	test_complete, 4
test_complete:
	.zero	4
	.text
	.align	2
	.type	do_fence, @function
do_fence:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	addi	s0,sp,16
 #APP
# 18 "C:\Users\DELL\OneDrive\Documents\projects\riscv_verif0\code\rv32i_coverage.c" 1
	fence
# 0 "" 2
 #NO_APP
	nop
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	do_fence, .-do_fence
	.align	2
	.type	do_ebreak, @function
do_ebreak:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	addi	s0,sp,16
 #APP
# 19 "C:\Users\DELL\OneDrive\Documents\projects\riscv_verif0\code\rv32i_coverage.c" 1
	ebreak
# 0 "" 2
 #NO_APP
	nop
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	do_ebreak, .-do_ebreak
	.align	2
	.type	do_ecall, @function
do_ecall:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	addi	s0,sp,16
 #APP
# 20 "C:\Users\DELL\OneDrive\Documents\projects\riscv_verif0\code\rv32i_coverage.c" 1
	ecall
# 0 "" 2
 #NO_APP
	nop
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	do_ecall, .-do_ecall
	.align	2
	.type	force_lui, @function
force_lui:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
 #APP
# 28 "C:\Users\DELL\OneDrive\Documents\projects\riscv_verif0\code\rv32i_coverage.c" 1
	lui a5, 0x12345
addi a5, a5, 0x6
# 0 "" 2
 #NO_APP
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	force_lui, .-force_lui
	.align	2
	.type	callee, @function
callee:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	li	a5,0
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	callee, .-callee
	.align	2
	.type	do_alu_suite, @function
do_alu_suite:
	addi	sp,sp,-112
	sw	ra,108(sp)
	sw	s0,104(sp)
	addi	s0,sp,112
	sw	a0,-100(s0)
	sw	a1,-104(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	add	a5,a4,a5
	sw	a5,-20(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	sub	a5,a4,a5
	sw	a5,-24(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	and	a5,a4,a5
	sw	a5,-28(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	or	a5,a4,a5
	sw	a5,-32(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	xor	a5,a4,a5
	sw	a5,-36(s0)
	lw	a5,-104(s0)
	andi	a5,a5,31
	lw	a4,-100(s0)
	sll	a5,a4,a5
	sw	a5,-40(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	andi	a5,a5,31
	srl	a5,a4,a5
	sw	a5,-44(s0)
	lw	a5,-104(s0)
	andi	a5,a5,31
	lw	a4,-100(s0)
	sra	a5,a4,a5
	sw	a5,-48(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	slt	a5,a4,a5
	andi	a5,a5,0xff
	sw	a5,-52(s0)
	lw	a4,-100(s0)
	lw	a5,-104(s0)
	sltu	a5,a4,a5
	andi	a5,a5,0xff
	sw	a5,-56(s0)
	lw	a5,-100(s0)
	addi	a5,a5,10
	sw	a5,-60(s0)
	lw	a5,-100(s0)
	andi	a5,a5,15
	sw	a5,-64(s0)
	lw	a5,-100(s0)
	ori	a5,a5,240
	sw	a5,-68(s0)
	lw	a5,-100(s0)
	xori	a5,a5,255
	sw	a5,-72(s0)
	lw	a5,-100(s0)
	slli	a5,a5,2
	sw	a5,-76(s0)
	lw	a5,-100(s0)
	srli	a5,a5,1
	sw	a5,-80(s0)
	lw	a5,-100(s0)
	srai	a5,a5,1
	sw	a5,-84(s0)
	lw	a5,-100(s0)
	slti	a5,a5,20
	andi	a5,a5,0xff
	sw	a5,-88(s0)
	lw	a5,-100(s0)
	sltiu	a5,a5,5
	andi	a5,a5,0xff
	sw	a5,-92(s0)
	sw	zero,-96(s0)
	lw	a4,-20(s0)
	lw	a5,-24(s0)
	add	a4,a4,a5
	lw	a5,-28(s0)
	add	a4,a4,a5
	lw	a5,-32(s0)
	add	a4,a4,a5
	lw	a5,-36(s0)
	add	a5,a4,a5
	lw	a4,-96(s0)
	add	a5,a4,a5
	sw	a5,-96(s0)
	lw	a4,-40(s0)
	lw	a5,-44(s0)
	add	a4,a4,a5
	lw	a5,-48(s0)
	add	a4,a4,a5
	lw	a5,-52(s0)
	add	a4,a4,a5
	lw	a5,-56(s0)
	add	a5,a4,a5
	lw	a4,-96(s0)
	add	a5,a4,a5
	sw	a5,-96(s0)
	lw	a4,-60(s0)
	lw	a5,-64(s0)
	add	a4,a4,a5
	lw	a5,-68(s0)
	add	a4,a4,a5
	lw	a5,-72(s0)
	add	a4,a4,a5
	lw	a5,-76(s0)
	add	a4,a4,a5
	lw	a5,-80(s0)
	add	a4,a4,a5
	lw	a5,-84(s0)
	add	a4,a4,a5
	lw	a5,-88(s0)
	add	a4,a4,a5
	lw	a5,-92(s0)
	add	a5,a4,a5
	lw	a4,-96(s0)
	add	a5,a4,a5
	sw	a5,-96(s0)
	lw	a5,-96(s0)
	mv	a0,a5
	lw	ra,108(sp)
	lw	s0,104(sp)
	addi	sp,sp,112
	jr	ra
	.size	do_alu_suite, .-do_alu_suite
	.align	2
	.type	branch_suite, @function
branch_suite:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	sw	zero,-20(s0)
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	bne	a4,a5,.L11
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L11:
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	beq	a4,a5,.L12
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L12:
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	bge	a4,a5,.L13
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L13:
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	blt	a4,a5,.L14
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L14:
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	bgeu	a4,a5,.L15
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L15:
	lw	a4,-36(s0)
	lw	a5,-40(s0)
	bltu	a4,a5,.L16
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L16:
	sw	zero,-24(s0)
	j	.L17
.L18:
	lw	a4,-20(s0)
	lw	a5,-24(s0)
	add	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L17:
	lw	a4,-24(s0)
	li	a5,3
	ble	a4,a5,.L18
	lw	a5,-20(s0)
	mv	a0,a5
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	branch_suite, .-branch_suite
	.align	2
	.type	load_store_suite, @function
load_store_suite:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	lui	a5,%hi(bbuf)
	addi	a5,a5,%lo(bbuf)
	lbu	a5,0(a5)
	andi	a5,a5,0xff
	slli	a5,a5,24
	srai	a5,a5,24
	sw	a5,-20(s0)
	lui	a5,%hi(hbuf)
	addi	a5,a5,%lo(hbuf)
	lhu	a5,0(a5)
	slli	a5,a5,16
	srli	a5,a5,16
	slli	a5,a5,16
	srai	a5,a5,16
	sw	a5,-24(s0)
	lui	a5,%hi(wbuf)
	addi	a5,a5,%lo(wbuf)
	lw	a5,0(a5)
	sw	a5,-28(s0)
	lui	a5,%hi(bbuf)
	addi	a5,a5,%lo(bbuf)
	lbu	a5,1(a5)
	andi	a5,a5,0xff
	sw	a5,-32(s0)
	lui	a5,%hi(hbuf)
	addi	a5,a5,%lo(hbuf)
	lhu	a5,2(a5)
	slli	a5,a5,16
	srli	a5,a5,16
	sw	a5,-36(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-20(s0)
	sw	a4,0(a5)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-24(s0)
	sw	a4,4(a5)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-28(s0)
	sw	a4,8(a5)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-32(s0)
	sw	a4,12(a5)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-36(s0)
	sw	a4,16(a5)
	lw	a5,-20(s0)
	andi	a4,a5,0xff
	lui	a5,%hi(bbuf)
	addi	a5,a5,%lo(bbuf)
	sb	a4,2(a5)
	lw	a5,-24(s0)
	slli	a4,a5,16
	srli	a4,a4,16
	lui	a5,%hi(hbuf)
	addi	a5,a5,%lo(hbuf)
	sh	a4,4(a5)
	lw	a4,-28(s0)
	lw	a5,-32(s0)
	add	a4,a4,a5
	lw	a5,-36(s0)
	add	a4,a4,a5
	lui	a5,%hi(wbuf)
	addi	a5,a5,%lo(wbuf)
	sw	a4,8(a5)
	nop
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	load_store_suite, .-load_store_suite
	.align	2
	.type	force_auipc_addi, @function
force_auipc_addi:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
 #APP
# 116 "C:\Users\DELL\OneDrive\Documents\projects\riscv_verif0\code\rv32i_coverage.c" 1
	.globl __here
__here:

# 0 "" 2
 #NO_APP
	lui	a5,%hi(__here)
	addi	a5,a5,%lo(__here)
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	force_auipc_addi, .-force_auipc_addi
	.align	2
	.type	call_indirect, @function
call_indirect:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	sw	a2,-28(s0)
	lw	a5,-20(s0)
	lw	a1,-28(s0)
	lw	a0,-24(s0)
	jalr	a5
	mv	a5,a0
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	call_indirect, .-call_indirect
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-80
	sw	ra,76(sp)
	sw	s0,72(sp)
	addi	s0,sp,80
	call	do_fence
	call	force_lui
	sw	a0,-20(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-20(s0)
	sw	a4,40(a5)
	call	force_auipc_addi
	sw	a0,-24(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-24(s0)
	sw	a4,44(a5)
	li	a5,305418240
	addi	a5,a5,1656
	sw	a5,-28(s0)
	li	a5,15790080
	addi	a5,a5,15
	sw	a5,-32(s0)
	lw	a1,-32(s0)
	lw	a0,-28(s0)
	call	do_alu_suite
	sw	a0,-36(s0)
	lw	a4,-36(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,48(a5)
	li	a5,-2147483648
	addi	a1,a5,-1
	li	a0,-2147483648
	call	branch_suite
	sw	a0,-40(s0)
	lw	a4,-40(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,52(a5)
	call	load_store_suite
	lui	a5,%hi(wbuf)
	addi	a5,a5,%lo(wbuf)
	lw	a4,8(a5)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,56(a5)
	li	a1,3
	li	a0,7
	call	callee
	sw	a0,-44(s0)
	li	a2,5
	li	a1,11
	lui	a5,%hi(callee)
	addi	a0,a5,%lo(callee)
	call	call_indirect
	sw	a0,-48(s0)
	lw	a4,-44(s0)
	lw	a5,-48(s0)
	add	a5,a4,a5
	mv	a4,a5
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,60(a5)
	li	a5,42
	sw	a5,-52(s0)
	lw	a5,-52(s0)
	ori	a5,a5,291
	xori	a5,a5,7
	mv	a4,a5
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,64(a5)
	lw	a5,-52(s0)
	slli	a5,a5,1
	andi	a4,a5,126
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,68(a5)
	lw	a5,-52(s0)
	srli	a4,a5,2
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,72(a5)
	li	a5,-1
	sb	a5,-53(s0)
	lb	a5,-53(s0)
	sw	a5,-60(s0)
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	lw	a4,-60(s0)
	sw	a4,76(a5)
	li	a5,-1
	sw	a5,-64(s0)
	sw	zero,-68(s0)
	lw	a4,-64(s0)
	lw	a5,-68(s0)
	sgtu	a5,a4,a5
	andi	a5,a5,0xff
	mv	a4,a5
	lui	a5,%hi(results)
	addi	a5,a5,%lo(results)
	sw	a4,80(a5)
	call	do_ecall
	call	do_ebreak
	lui	a5,%hi(test_complete)
	li	a4,-559038464
	addi	a4,a4,-273
	sw	a4,%lo(test_complete)(a5)
	li	a5,0
	mv	a0,a5
	lw	ra,76(sp)
	lw	s0,72(sp)
	addi	sp,sp,80
	jr	ra
	.size	main, .-main
	.ident	"GCC: (xPack GNU RISC-V Embedded GCC x86_64) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
