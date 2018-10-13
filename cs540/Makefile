# Makefile for example programs
#	where to find PAPI
#PAPI = /site/local/papi_64-3.7.0
PAPI = /site/local/papi_64-4.1.4
LIB_DIR		= $(PAPI)/lib

#	where to find include files
INCLUDE_DIR	= $(PAPI)/include

CC	= gcc
OPT	= -O0
CFLAGS	= -I$(INCLUDE_DIR)
LDFLAGS	= -L$(LIB_DIR) -static -lpapi -lm


default: timeloop

all: timeloop countloop floops

clean:
	rm -f *.o *.exe a.out timeloop countloop

timeloop: timeloop.c
	$(CC) $(CFLAGS) -O0 -m64 -o timeloop timeloop.c $(LDFLAGS)

timeloop_opt: timeloop.c
	$(CC) $(CFLAGS) -O1 -m64 -o timeloop_opt timeloop.c $(LDFLAGS)

countloop: countloop.c
	$(CC) $(CFLAGS) -O0 -o countloop countloop.c $(LDFLAGS)

list: countloop.c
	$(CC) $(CFLAGS) -O0  -g -c -fverbose-asm -Wa,-adhln countloop.c $(LDFLAGS) > countloop-o0.lst
	$(CC) $(CFLAGS) -O1  -g -c -fverbose-asm -Wa,-adhln countloop.c $(LDFLAGS) > countloop-o1.lst

countloop_opt: countloop.c
	$(CC) $(CFLAGS) -O1 -o countloop_opt countloop.c $(LDFLAGS)

floops: floops.c
	$(CC) $(CFLAGS) -o floops floops.c $(LDFLAGS)

papi-test1: papi-test1.c
	$(CC) $(CFLAGS) -o papi-test1 papi-test1.c $(LDFLAGS)
