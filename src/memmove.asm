bits 64

section .text

global memmove

memmove:
    xor     rcx, rcx
    xor     rax, rax

.loop:
    cmp     rcx, rdx
    jz      .end

    mov     al, [rsi, rcx]
    mov     [rdi, rcx], al
    inc     rcx
    jmp     .loop

.end:
    lea     rax, [rdi]
    ret
