CC = gcc
CFLAGS = -g -fopenmp -lm 
OBJS = lcs-omp.o lcsAlgorithm.o readFileUtils.o utils.o

lcs-omp: $(OBJS)
	$(CC) $(CFLAGS) -o lcs-omp $(OBJS)

lcs-omp.o: lcs-omp.c structs.h readFileUtils.h readFileUtils.c lcsAlgorithm.h lcsAlgorithm.c utils.h utils.c
	$(CC) $(CFLAGS) -c lcs-omp.c

lcsAlgorithm.o: structs.h utils.h utils.c
	$(CC) $(CFLAGS) -c lcsAlgorithm.c

readFileUtils.o: structs.h utils.h utils.c
	$(CC) $(CFLAGS) -c readFileUtils.c

utils.o: structs.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o *~ lcs-omp lcsAlgorithm readFileUtils utils
