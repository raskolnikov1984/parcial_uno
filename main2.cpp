#include <iostream>

using namespace std;
enum DiaSemana { Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo };

int main() {
  DiaSemana dia = Lunes;

  cout << "¿Qué día es hoy? ";
  cin >> dia;

  switch (dia) {
    case Lunes:
      std::cout << "Hoy es lunes." << std::endl;
      break;
    case Martes:
      std::cout << "Hoy es martes." << std::endl;
      break;
    case Miercoles:
      std::cout << "Hoy es miércoles." << std::endl;
      break;
    case Jueves:
      std::cout << "Hoy es jueves." << std::endl;
      break;
    case Viernes:
      std::cout << "Hoy es viernes." << std::endl;
      break;
    case Sabado:
      std::cout << "Hoy es sábado." << std::endl;
      break;
    case Domingo:
      std::cout << "Hoy es domingo." << std::endl;
      break;
    default:
      std::cout << "Ese no es un día de la semana válido." << std::endl;
      break;
  }

  return 0;
}
