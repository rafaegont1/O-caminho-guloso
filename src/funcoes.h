#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

typedef struct movement Mov;

unsigned short greedyAlg(unsigned short mat_sz, unsigned short *mat);
void joystick(unsigned short *i, unsigned short *j, char dir);
void printMat(unsigned short mat_sz, unsigned short *mat);

#endif
