bits 64

section .text

global strcmp

strcmp:
    xor     rcx, rcx


.loop:
    cmp     [rdi, rcx], byte 0
    jz      .is_end

    mov     al, [rsi, rcx]

    cmp     [rdi, rcx], al
    jz      .increment

    jmp     .not_same


.increment:
    inc     rcx
    jmp     .loop

.not_same:
    mov     r8b, [rdi, rcx]
    mov     r9b, [rsi, rcx]
    movsx     rax, r8b
    movsx     rbx, r9b
    sub rax, rbx
    ret

.same:
    mov     rax, 0
    ret

.is_end:
    cmp     [rsi, rcx], byte 0
    jz      .same

    jmp     .not_same
