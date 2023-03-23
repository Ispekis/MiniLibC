bits 64

section .text

global strstr

extern strncmp

extern strlen

strstr:
    xor     rcx, rcx
    xor     rax, rax

    mov     r9, rdi ; store in tmp value the rdi
    mov     rdi, rsi
    call strlen wrt ..plt
    mov     rdx, rax
    xor     rax, rax

    mov     rdi, r9 ; restiture the rdi

.loop:
    ; Check if the snd str is a null byte
    cmp     [rsi, 0], byte 0
    je      .end_null_byte

    ; set to null byte when touched the null byte of the needle
    cmp     [rdi, 0], byte 0
    je      .end_null

    call    strncmp wrt ..plt
    cmp     rax, 0
    je      .end

    add     rdi, 1

    jmp     .loop

.end:
    lea     rax, [rdi] ; maybe not the right return value
    ret

.end_null:
    mov     rax, 0
    ret

.end_null_byte:
    lea     rax, [rdi]
    ret