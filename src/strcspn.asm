bits 64

section .text

global strcspn

extern strlen

strcspn:
    xor     rcx, rcx
    xor     rdx, rdx

.loop:
    cmp     [rdi, rdx], byte 0
    je      .not_found

    cmp     [rsi, rcx], byte 0
    je      .increment

    mov     al, [rsi, rcx]
    cmp     [rdi, rdx], al
    je      .end

    inc     rcx
    jmp     .loop

.increment:
    xor     rcx, rcx,
    inc     rdx
    jmp     .loop

.end:
    xor     rcx, rcx

    mov     sil, [rdi, rdx]

    ; call strchr after founding the first letter
    call _strchr

    ret

.not_found:
    ; return the strlen of the str1 if not found
    call    strlen wrt ..plt
    ret

_strchr:
    xor     rcx, rcx
    mov     al, sil

.loop:
    cmp     [rdi, rcx], byte 0
    je      .end_null

    cmp     [rdi, rcx], al
    jz      .end

    inc     rcx
    jmp     .loop

.end:
    mov     rax, rcx
    ret

.end_null:
    mov     rax, 0
    ret