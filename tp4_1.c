#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 30

typedef struct {
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

void cargar(Tarea ** arreglo, int n);
void mostrarTarea(Tarea T);
void buscarClave(Tarea ** arreglo, int n);

int main(){

    srand(time(NULL));

    int cantTareas;
    char x;
    Tarea ** tareasPendientes;
    Tarea ** tareasRealizadas;

    printf("Ingresa la cantidad de Tareas a cargar: ");
    scanf("%d",&cantTareas);
    getchar();
    tareasPendientes = (Tarea**)malloc(sizeof(Tarea)*cantTareas);
    tareasRealizadas = (Tarea**)malloc(sizeof(Tarea)*cantTareas);

    cargar(tareasPendientes,cantTareas);

    for(int i=0;i<cantTareas;i++){
        mostrarTarea(*tareasPendientes[i]);
        printf("¿Realizo la tarea?(y/n): ");
        scanf("%c",&x);
        getchar();
        if(x=='y'){
            tareasRealizadas[i]=(Tarea*)malloc(sizeof(Tarea));
            tareasRealizadas[i]=tareasPendientes[i];
            tareasPendientes[i]=NULL;
        }
        else{
            tareasRealizadas[i]=NULL;
        }
        
    }

    printf("Tareas Realizadas\n");
    for(int i=0;i<cantTareas;i++){
        if(tareasRealizadas[i]!=NULL){
            mostrarTarea(*tareasRealizadas[i]);
        }
    }
    printf("Tareas Pendientes\n");
    for(int i=0;i<cantTareas;i++){
        if(tareasPendientes[i]!=NULL){
            mostrarTarea(*tareasPendientes[i]);
        }
    }

    buscarClave(tareasRealizadas,cantTareas);

    getchar(); //Stop
    return 0;
}

void cargar(Tarea ** arreglo, int n){
    char descripcion[MAX];
    for(int i=0;i<n;i++){
        arreglo[i] = (Tarea*)malloc(sizeof(Tarea));
        arreglo[i]->TareaID = i+1;
        printf("Igresa descripcion de la tarea: ");
        gets(descripcion);
        arreglo[i]->Descripcion = (char*)malloc(sizeof(char)*MAX);
        strcpy(arreglo[i]->Descripcion,descripcion);
        arreglo[i]->Duracion = rand()%101+10;
    }
}

void mostrarTarea(Tarea T){
    printf("ID: %d\n",T.TareaID);
    printf("%s\n",T.Descripcion);
    printf("Duracion: %d\n\n",T.Duracion);
}

void buscarClave(Tarea ** arreglo, int n){
    char clave[10];
    printf("Ingresa la palabra clave: ");
    gets(clave);
    for (int i=0; i<n; i++){
        if(arreglo[i]!=NULL && strstr((*arreglo[i]).Descripcion,clave)){
            mostrarTarea(*arreglo[i]);
        }
    }
}