CC=gcc
CFLAGS=-g 
OUTFILE=test
SOURCEFILE=proj-4.c
all:$(SOURCEFILE)
	$(CC) $(CFLAGS) $(SOURCEFILE) -o $(OUTFILE)
clean:
	rm $(OUTFILE)
