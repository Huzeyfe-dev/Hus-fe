CP := cp
RM := rm -f
MKDIR := mkdir -pv

BIN = kernel
CFG = grub.cfg
ISO_DIR_PATH := ../iso_dir
BOOT_PATH := $(ISO_DIR_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub
ISO_PATH := $../../iso/



kernel.iso: kernel kernel.o
	$(MKDIR) $(GRUB_PATH)
	$(MKDIR) $(ISO_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o $(ISO_PATH)/kernel.iso $(ISO_DIR_PATH)

boot.o: boot.asm
	nasm -f elf32 boot.asm -o boot.o

kernel.o: kernel.c include/kabuk.c include/kernel.h
	gcc -m32 -c kernel.c -o kernel.o

kernel: linker.ld boot.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o

#run: $(ISO_PATH)/kernel.iso
#	qemu-system-x86_64 $(ISO_PATH)/kernel.iso


clean:
	$(RM) *.o $(BIN) -r $(ISO_DIR_PATH)