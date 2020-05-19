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

typedef struct node{
    Tarea T;
    struct node * siguiente;
}Nodo;

void cargarNodo(Nodo **Lista, int ID);
void cargarTareas(Nodo ** Lista, int n);
void mostrarTarea(Tarea T);
void mostrarLista(Nodo * Lista);

int main(){

    int cantTareas;
    Nodo * listaPendientes = NULL;
    Nodo * listaRealizadas = NULL;

    printf("Ingresa la cantidad de Tareas a cargar: ");
    scanf("%d",&cantTareas);
    getchar();

    cargarTareas(&listaPendientes,cantTareas);
    mostrarLista(listaPendientes);

    getchar(); //Stop
    return 0;
}

void cargarNodo(Nodo **Lista, int ID){
    Nodo * aux = (Nodo*)malloc(sizeof(Nodo));
    char descripcion[MAX];
    printf("Ingresa una descripcion de la tarea: ");
    gets(descripcion);
    aux->T.Descripcion = (char*)malloc(sizeof(char)*MAX);
    strcpy(aux->T.Descripcion,descripcion);
    aux->T.TareaID = ID;
    aux->T.Duracion = rand()%91+10;
    if (*Lista==NULL){
        *Lista = aux;
    }
    else{
        Nodo * Laux = *Lista;
        while (Laux->siguiente!=NULL){
            Laux = Laux->siguiente;
        }
        Laux->siguiente=aux;
    }
}

void cargarTareas(Nodo ** Lista, int n){
    for (int i=0;i<n;i++){
        cargarNodo(Lista,i+1);
    }
}

void mostrarTarea(Tarea T){
    printf("ID: %d\n",T.TareaID);
    printf("%s\n",T.Descripcion);
    printf("Duracion: %d\n\n",T.Duracion);
}

void mostrarLista(Nodo * Lista){
    if(Lista!=NULL){
        while (Lista->siguiente!=NULL){
            mostrarTarea(Lista->T);
            Lista=Lista->siguiente;
        }
    }
}