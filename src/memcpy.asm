bits 64

section .text

global memcpy

memcpy:
    xor     rcx, rcx

.loop:
    cmp     rcx, rdx
    jz      .end

    mov     al, [rsi, rcx]
    mov     [rdi, rcx], al
    inc     rcx
    jmp     .loop

.end:
    mov     rax, rdi
    ret