#ifndef __MIMORI_H__
#define __MIMORI_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char mimoriSuzuko[1029];
}Suzuko;

extern Suzuko makeMimoriSuzuko(int arg_num);
int makeKansu(char *arg_str, int arg_num);
int makeMori(char *arg_str, int arg_num);
int makeSuzuko(char *arg_str, int arg_num);

#endif // __MIMORI_H__
