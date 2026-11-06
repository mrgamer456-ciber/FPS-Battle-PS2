EE_BIN = fps-battle.elf
EE_OBJS = src/main.o
EE_LIBS = -ldebug -lkernel

EE_INCS = -I$(PS2SDK)/ee/include
EE_CFLAGS = -O2 -G0 -Wall -Wextra

all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
