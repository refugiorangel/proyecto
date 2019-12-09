#include "funciones.h"

monomio *crear_monomio(monomio *a){
	a = (monomio*)malloc(sizeof(monomio));
	a -> coef = 0;
	a -> pot = 0;
	a -> sig = NULL;
	return a;
}

void *agregar_monomio(monomio *a,monomio b){
	monomio *nuev, *temp;
	nuev = crear_monomio(nuev);
	nuev -> coef = b.coef;
	nuev -> pot = b.pot;
	nuev -> sig = NULL;
	if( a->coef == 0 && a->pot == 0){
		a->coef = nuev->coef ;
		a->pot = nuev->pot;
	}
	else{
		temp = a;
		while(temp -> sig != NULL){
			temp = temp->sig;
		}
		temp -> sig = nuev;
	}
	return a;
}

void acomiodar_pol(monomio *a){
		
}

monomio *leer_monomio(monomio *m){
	char c;
	monomio z;
	do{
		printf("Inserta el coeficiente y la potencia del monomio\n");
		scanf("%f %d", &z.coef, &z.pot); //Lee el monomio
		agregar_monomio(m, z);		
		printf("Desea agregar mas monomios al polinomio(s/n)\n");
		setbuf(stdin,NULL);
		scanf("%c", &c);
		getchar();	
	}while(c == 'S' || c =='s');
	return m;
}

void imprimir_monomio(monomio *a){
	monomio *t;
	t = a;
	if( a == NULL){
		printf("El polinomio es NULL\n");
	}else{
		while( t != NULL){
			printf("%fx^%d", t -> coef, t -> pot);
			if ( t->sig != NULL){
				if(t->sig->coef >= 0){
					printf(" + ");
				}else{
					printf("   ");
				}
			}
			t = t -> sig;
		}
		printf("\n");
	}
}

void borrar_monomio(monomio *m){
	free(m);
	m = NULL;
}

void menu(){
	printf("\tCalculadora de polinomios\n");
	printf("(1) Agregar polinomio.\n(2) Sumar polinomios.\n(3) Restar polinomios.\n");
	printf("(4) Multiplicar polinomios.\n(5) Dividir polinomio entre monomio.\n(6) Dividir polinomio entre binomio.\n");
	printf("(7) Imprimir polinomio.\n(8) Guardar polinomios.\n(9) Salir\n");
}
	
monomio *simp(monomio *z){
	monomio *m1, *m2;
	monomio x;
	m1 = z;
	m2 = m1 ->sig;
	borrar_monomio(z);
	crear_monomio(z);
	while(m1!=NULL && m2!=NULL){
		if(m1->pot == m2->pot){
			x.coef = m1->coef + m2->coef;
			x.pot = m1->pot;
			agregar_monomio(z, x);
		}else{
			if(m1->pot != m2->pot){
				x.coef = m1->coef;
				x.pot = m1->pot;
				agregar_monomio(z, x);	
			}
		}
		m2 = m2->sig;
	}
	m1 = m1->sig;
	m2 = m1 ->sig;
    return z;
}

monomio *suma_polinomio(monomio *a, monomio *b, monomio *res){
	monomio *t1, *t2;
	monomio c;
	t1 = a;
	t2 = b;
	while(t1!=NULL && t2!=NULL){
		if(t1->pot != t2->pot){
			if(t1->pot > t2->pot){
				c.coef = t1->coef;
				c.pot = t1->pot;
				agregar_monomio(res, c);
				t1 = t1->sig;
			}else{
				if(t1->pot < t2->pot){
					c.coef = t2->coef;
					c.pot = t2->pot;
					agregar_monomio(res, c);
					t2 = t2 -> sig;
				}
			}
        }else{
        	if(t1->pot == t2->pot){
    			c.pot = t1->pot;
    			c.coef =t1->coef + t2->coef;
    			agregar_monomio(res, c);
    			t2=t2->sig;
				t1=t1->sig;
			}
		}
		if(t1!=NULL && t2==NULL){
			c.coef = t1->coef;
			c.pot = t1->pot;
			agregar_monomio(res, c);
		}else{
			if(t1==NULL && t2!=NULL){
				c.coef = t2->coef;
				c.pot = t2->pot;
				agregar_monomio(res, c);
			}
		}
	}
	return res;
}

monomio *resta_polinomio(monomio *a, monomio *b, monomio *res){
	monomio *t1, *t2;
	monomio c;
	t1 = a;
	t2 = b;
	while(t1!=NULL && t2!=NULL){
		if(t1->pot != t2->pot){
			if(t1->pot > t2->pot){
				c.coef = t1->coef;
				c.pot = t1->pot;
				agregar_monomio(res, c);
				t1 = t1->sig;
			}else{
				if(t1->pot < t2->pot){
					c.coef = -1 * t2->coef;
					c.pot = t2->pot;
					agregar_monomio(res, c);
					t2 = t2 -> sig;
				}
			}
        }else{
        	if(t1->pot == t2->pot){
    			c.pot = t1->pot;
    			c.coef =t1->coef - t2->coef;
    			agregar_monomio(res, c);
    			t2=t2->sig;
				t1=t1->sig;
			}
		}
		if(t1!=NULL && t2==NULL){
			c.coef = t1->coef;
			c.pot = t1->pot;
			agregar_monomio(res, c);
		}else{
			if(t1==NULL && t2!=NULL){
				c.coef = -1 * t2->coef;
				c.pot = t2->pot;
				agregar_monomio(res, c);
			}
		}
	}
	return res;
}

monomio *mult_polinomio(monomio *a, monomio *b, monomio *res){
	monomio *t1, *t2;
	monomio c;
	t1 = a;
	t2 = b;
	while(t1!=NULL){
		while(t2!=NULL){
			c.coef = t1->coef*t2->coef;
			c.pot = t1->pot + t2->pot;
			agregar_monomio(res, c);
			t2 = t2 -> sig;
		}
		t2 = b;
		t1 = t1->sig;
	}
	//simp(res);
	return res;
}

monomio *pol_mon(monomio *a, monomio b, monomio *res){
	monomio *t;
	monomio c;
	t = a;
	while(t!=NULL){
		c.coef = t->coef/b.coef;
		c.pot = t->pot - b.pot;
		agregar_monomio(res, c);
		t=t->sig;
	}
	return res;
}

monomio *acomodar_pol(monomio *a, monomio *b){
	monomio *t;
	monomio c;
	int grado;
	t=a;
	grado=t->pot;
	while(t!=NULL){
		if(grado==t->pot){
			c.coef=t->coef;
			c.pot=t->pot;
			t=t->sig;
			agregar_monomio(b, c);
		}else{
			c.coef=0.00;
			c.pot=grado;
			agregar_monomio(b, c);
		}
		grado=grado-1;
	}
	return b;
}

monomio *pol_pol(monomio *a, monomio *res){
	float dep;
	int ind;
	monomio *t;
	monomio c, temp;
	t=a;
	printf("Ingrese el término dependiente e independiente\n");
	scanf("%f %d", &dep, &ind);
	while(t->sig!=NULL){
		c.coef=t->coef/dep;
		c.pot=t->pot-1;
		agregar_monomio(res, c);
		temp.coef=c.coef*ind;
		t->sig->coef=t->sig->coef-temp.coef;
		t=t->sig;
	}
	printf("El residuo es %f\n", t->coef);
	return res;
}

FILE *crear_archivo(FILE *f){
	f=fopen("historial.txt", "a");
	if (f != NULL) {
		printf("creado (ABIERTO)\n");
	}else{
		printf("Error (NO ABIERTO)\n");;
	}
	return f;
}

void cerrar_archivo(FILE *f){
	fclose(f);
}

void escribir_archivo(FILE *f, monomio *a){
	monomio *t;
	t=a;
	if( a == NULL){
		printf("El polinomio es NULL\n");
	}else{
		while(t!=NULL){
			fprintf(f, "%fx^%d", t -> coef, t -> pot);
			if( t->sig != NULL){
				if(t->sig->coef >= 0){
					fprintf(f, " + ");
				}else{
					fprintf(f, "   ");
				}
			}
			t = t -> sig;
		}
	}
}
