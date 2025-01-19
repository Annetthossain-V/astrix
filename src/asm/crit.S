.intel_syntax noprefix

.global CritExit
.global Data_Initialize

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


Data_Initialize:
        nop
        nop

        call CritExit


.section .note.GNU-stack,"",@progbits
