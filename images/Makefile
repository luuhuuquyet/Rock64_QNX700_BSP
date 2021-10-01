ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

SUFFIXES := .build .ifs .bin

.PHONY: all clean

all: ifs-rk3328.bin

ifs-rk3328.bin: rk3328.build
	$(HOST_MKIFS) -vvv -r../install $(MKIFSFLAGS) $^ $@


clean:
	$(RM_HOST) *.bin *.build *.srec
