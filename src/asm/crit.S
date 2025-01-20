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

        mov rax, QWORD PTR st1[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR st2[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR st3[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR st4[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR st5[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR st6[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR stf1[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR stf2[rip]
        movsd QWORD PTR [rax], xmm0

        mov rax, QWORD PTR stf3[rip]
        movsd QWORD PTR [rax], xmm0

        xor rax, rax
        mov eax, 1
.return:
        pop rbp
        ret





.data
msg: .string "Critical Error, Exiting"
dz: .double 0

.section .note.GNU-stack,"",@progbits
