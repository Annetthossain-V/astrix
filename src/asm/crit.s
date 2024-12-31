.intel_syntax noprefix

.global CritExit
.extern exit
.extern puts

.data
msg: .string "Critical Error, Exiting"

.text
CritExit:
        lea rdi, msg
        call puts

        mov rax, 60
        mov rdi, 1
        syscall

        ret
