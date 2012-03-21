####################################################
#
#  ISA 563, Spring 2012
#  Chris Brahms
#
####################################################

# macros

COND := $(shell type clang &> /dev/null && echo $$?)

ifeq ($(COND), 0)
  CC=clang
else
  CC=gcc
endif

CFLAGS=-g -Wall

PROG=shell
# targets

${PROG}: ${PROG}.c string_utils
	$(CC) $(CFLAGS) -o ${PROG} ${PROG}.c string_utils.o 

string_utils: string_utils.c
	$(CC) $(CFLAGS) -c string_utils.c
	
clean:
	rm -rf $(PROG) *.o *.dSYM 
	
