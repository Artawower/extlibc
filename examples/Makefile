TARGET=example

SRCDIR=.
SOURCES=$(shell find $(SRCDIR) -type f -name "*.c")
OBJECTS=$(SOURCES:%.c=%.o)

CC=cc
CFLAGS=-Os -c -Wall --std=c99 -I $(SRCDIR)
LDFLAGS=-L. -l extc

.SILENT:

all: $(OBJECTS)
	cp ../libextc.so libextc.so
	echo "LD   $(TARGET)"
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	echo "CC   $@"
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET) libextc.so
