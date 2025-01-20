.intel_syntax noprefix

.global CritExit
.global Data_Initialize

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
        push rbp
        mov rbp, rsp


        movsd xmm0, QWORD PTR dz[rip]

        mov rax, QWORD PTR r0[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR r1[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR s0[rip]
        mov BYTE PTR [rax], 0

        mov rax, QWORD PTR s1[rip]
        mov BYTE PTR [rax], 0

.return:
        pop rbp
        nop
        xor eax, eax
        ret





.data
msg: .string "Critical Error, Exiting"
dz: .double 0

.section .note.GNU-stack,"",@progbits
