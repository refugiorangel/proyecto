#ifndef POLINOMIO_H
#define	POLINOMIO_H
#include "monomio.h"

typedef struct _polinomio polinomio;
struct _polinomio{
	monomio *primero;
	int num;
};
#endif
