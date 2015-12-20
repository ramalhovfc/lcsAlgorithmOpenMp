#ifndef cpdProject2014_structs_h
#define cpdProject2014_structs_h

struct lcs_Matrix {
	int lines;
	int cols;
	char *seqLine;
	char *seqColumn;
	int **mtx;
};
typedef struct lcs_Matrix LcsMatrix;

struct lcsResult {
	int counter;
	char *sequence;
};
typedef struct lcsResult LcsResult;

#endif
