#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

void cargar(Tarea ** arreglo, int n);

int main(){

    srand(time(NULL));

    int cantTareas;
    Tarea ** tareasPendientes;
    Tarea ** tareasRealizadas;

    printf("Ingresa la cantidad de Tareas a cargar: ");
    scanf("%d",cantTareas);
    getchar();
    tareasPendientes = (Tarea**)malloc(sizeof(Tarea)*cantTareas);
    tareasRealizadas = (Tarea**)malloc(sizeof(Tarea)*cantTareas);


    printf("\nOK");
    getchar(); //Stop
    return 0;
}

void cargar(Tarea ** arreglo, int n){
    char descripcion[30];
    for(int i=0;i<n;i++){
        (*(arreglo+i))->TareaID = i+1;
        printf("Igresa descripcion de la tarea: ");
        gets(descripcion);
        (*(arreglo+i))->Descripcion = (char*)malloc(sizeof(char)*30);
        (*(arreglo+i))->Descripcion = descripcion;
        (*(arreglo+i))->Duracion = rand()%101+10;
    }
}