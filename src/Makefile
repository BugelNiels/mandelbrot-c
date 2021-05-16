CC=gcc
CFLAGS=-I. -Wall -pedantic -O3 -lm -fopenmp
DEPS = util.h interaction.h mandelbrot.h
OBJ = util.o interaction.o mandelbrot.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mandelbrot: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 