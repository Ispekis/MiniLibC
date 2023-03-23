bits 64

section .text

global strcasecmp

strcasecmp:
    xor     rcx, rcx


.loop:
    cmp     [rdi, rcx], byte 0
    jz      .is_end

    mov     al, [rsi, rcx]

    cmp     [rdi, rcx], al
    jz      .increment

    jmp     .is_same_upper


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

.is_same_upper:
    mov     al, [rsi, rcx]

    add     al, 32

    cmp     [rdi, rcx], al
    je      .increment

    ; check lower case if not upper
    jmp .is_same_lower

.is_same_lower:
    mov     al, [rsi, rcx]

    sub     al, 32

    cmp     [rdi, rcx], al
    je      .increment

    ; return result if not upper or lower
    jmp .not_same