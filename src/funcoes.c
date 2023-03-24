#include "funcoes.h"

	typedef struct movement {
		char dir;
	short max;
} Mov;

unsigned short greedyAlg(unsigned short mat_sz, unsigned short *mat) {
	unsigned short i = 0, j = 0, offset = mat_sz * i + j, res = mat[offset];

	while(i + 1 != mat_sz) {
    // (c) saltar para a linha de baixo
		struct movement mov = (Mov){.dir = 'd', .max = mat[mat_sz * (i + 1) + j]};

    if(j != 0) {
      // (b) retroceder para coluna anterior
			offset = mat_sz * i + j - 1;
      if(mat[offset] > mov.max) mov = (Mov){.dir = 'l', .max = mat[offset]};

      // (d) ir em diagonal para baixo (/)
			offset = mat_sz * (i + 1) + j - 1;
      if(mat[offset] > mov.max) mov = (Mov){.dir = '/', .max = mat[offset]};
    }

    if(j + 1 != mat_sz) {
      // (a) avançar para a próxima coluna
			offset = mat_sz * i + j + 1;
      if(mat[offset] > mov.max) mov = (Mov){.dir = 'r', .max = mat[offset]};

      // (d) ir em diagonal para baixo (\)
			offset = mat_sz * (i + 1) + j + 1;
      if(mat[offset] > mov.max) mov = (Mov){.dir = '\\', .max = mat[offset]};
    }

		mat[mat_sz * i + j] = 0;
		joystick(&i, &j, mov.dir);
		offset = mat_sz * i + j;
		res += mat[offset];
	}

	while(j + 1 != mat_sz) {
		offset = mat_sz * i + (j = j + 1);
		res += mat[offset];
		mat[mat_sz * i + j] = 0;
	}

	return res;
}

void joystick(unsigned short *i, unsigned short *j, char dir) {
	switch(dir) {
		case 'r':
			++*j;
			break;
		case 'l':
			--*j;
			break;
		case 'd':
			++*i;
			break;
		case '\\':
			++*i;
			++*j;
			break;
		case '/':
			++*i;
			--*j;
			break;
	}
}

void printMat(unsigned short mat_sz, unsigned short *mat) {
	for(int i = 0; i < mat_sz; i++) {
		for(int j = 0; j < mat_sz; j++) {
			printf("%d\t", mat[mat_sz * i + j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
