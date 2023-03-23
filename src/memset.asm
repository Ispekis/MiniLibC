bits 64

section .text

global memset

memset:
    xor     rcx, rcx

.loop:
    cmp     rcx, rdx
    jz      .end
    mov     [rdi, rcx], sil
    inc     rcx
    jmp     .loop

.end:
    mov     rax, rdi
    ret