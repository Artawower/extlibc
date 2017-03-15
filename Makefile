TARGET=libextc.so

INCLUDE_DIR=include
SOURCE_DIR=source

SOURCES=$(shell find $(SOURCE_DIR) -type f -name "*.c")
OBJECTS=$(SOURCES:%.c=%.o)

CC=cc
CFLAGS=-Os -c -fPIC -Wall --std=c99 -I $(INCLUDE_DIR)
SOFLAGS=-shared

.SILENT:

all: libextc

%.o: %.c
	echo "CC   $@"
	$(CC) $(CFLAGS) -o $@ $<

libextc: $(OBJECTS)
	echo "CC   $(TARGET)"
	$(CC) $(SOFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
