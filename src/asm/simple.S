.intel_syntax noprefix


.section .text
.global strlen_ASM
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

.section .note.GNU-stack, "",@progbits