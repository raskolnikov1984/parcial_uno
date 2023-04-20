#include <iostream>
#include "Funciones.h"
using namespace std;

int main()
{
    char*** cronograma1;
    char** materiasDisponibles;
    char** AUXmateriasDisponibles;

    int opcion = mostrarMenu();
    while(opcion!= 0)
    {
        materiasDisponibles = MateriasDisponibles();
        switch (opcion)
        {
        case 1:{
            registrarCursos();
            break;}
        case 2:{
            cronograma1 = cronograma();
            break;}
        case 3:{
            ImprimirMateriasHorarios();
            break;
        }
        case 4:{
            //imprimir la matriz
            cout<<"Códigos de Materias Disponibles: "<<endl;
            /* TODO: Volver una función para imprimir matrizes.*/
            imprimirMatriz(materiasDisponibles);
            break;
        }
        case 5:{
            cout<<*(HorariosDisponibles(2536302));
            //materiasDisponibles = MateriasDisponibles();
            //Matricular(cronograma1, materiasDisponibles, AUXmateriasDisponibles);
            break;
        }
        case 6:{
            imprimirRecomendacionesEstudio();
            break;
        }
        default:
            cout<<"opcion no valida"<<endl;
        }
        opcion = mostrarMenu();
        //materiasDisponibles = MateriasDisponibles();
    }
    return 0;
}
