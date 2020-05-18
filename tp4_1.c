#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

int main(){

    int cantTareas;

    printf("Ingresa la cantidad de Tareas a cargar:");
    scanf("%d",cantTareas);


    getchar(); //Stop
    return 0;
}