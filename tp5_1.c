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

Tarea crearTarea(int ID);
Nodo * crearNodo(int ID);
void mostrarTarea(Tarea T);
void agregarALista(Nodo **L,Nodo*N);
void mostrarLista(Nodo *Lista);
Nodo * quitarNodo(Nodo **Lista);
Nodo * buscarID(Nodo *L,int ID);
Nodo * buscarClave(Nodo *L, char *clave);


int main(){

    int cantTareas;
    char x;
    char clave[]="hola";
    Nodo * listaPendientes = NULL;
    Nodo * listaRealizadas = NULL;
    Nodo * listaAux = NULL;
    Nodo * encontrado;

    printf("Ingresa la cantidad de Tareas a cargar: ");
    scanf("%d",&cantTareas);
    getchar();

    for (int i=0;i<cantTareas;i++){
        Nodo * Aux = crearNodo(i+1);
        agregarALista(&listaPendientes,Aux);
    }

    mostrarLista(listaPendientes);

    for (int i=0;i<cantTareas;i++){
        mostrarTarea(listaPendientes->T);
        printf("Realizo esta tarea?(y/n): ");
        scanf("%c",&x);
        getchar();
        if (x=='y'){
            agregarALista(&listaRealizadas,quitarNodo(&listaPendientes));
        }
        else{
            agregarALista(&listaAux,quitarNodo(&listaPendientes));
        }
    }
    listaPendientes = listaAux;

    printf("Pendientes\n");
    mostrarLista(listaPendientes);
    printf("-------------\n");
    printf("Realizadas\n");
    mostrarLista(listaRealizadas);
    printf("-------------\n");

    encontrado = buscarID(listaPendientes,1);
    mostrarTarea(encontrado->T);
    encontrado = buscarClave(listaPendientes,clave);
    mostrarTarea(encontrado->T);

    getchar(); //Stop
    return 0;
}

Tarea crearTarea(int ID){
    char descripcion[MAX];
    Tarea T;
    T.TareaID = ID;
    T.Duracion = rand()%91+10;
    printf("Igresa descripcion de la tarea: ");
    gets(descripcion);
    T.Descripcion = (char*)malloc(sizeof(char)*MAX);
    strcpy(T.Descripcion,descripcion);
    return T;
}

Nodo * crearNodo(int ID){
    Nodo * N=(Nodo*)malloc(sizeof(Nodo));
    N->T=crearTarea(ID);
    N->siguiente=NULL;
    return N;
}

void agregarALista(Nodo **L,Nodo*N){
    N->siguiente = *L;
    *L=N;
}

void mostrarTarea(Tarea T){
    printf("ID: %d\n",T.TareaID);
    printf("%s\n",T.Descripcion);
    printf("Duracion: %d\n\n",T.Duracion);
}

void mostrarLista(Nodo *Lista){
    while(Lista!=NULL){
        mostrarTarea(Lista->T);
        Lista=Lista->siguiente;
    }
}

Nodo * quitarNodo(Nodo **Lista){
    Nodo * Aux = *Lista;
    *Lista = (*Lista)->siguiente;
    Aux->siguiente = NULL;
    return Aux;
}

Nodo * buscarID(Nodo *L,int ID){
    while(L!=NULL){
        if (L->T.TareaID==ID){
            return L;
        }
        L = L->siguiente;
    }
    return NULL;
}
Nodo * buscarClave(Nodo *L, char *clave){
    while(L!=NULL){
        if (strstr(L->T.Descripcion,clave)){
            return L;
        }
        L = L->siguiente;
    }
    return NULL;
}