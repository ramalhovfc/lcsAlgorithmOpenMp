#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "structs.h"
#include "readFileUtils.h"
#include "lcsAlgorithm.h"
#include "utils.h"

int main(int argc, const char *argv[]) {

	FILE *fp;
	LcsMatrix *lcsMtx;
	LcsResult result;

	double start, time;			//obter o tempo que demora a executar a função
	start = omp_get_wtime();

	if (argc != 2) {
		printf("Wrong number of arguments\n");
		printf("Usage: %s <input_file>\n", argv[0]);
		return 0;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Error openning file %s\n", argv[1]);
		return -1;
	}

	lcsMtx = readFile(fp);	//função que reserva a memória e copia as strings para duas strings na estrutura de dados

	fillMatrix(lcsMtx); //função que constroi a matrix

	result = findLongestCommonSubsequence(lcsMtx); //usa a matriz e as duas strings para obter a sequencia procurada

	time = omp_get_wtime() - start;
	printf("Execution time:%f\n", time);
	
	printf("%d\n", result.counter);
	printf("%s\n", result.sequence);

	fclose(fp);
	free_memory(lcsMtx, result);
	
	return 0;
}

