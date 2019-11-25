#ifndef FUNCIONES_H
#define	FUNCIONES_H
#include "polinomio.h"

monomio *crear_monomio();
polinomio *crear_polinomio();
void agregar_monomio(polinomio *p, monomio a);
void borrar_monomio(monomio *m);
void borrar_polinomio(polinomio *p);
void menu();
void leer_monomio();
polinomio suma(polinomio a, polinomio b);
polinomio resta(polinomio a, polinomio b);
polinomio multiplicacion(polinomio a, polinomio b);
polinomio division(polinomio a, polinomio b);
#endif
