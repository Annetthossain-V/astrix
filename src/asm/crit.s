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

        mov rdi, 199
        call exit

        mov rax, 60
        mov rdi, 999
        syscall

        ret
