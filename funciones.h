#ifndef FUNCIONES_H
#define	FUNCIONES_H
#include "struct.h"

monomio *crear_monomio(monomio *a);
void *agregar_monomio(monomio *a,monomio b);
void acomiodar_pol(monomio *a);
monomio *leer_monomio(monomio *m);
void imprimir_monomio(monomio *a);
void borrar_monomio(monomio *m);
void menu();
monomio *simp(monomio *z);
monomio *suma_polinomio(monomio *a, monomio *b, monomio *res);
monomio *resta_polinomio(monomio *a, monomio *b, monomio *res);
monomio *mult_polinomio(monomio *a, monomio *b, monomio *res);
monomio *pol_mon(monomio *a, monomio b, monomio *res);
monomio *acomodar_pol(monomio *a, monomio *b);
monomio *pol_pol(monomio *a, monomio *res);
FILE *crear_archivo(FILE *f);
void cerrar_archivo(FILE *f);
void escribir_archivo(FILE *f, monomio *a);
#endif
