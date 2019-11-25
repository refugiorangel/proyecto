
polinomio *crear_polinomio(){
    polinomio *p;
    p=(polinomio*)malloc(sizeof(polinomio));
    p->primero=NULL;
    p->num=0;
    return p;
}

monomio *crear_monomio(){
    monomio *m;
    m=(monomio*)malloc(sizeof(monomio));
    m->sig=NULL;
    m->coef=0;
    m->pot=0;
    return m;
}

void agregar_monomio(polinomio *p, monomio a){
    if(p==NULL){
    	p=crear_polinomio();
	p->primero=crear_monomio(a);
    }else{
        if(p->primero==NULL){
            p->primero=crear_monomio(a);
        }else{
            monomio *t=p->primero;
            while(t->sig!=NULL){
                t=t->sig;
            }
            t->sig=crear_monomio(a);
        }
        p->num++;
    }
}

void borrar_monomio(monomio *m){
    if(m->sig!=NULL){
    	borrar_monomio(m->sig);
    }
    free(m);
}

void borrar_polinomio(polinomio *p){
    borrar_monomio(p->primero);
    free(p);
}

void leer_monomio(){
	
}

polinomio suma(polinomio a, polinomio b){
    
}

polinomio resta(polinomio a, polinomio b){
    
}

polinomio multiplicacion(polinomio a, polinomio b){
    
}

polinomio division(polinomio a, polinomio b){
    
}
