bits 64

section .text

global strrchr
    extern strlen

strrchr:
    xor     rcx, rcx
    call    strlen  wrt ..plt
    mov     rcx, rax
    mov     al, sil

.loop:
    cmp     rcx, -1
    je      .end_null

    cmp     [rdi, rcx], al
    jz      .end

    dec     rcx
    jmp     .loop

.end:
    add     rdi, rcx
    mov     rax, rdi
    ret

.end_null:
    lea     rax, byte 0
    ret
