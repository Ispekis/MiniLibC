bits 64

section .text

global index

extern strlen

index:
    xor     rcx, rcx
    mov     al, sil

.loop:
    cmp     al, byte 0
    je      .end_null_byte

    cmp     [rdi, rcx], byte 0
    je      .end_null

    cmp     [rdi, rcx], al
    jz      .end

    inc     rcx
    jmp     .loop

.end:
    add     rdi, rcx
    mov     rax, rdi
    ret

.end_null:
    mov     rax, 0
    ret

.end_null_byte:
    call strlen wrt ..plt

    add     rdi, rax
    mov     rax, rdi
    ret