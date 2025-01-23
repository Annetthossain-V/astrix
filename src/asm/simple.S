.intel_syntax noprefix


.section .text
.global strlen_ASM
.global kmalloc
.global ksleep
.global kwrite

strlen_ASM:
    xor eax, eax
    cmp BYTE PTR [rdi], 0
    je .L4

.L3:
    add eax, 1
    movsx rdx, ax
    cmp BYTE PTR [rdi+rdx], 0
    jne .L3
    ret

.L4:
    ret


kmalloc:
    mov rax, 1024
    mul rdi
    mov rdi, rax
    call malloc
    ret
    nop

ksleep:
    mov rax, 1000
    mul rdi
    mov rdi, rax
    xor rax, rax
    call usleep
    xor rax, rax
    ret
    nop



kwrite:
    push rbx
    mov rbx, rdi
    call strlen_ASM
    mov rdx, rax
    mov rcx, rbx
    mov rax, 1
    mov rdi, 1
    syscall
    ret
    ret


.section .note.GNU-stack, "",@progbits
