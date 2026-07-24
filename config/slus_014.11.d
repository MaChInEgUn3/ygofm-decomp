build/slus_014.11.elf: \
    build/asm/header.o \
    build/asm/data/800.rodata.o \
    build/src/31D8.o \
    build/asm/data/80EE0.data.o \
    build/asm/data/8B708.data.o \
    build/asm/data/carddata.data.o
build/asm/header.o:
build/asm/data/800.rodata.o:
build/src/31D8.o:
build/asm/data/80EE0.data.o:
build/asm/data/8B708.data.o:
build/asm/data/carddata.data.o:
-include build/asm/header.d build/asm/data/800.rodata.d build/src/31D8.d build/asm/data/80EE0.data.d build/asm/data/8B708.data.d build/asm/data/carddata.data.d
