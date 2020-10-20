CP := cp
RM := rm -f
MKDIR := mkdir -pv

BIN = kernel
CFG = grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

iso: kernel
    $(MKDIR) $(GRUB_PATH)
    $(CP) $(BIN) $(BOOT_PATH)
    $(CP) $(CFG) $(GRUB_PATH)
    grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
    grub-mkrescue -o my-kernel.iso $(ISO_PATH)

boot.o: boot.asm
    nasm -f elf32 boot.asm -o boot.o

kernel.o:kernel.c kernel.h
    gcc -m32 -c kernel.c -o kernel.o

kernel: linker.ld boot.o kernel.o
    ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o

clean: 
    $(RM) *.o $(BIN) -r *iso