/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ejercicio4.c
 * Author: root
 *
 * Created on 10 de octubre de 2019, 09:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanio 25
#define numero 100                               //Numero de cuadros


/*
 * 
 */

int iteracion;
int columna= tamanio-1,fila= tamanio-1;
int opt  = (tamanio*tamanio+1);                 //Para tomar una mejor ruta


void llenartab(int array[][tamanio])
{
    int t,i;
    for (t=0; t<tamanio; t++)
    {
        for (i=0; i<tamanio; i++)
        {array[t][i] = 0;}
    }
}

void mostrar(int array[][tamanio])
{
    int t,i;

    for (i=0; i<tamanio; i++)
    {
        for (t=0; t<tamanio; t++)
        {printf(" %2d |",array[t][i]);}
        printf("\n\n");
    }
}

void diseno(int array[][tamanio])
{
    int i,t;
    for (i=0; i<tamanio*3+2; i++)
        printf("%c",205);
    printf("\n%c",186);
    for (i=0; i<tamanio; i++)
    {
        for (t=0; t<tamanio; t++)
        {
            if (array[t][i] == -1)
                printf("%c%c%c",219,219,219);
            if (array[t][i] == 0)
                printf("   ");
            if (array[t][i] != 0 && array[t][i] != -1)
                printf(" %c ",15);


        }
        printf("%c\n%c",186,186);
    }
    for (i=0; i<tamanio*3+1; i++)
        printf("%c",205);
}

void aleatorio(int array[][tamanio])
{
    int i, x, y;
    srand(time(NULL));
    for (i=0; i<numero; i++)
    {
        x = rand()%tamanio;
        y = rand()%tamanio;
        if(x != columna || y != fila)
            array[x][y] = -1;

    }
}//aleatorio

void cambio(int antes[][tamanio], int despues[][tamanio])
{
    int t,i;
    for (i=0; i<tamanio; i++)
    {
        for (t=0; t<tamanio; t++)
        {
            despues[t][i] = antes[t][i];
        }
    }
}

void recursividad(int tab[][tamanio], int tab_aux[][tamanio],int casilla, int x, int y)
{
    int arrx[]={1,0,-1,0};
    int arry[]={0,1,0,-1};

    int inicio = 0;
    int variablex, variabley;

    while(inicio <= 3)
    {
        variablex= x+arrx[inicio];
        variabley= y+arry[inicio];


        if ((tab[variablex][variabley] == 0) && (variablex < tamanio&& variablex >= 0 && variabley < tamanio&& variabley >= 0)&& (casilla < opt))
        {

            tab[variablex][variabley] = casilla;

            if (columna == variablex && fila == variabley)//Resolviendo....
            {

                diseno(tab);


                if (casilla < opt)//Opta por la ruta optima.
                {
                    cambio(tab,tab_aux);
                    opt = casilla;
                }
            }

            recursividad(tab,tab_aux,casilla+1,variablex,variabley);
        }
        inicio+=1;
        iteracion = iteracion + 1;
    }
    tab[x][y]= 0;
}


int main()
{
    int tablero[tamanio][tamanio];
    int tablero_aux[tamanio][tamanio];
    int t,i;
    llenartab(tablero);
    llenartab(tablero_aux);
    aleatorio(tablero);
    printf("\n   ___________________________|||Laberinto|||_____________________________\n");
    diseno(tablero);
    printf("\n-COLUMNA Y FILA-\n");
    scanf("%d%d",&t,&i);
    tablero[t][i]=1;
    recursividad(tablero,tablero_aux,2,t,i);
    diseno(tablero_aux);

    return 0;
}