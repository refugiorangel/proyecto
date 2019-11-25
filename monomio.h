#ifndef MONOMIO_H
#define	MONOMIO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _monomio monomio;
struct _monomio{
    int coef;
    int pot;
    monomio *sig;
};
#endif
