extern bss_begin
extern bss_end
extern entry
extern gdt

section .entry

global _start
_start:
    cld

    ; Zero out .bss
    xor al, al
    mov edi, bss_begin
    mov ecx, bss_end
    sub ecx, bss_begin
    rep stosb

    lgdt [gdt]
    jmp 0x18:.reload_cs
  .reload_cs:
    mov eax, 0x20
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp entry
