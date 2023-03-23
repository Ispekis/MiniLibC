bits 64

section .text

global strncmp

strncmp:
    xor     rcx, rcx

.loop:
    ; Check if it reach the null bit
    cmp     [rdi, rcx], byte 0
    jz      .is_end

    ; Check if it reach the number
    cmp     rcx, rdx
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