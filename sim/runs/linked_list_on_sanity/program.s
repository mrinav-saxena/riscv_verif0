	.file	"linked_list.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	test_complete
	.section	.sbss,"aw",@nobits
	.align	2
	.type	test_complete, @object
	.size	test_complete, 4
test_complete:
	.zero	4
	.globl	all_available_nodes
	.bss
	.align	2
	.type	all_available_nodes, @object
	.size	all_available_nodes, 512
all_available_nodes:
	.zero	512
	.text
	.align	2
	.globl	reserve_nodes_for_debug
	.type	reserve_nodes_for_debug, @function
reserve_nodes_for_debug:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	addi	s0,sp,16
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	li	a4,2
	sb	a4,0(a5)
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	li	a4,-1
	sh	a4,2(a5)
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	sb	zero,1(a5)
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	li	a4,2
	sb	a4,508(a5)
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	li	a4,-1
	sh	a4,510(a5)
	lui	a5,%hi(all_available_nodes)
	addi	a5,a5,%lo(all_available_nodes)
	sb	zero,509(a5)
	nop
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	reserve_nodes_for_debug, .-reserve_nodes_for_debug
	.align	2
	.globl	get_free_node
	.type	get_free_node, @function
get_free_node:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	sw	zero,-20(s0)
	j	.L3
.L6:
	lui	a5,%hi(all_available_nodes)
	addi	a4,a5,%lo(all_available_nodes)
	lw	a5,-20(s0)
	slli	a5,a5,2
	add	a5,a4,a5
	lbu	a5,0(a5)
	bne	a5,zero,.L4
	lui	a5,%hi(all_available_nodes)
	addi	a4,a5,%lo(all_available_nodes)
	lw	a5,-20(s0)
	slli	a5,a5,2
	add	a5,a4,a5
	li	a4,1
	sb	a4,0(a5)
	lw	a5,-20(s0)
	andi	a5,a5,0xff
	j	.L5
.L4:
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L3:
	lw	a4,-20(s0)
	li	a5,127
	ble	a4,a5,.L6
	li	a5,255
.L5:
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	get_free_node, .-get_free_node
	.align	2
	.globl	add_ll_node
	.type	add_ll_node, @function
add_ll_node:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	mv	a5,a0
	mv	a4,a1
	sb	a5,-33(s0)
	mv	a5,a4
	sh	a5,-36(s0)
	sw	zero,-20(s0)
	lbu	a5,-33(s0)
	sb	a5,-21(s0)
	call	get_free_node
	mv	a5,a0
	sb	a5,-22(s0)
	j	.L8
.L10:
	lbu	a5,-21(s0)
	beq	a5,zero,.L9
	lbu	a5,-21(s0)
	lui	a4,%hi(all_available_nodes)
	addi	a4,a4,%lo(all_available_nodes)
	slli	a5,a5,2
	add	a5,a4,a5
	lbu	a5,1(a5)
	sb	a5,-21(s0)
	j	.L8
.L9:
	li	a5,1
	sw	a5,-20(s0)
	lbu	a5,-21(s0)
	lui	a4,%hi(all_available_nodes)
	addi	a4,a4,%lo(all_available_nodes)
	slli	a5,a5,2
	add	a5,a4,a5
	lbu	a4,-22(s0)
	sb	a4,1(a5)
	lbu	a5,-22(s0)
	lui	a4,%hi(all_available_nodes)
	addi	a4,a4,%lo(all_available_nodes)
	slli	a5,a5,2
	add	a5,a4,a5
	lhu	a4,-36(s0)
	sh	a4,2(a5)
.L8:
	lw	a5,-20(s0)
	beq	a5,zero,.L10
	nop
	nop
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	add_ll_node, .-add_ll_node
	.globl	base_data
	.data
	.align	2
	.type	base_data, @object
	.size	base_data, 32
base_data:
	.half	4660
	.half	22136
	.half	-25924
	.half	-8464
	.half	9320
	.half	4951
	.half	-25633
	.half	-21265
	.half	13689
	.half	9320
	.half	-30002
	.half	4951
	.half	-25633
	.half	9320
	.half	4951
	.half	-25633
	.globl	init_ll_head_ptr
	.section	.sdata,"aw"
	.align	2
	.type	init_ll_head_ptr, @object
	.size	init_ll_head_ptr, 2
init_ll_head_ptr:
	.ascii	"Ez"
	.globl	random_sequence
	.data
	.align	2
	.type	random_sequence, @object
	.size	random_sequence, 16
random_sequence:
	.string	"\001"
	.string	"\001\001"
	.string	""
	.string	"\001"
	.string	"\001\001"
	.string	"\001"
	.string	""
	.ascii	"\001\001"
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	call	reserve_nodes_for_debug
	sw	zero,-20(s0)
	j	.L12
.L13:
	lui	a5,%hi(random_sequence)
	addi	a4,a5,%lo(random_sequence)
	lw	a5,-20(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	mv	a4,a5
	lui	a5,%hi(init_ll_head_ptr)
	addi	a5,a5,%lo(init_ll_head_ptr)
	add	a5,a4,a5
	lbu	a3,0(a5)
	lui	a5,%hi(base_data)
	addi	a4,a5,%lo(base_data)
	lw	a5,-20(s0)
	slli	a5,a5,1
	add	a5,a4,a5
	lhu	a5,0(a5)
	mv	a1,a5
	mv	a0,a3
	call	add_ll_node
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L12:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L13
	lui	a5,%hi(test_complete)
	li	a4,-559038464
	addi	a4,a4,-273
	sw	a4,%lo(test_complete)(a5)
	li	a5,0
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (xPack GNU RISC-V Embedded GCC x86_64) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
