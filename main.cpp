#include "Funciones.h"

int main(){
    char*** cronograma1;
    char** materiasDisponibles;
    int opcion = mostrarMenu();

    cout<<"Actualmente su cronograma se encuentra Asi"<<endl;
    while(opcion!= 0){
        materiasDisponibles = MateriasDisponibles();
        switch (opcion)
        {
        case 1:{
            registrarCursos();
            break;}
        case 2:{
            ImprimirMateriasHorarios();
            break;}
        case 3:{
            cout<<"Códigos de Materias Disponibles: "<<endl;
            /* TODO:
             * Volver una función para imprimir matrizes.*/
            imprimirMatriz(materiasDisponibles);
            break;}
        case 4:{
            cout<<"Actualmente su cronograma se encuentra Asi"<<endl;
            cronograma1 = cronograma();
            Matricular(cronograma1, materiasDisponibles);
            break;}
        case 5:{
            mostrarRecomendaciones();
            break;}
        default:
            cout<<"opcion no valida"<<endl;}
        opcion = mostrarMenu();
    }return 0;
}
