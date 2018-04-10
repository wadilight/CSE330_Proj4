CC=gcc
CFLAGS=-g 
OUTFILE=thread_test
SOURCEFILE=proj-3.c
all:$(SOURCEFILE)
	$(CC) $(CFLAGS) $(SOURCEFILE) -o $(OUTFILE)
clean:
	rm $(OUTFILE)
