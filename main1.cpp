#include <iostream>

using namespace std;


int matriz()
{
    int filas=10, columnas=8;
    // Crear la matriz dinámica de char
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
      matriz[i] = new char[columnas];
    }

    // Llenar la matriz con valores
    for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
        matriz[i][j] = 'A' + i + j;
      }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
        std::cout << matriz[i][j] << " ";
      }
      std::cout << std::endl;
    }

    // Liberar la memoria asignada
    for (int i = 0; i < filas; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}
