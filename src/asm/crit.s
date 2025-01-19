.intel_syntax noprefix

.global CritExit
.global SigCheck

.data
msg: .string "Critical Error, Exiting"

.text
CritExit:
        lea rdi, msg
        call puts

        mov rax, 60
        mov rdi, 1
        syscall
        nop
        nop
        nop

SigCheck:

.section .note.GNU-stack,"",@progbits
