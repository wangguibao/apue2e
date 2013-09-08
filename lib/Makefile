include ../make.def

AR := ar
LIB := libapue.a
RANLIB := ranlib

OBJS := error.o pathalloc.o

all: $(OBJS)
	$(AR) rv $(LIB) $?
	$(RANLIB) $(LIB)

clean:
	rm -f *.o a.out core temp.* ptyopen.c $(LIB)

