TARGET = main
cc = gcc
SRCS = main.c bstrutils.c
SRC = main.c
CFLAGS = -Wall -g
OBJS = $(SRCS:.c=.o)
LIB_BA = bstrutils.c
OBLIB = $(LIB_BA:.c=.o)
OBSR = $(SRC:.c=.0)

STATIC_main = main_static
SHARED_main = main_shared

LIB_STATIC = libstrutils.a
LIB_SHARED = libstrutils.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(cc) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

static: $(STATIC_main) $(LIB_STATIC)

$(LIB_STATIC): $(OBLIB)
	ar rsc $@ $<
%.0: %.c
	$(cc) $(CFLAGS) -c $< -o $@
$(STATIC_main): $(LIB_STATIC)
	$(cc) $(SRC) -L. -lstrutils -o $(STATIC_main)


shared: $(SHARED_main) $(LIB_SHARED)

$(LIB_SHARED): $(OBLIB)
	$(cc) -shared -o $@ $<
%.o: %.c
	$(cc) -fPIC -c $< -o $@

$(SHARED_main): $(LIB_SHARED)
	$(cc) $(SRC) -L. -lstrutils -o $(SHARED_main)


clean:
	rm -f *.o *.a *.so $(TARGET) $(STATIC_main) $(SHARED_main)