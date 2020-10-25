bits 32

section .multiboot
    dd 0x1BADB002

    dd 0x0
    dd - (0x1BADB002 + 0x0)

section .text
global start
global load_disk
global shutdown
extern main

start:
    cli
    mov esp, stack_space
    call main
    call shutdown

shutdown:
	mov ax, 0x1000
	mov ax, ss
	mov sp, 0xf000
	mov ax, 0x5307
	mov bx, 0x0001
	mov cx, 0x0003
	int 0x15
	ret


section .bss
resb 8192
stack_space: