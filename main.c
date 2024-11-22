#include <stdio.h>
#include <math.h>
#include "funciones.h"
#include <string.h>

int main (int argc, char *argv[]) {
    int i=0, opc, k, u,p,j=0;
     printf("Cuantos tipos de teléfono deseas agregar\n");
    fflush(stdin);
    scanf("%d", &p);
    while (p<0){
                printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                scanf("%d",&p);
        }
    
    char producto[p][40];
    float tiempo[p], recursos[p], demanda[p], cantidad = 0;
    char palabra_a_buscar[40];
    char palabra_eliminar[21]="Componente eliminado";
    float tiempoL = 0, recursosL = 0, tiempoT, recursosT;

    printf("¿Cuál es la cantidad de horas/máquina con las que cuentas?\n");
    fflush(stdin);
    scanf("%f", &tiempoL);
     while (tiempoL<0){
                printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                scanf("%f", &tiempoL);
        }
    printf("¿Cuál es la cantidad de microchips con los que cuentas?\n");
    fflush(stdin);
    scanf("%f", &recursosL);
     while (recursosL<0){
                printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                scanf("%f",&recursosL);
        }

    printf("¿Qué deseas hacer?\n0. Terminar el programa\n1.Ingresar los productos\n2. Editar el nombre de un producto\n3. Eliminar un producto\n4. Cambiar el horas/maquina que necesita un producto\n5. Cambiar la cantidad de microchips que necesita un producto\n6. Calcular para una orden de producto\n");
    fflush(stdin);
    scanf("%d", &opc);
    while (opc<0){
                printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                scanf("%d",&opc);
        }
    fflush(stdin);

    while (opc != 0) {
            printf("%d", opc);
        switch (opc) {
            case 1:
            printf("ingresa tus productos\n");
            for (int i = 0; i < p; i++) {
                    Nproductos(producto, i);
                    Tiempo(tiempo, i);
                     while (tiempo[i]<0){
                            printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                            scanf("%f", &tiempo[i]);
                    }
                    Recursos(recursos, i);
                     while (recursos[i]<0){
                            printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                            scanf("%f",&recursos[i]);
                 }
                }
                    printf("tu nueva tabla es:\n");
                    printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                    for (int j = 0; j < p; j++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[j], tiempo[j], recursos[j]);
                }
            break;
            case 2:
                printf("¿Qué número de producto deseas cambiar?\n");
                fflush(stdin);
                scanf("%d", &k);
                while (k<0){
                    printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                    scanf("%d",&k);
                }
                getchar();
                k = k - 1;
                Nproductos(producto, k);
                printf("Tu nueva tabla es:\n");
                printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                for (int i = 0; i < p; i++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[i], tiempo[i], recursos[i]);
                }
                break;

            case 3:
                printf("¿Qué producto deseas eliminar?\n");
                fflush(stdin);
                fgets(palabra_a_buscar, 40, stdin);
                palabra_a_buscar[strlen(&palabra_a_buscar[0])- 1] = '\0';
                int eliminado = 0;
                for (int i = 0; i < p; i++) {
                    if (strcmp(producto[i], palabra_a_buscar)== 0) {
                        strcpy(producto[i], palabra_eliminar);
                        eliminado = 1;  
                        
                 }
             }
    
                if (!eliminado) {
                    printf("El producto no se encontró en la lista.\n");
             }

                printf("Tu nueva tabla es:\n");
                printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                for (int i = 0; i < p; i++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[i], tiempo[i], recursos[i]);
                }
             break;


            case 4:
                printf("¿Qué número de producto deseas cambiar el tiempo?\n");
                fflush(stdin);
                scanf("%d", &k);
                while (k<0){
                    printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                    scanf("%d",&k);
                }
                getchar();
                k = k - 1;
                Tiempo(tiempo, k);
                printf("Tu nueva tabla es:\n");
                printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                for (int i = 0; i < p; i++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[i], tiempo[i], recursos[i]);
                }
                break;

            case 5:
                printf("¿Qué número de producto deseas cambiar la cantidad de recursos?\n");
                fflush(stdin);
                scanf("%d", &k);
                while (k<0){
                    printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                    scanf("%d",&k);
                }
                getchar();
                k = k - 1;
                Recursos(recursos, k);
                printf("Tu nueva tabla es:\n");
                printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                for (int i = 0; i < p; i++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[i], tiempo[i], recursos[i]);
                }
                break;

            case 6:
                printf("¿Qué producto desea el comprador?\n");
                fflush(stdin);
                fgets(palabra_a_buscar, 40, stdin);
                palabra_a_buscar[strlen(&palabra_a_buscar[0])- 1] = '\0';
                int encontrado = 0;  
                for (int i = 0; i < p; i++) {
                if (strcmp(producto[i], palabra_a_buscar) == 0) {
                u = i;  
                encontrado = 1;  
                printf("¿Qué cantidad de producto requiere el comprador?\n");
                scanf("%f", &cantidad);
                 while (cantidad<0){
                    printf("El valor que ingresas tiene que ser mayor a 0\n Intentalo de nuevo\n");
                    scanf("%f",&cantidad);
                }
                tiempoT = cantidad * tiempo[u];
                recursosT = cantidad * recursos[u];
                if (tiempoT > tiempoL || recursosT > recursosL) {
                printf("Te has agotado los recursos o el tiempo que tiene la fábrica para funcionar :(\n");
                } else if (tiempoT > 0 && recursosT > 0) {
                tiempoL -= tiempoT;
                recursosL -= recursosT;
                printf("La orden fue procesada correctamente.\n");
                        }
                    }
                }
    
                if (!encontrado) {
                    printf("El producto no se encontró en la lista.\n");
                }

                printf("Tu nueva tabla es:\n");
                printf("Tiempo Total\t Recursos Totales\n %2.f\t %2.f\t\n", tiempoL,recursosL);
                for (int i = 0; i < p; i++) {
                    printf("Producto\tTiempo\tRecursos\n %s\t\t%.2f\t %.2f\t \n", producto[i], tiempo[i], recursos[i]);
                }
                break;

            default:
                printf("La opción que escogiste no existe\n");
                break;
        }

        printf("¿Qué deseas hacer?\n0. Terminar el programa\n1.Ingresar los productos\n2. Editar el nombre de un producto\n3. Eliminar un producto\n4. Cambiar el horas/maquina que necesita un producto\n5. Cambiar la cantidad de microchips que necesita un producto\n6. Calcular para una orden de producto\n");
        scanf("%d", &opc);
        getchar();
    }

    return 0;
}
