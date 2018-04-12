CC=gcc
CFLAGS=-g 
OUTFILE=test
SOURCEFILE=proj-4t.c
all:$(SOURCEFILE)
	$(CC) $(CFLAGS) $(SOURCEFILE) -o $(OUTFILE)
clean:
	rm $(OUTFILE)
