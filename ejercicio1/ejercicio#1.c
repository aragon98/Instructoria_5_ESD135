#include<stdio.h>

// Cambio de base desde el 10-15

char hexCadena(int numero){
    int hexa=0;
    if(!numero)
        return;
    else {
        hexa=numero%16;
        numero=numero/16;
        hexCadena(numero);
    }
    switch(hexa){
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",hexa);
    }
}

// Conversion de hex-dec

char convertBaseB(int num, int base){
    int hexa=0;
    if(!num){
        return;
    }
    else{
        hexa=num%base;
        num=num/base;
        convertBaseB(num,base);
        printf("%d",hexa);
    }
}

void main()
{
    int n=0;
    int base;
    printf("Ingrese un número:");
    scanf("%d",&n);
    hexCadena(n);
    printf("Ingrese un número:");
    scanf("%d",&n);
    printf("Ingrese la base:");
    scanf("%d",&base);
    convertBaseB(n,base);

}