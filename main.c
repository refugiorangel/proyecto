#include  "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int op;
	monomio *x, *res;
	monomio *p = NULL;
	monomio *q = NULL;	
	int c;
	FILE *f;
	crear_archivo(f);
	x= crear_monomio(x);
	res = crear_monomio(res);
	do{	
		menu();
		printf("Ingrese la opción que desea realizar\n");
		scanf("%d", &op);	
		switch(op){
			case 1: //Agregar polinomio				
				if( p == NULL){
					p = crear_monomio(p);
					leer_monomio(p);
					imprimir_monomio(p);
					
				}else{
					q = crear_monomio(q);
					leer_monomio(q);
				}
				break;
			case 2: //Suma			
				suma_polinomio(p, q, res);
				imprimir_monomio(res);
				break;
			case 3: //Resta
				resta_polinomio(p, q, res);
				imprimir_monomio(res);
				break;
			case 4: //Multiplicacion
				mult_polinomio(p, q, res);
				imprimir_monomio(res);
				break;
			case 5: //Division (Polinomio entre monomio)
				printf("¿Qué polinomio desea dividir?\n1 o 2\n");
				scanf("%d", &c);
				monomio a;
				if( c == 1){
					if( p != NULL){
						printf("ingresa el monomio\n");
						scanf("%f %d", &a.coef, &a.pot);
						pol_mon(p, a, res);
					}else
						printf("No existe el polinomio %d\n", c);
				}else{
					if( q != NULL){ 
						printf("ingresa el monomio\n");
						scanf("%f %d", &a.coef, &a.pot);
						pol_mon(q, a, res);
					}else
						printf("No existe el polinomio %d\n", c);
				}
				imprimir_monomio(res);
				break;
			case 6: //Division (Polinomio entre binomio)
				printf("¿Qué polinomio desea dividir?\n1 o 2\n");
				scanf("%d", &c);
				if( c == 1){
					if( p != NULL){
						acomodar_pol(p, x);
						pol_pol(x, res);
					}else
						printf("No existe el polinomio %d\n", c);
				}else{
					if( q != NULL){
						acomodar_pol(q, x);
						pol_pol(x, res);
					}else
						printf("No existe el polinomio %d\n", c);
				}
				imprimir_monomio(res);
				break;
			case 7: //Imprimir polinomio
				printf("¿Que polinomio quiere cargar?\n1 o 2\n");
				scanf("%d", &c);
				if( c == 1){
					if( p != NULL){
						imprimir_monomio(p);
					}else{
						printf("No existe el polinomio %d\n", c);
					}
				}else{
					if( q != NULL){ 
						imprimir_monomio(q);
					}else{
						printf("No existe el polinomio %d\n", c);				
					}
				}
				break;
			case 8: //Guardar polinomio
				printf("¿Que polinomio quiere guardar?\n1 o 2\n");
				scanf("%d", &c);
				if( c == 1){
					if( p != NULL){
						escribir_archivo(f, p);
					}else{
						printf("No existe el polinomio %d\n", c);
					}
				}else{
					if( q != NULL){ 
						escribir_archivo(f, q);
					}else{
						printf("No existe el polinomio %d\n", c);				
					}
				}
				break;
			case 9: //Salir
				break;
			default:
				printf("Esta opción es inválida\n");
				break;
		} 
	}while(op != 9);
	cerrar_archivo(f);
	borrar_monomio(x);
	borrar_monomio(res);
	borrar_monomio(p);
	borrar_monomio(q);
	return 0;
}
