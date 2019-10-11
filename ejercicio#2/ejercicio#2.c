/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ejercicio#2.c
 * Author: root
 *
 * Created on 10 de octubre de 2019, 09:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void piramedePascal(int vector[100],int n,int c);
int main() {
    int n,vector[0];
    vector[0]=1;
    printf("Ingresar el grado n:");
    scanf("%d",&n);
    piramedePascal(vector,n,0);
    return 0;
}
void piramedePascal(int vector[100],int n,int m){
    int aux[m+1];
    aux[0]=1;
    aux[m]=1;
    if(m<=n){

        for (int i = 1; i <m ; ++i) {
            aux[i]=vector[i-1]+vector[i];
        }
        for (int j = 0; j <=m ; ++j) {
            printf("[%i]",aux[j]);
        }
        m=m+1;
        printf("\n");
       piramedePascal(aux,n,m);
    }
}

