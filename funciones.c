#include <stdio.h>
#include <math.h>
#include "funciones.h"
#include <string.h>

void Nproductos (char producto[5][40], int i){
        printf("por favor, digita el nombre del producto númeo %d:\n",i+1);
        fgets(producto[i], 40, stdin);
        producto[i][strlen(&producto[i][0]) - 1] = '\0';

}
void Tiempo (float tiempo[5], int i){
        printf("por favor, digita el tiempo que toma hacer el producto %d en horas:\n",i+1);
       scanf("%f",&tiempo[i]);
       while (tiempo[i]<0){
        printf("el tiempo que ingresaste no es correcto, por favor intentalo de nuevo \n");
        scanf("%f",&tiempo[i]);
       }
       getchar();
}
void Recursos (float recursos[5], int i){
        printf("por favor, digita la cantidad de recursos que se necesita para hacer el producto %d:\n",i+1);
       scanf("%f",&recursos[i]);
        while (recursos[i]<0){
        printf("los recursos que ingresaste no son correctos, por favor intentalo de nuevo \n");
        scanf("%f",&recursos[i]);
       }
       getchar();
}
void Demanda (float demanda[5], int i){
        printf("por favor, digita la demanda que tiene el producto %d en unidades:\n",i+1);
       scanf("%f",&demanda[i]);
        while (demanda[i]<0){
        printf("la demanda que ingresaste no es correcta, por favor intentalo de nuevo \n");
        scanf("%f",&demanda[i]);
       }
       getchar();
}

