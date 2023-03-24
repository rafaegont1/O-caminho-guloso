#include "matrix.h"
#include <stdlib.h>

int main() {
	unsigned short *mat, mat_sz, n = 1, global_sum = 0, local_sum = 0;
	FILE *fp = fopen("dataset/input.data", "r");

	if(fp == NULL) {
		puts("Erro ao tentar abrir o arquivo");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%hu %*s\n", &mat_sz);

	mat = (unsigned short *)malloc(mat_sz * mat_sz * sizeof(unsigned short));

	while(!feof(fp)) {
		for(int i = 0; i < mat_sz; i++) {
			for(int j = 0; j < mat_sz; j++) {
				fscanf(fp, "%hu ", mat + mat_sz * i + j);
			}
		}
		printf("------------------Matriz número %hu------------------\n\n", n++);
		printMat(mat_sz, mat);
		global_sum += local_sum = greedyAlg(mat_sz, mat);
		printMat(mat_sz, mat);
		printf("Resultado local: %hu\n\n", local_sum);
	}

	printf("===================================================\n\n"
			"Resultado global: %hu\n", global_sum);

	free(mat);
	fclose(fp);

	return 0;
}

