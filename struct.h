#ifndef STRUCT_H
#define	STRUCT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct monomio monomio;
struct monomio{
	float coef;
	int pot;
	monomio *sig;
};
#endif
