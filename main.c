#include "funciones.c"
int main() {
    polinomio a, b;
    polinomio c;
    int op;
    menu();
    do{
        scanf("%d", &op);
        switch (op){
            case 1:
                c=suma(a,b);
                break;
            case 2:
                c=resta(a,b);
                break;
            case 3:
                c=multiplicacion(a,b);
                break;
            case 4:
                c=division(a,b);
                break;
            default:
                printf("Esta opción no es válida\n");
                break;
        }
    }while(op!=5);
    return 0;
}
