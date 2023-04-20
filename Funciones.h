#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

char* enteroAChar(int numero);
int mostrarMenu();
int asignarHorarios();
int registrarHorarios(int codigo);
int registrarCursos();
char*** cronograma();
char** MateriasDisponibles();
void ImprimirMateriasHorarios();
void imprimirRecomendacionesEstudio();
void Matricular(char*** cronograma, char** materiasDisponibles);
void search_by_code(char* filename, int code);

/* TODO: Limpiar casa y revisar estrategias.
 * TODO: Realizar pruebas registrar cursos
 *       codigo: solo acepte números.
 * TODO: Revisar Mensaje para imprimir horarios.
 */

int mostrarMenu(){
    int opcion;
    do {
        // Imprimir el menú
        cout<<"\t\t.................\n";
        cout<<"\t\t| MENÚ PRINCIPAL |\n";
        cout<<"\t\t................."<<endl;
        cout<<"\t1. Para registrar cursos #1."<<endl;
        cout<<"\t2. Para registrar horarios #2."<<endl;
        cout<<"\t3. Ver Horarios y Materias #3."<<endl;
        cout<<"\t4. Ver codígos disponibles #4"<<endl;
        cout<<"\t5. Matricular #5"<<endl;

        cout<<"\t6. Ver Recomendaciones de Estuido"<<endl;
        cout << "Seleccione una opción (0-5): ";

        // Leer la opción seleccionada por el usuario
        cin >> opcion;

        // Validar la opción ingresada
        if (opcion < 0 || opcion > 6) {
            cout << "Opción inválida. Por favor, seleccione una opción del 0 al 4." << endl;
        }
    } while (opcion < 0 || opcion > 6);
    // Retornar la opción seleccionada
    return opcion;
}

int asignarHorarios() {
    /*TODO: Aprender a utilizar el enum de c++,
     *      Lo que se quería hacer era que al preguntar por un día
     *      devolviese su correspondiente peso. (0,1,2...).
    */
    char opcion;

    enum diasSemana{
        LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO,DOMINGO
    };
    do {
        cout<<"\t\t........\n";
        cout<<"\t\t| Días |\n";
        cout<<"\t\t........"<<endl;
        cout<<"\t(L). Lunes."<<endl;
        cout<<"\t(M). Martes."<<endl;
        cout<<"\t(W). Miercoles"<<endl;
        cout<<"\t(J). Jueves."<<endl;
        cout<<"\t(V). Viernes"<<endl;
        cout << "Seleccione una opción (L - M - W - J - V): ";

        // Leer la opción seleccionada por el usuario
        cin >> opcion;

        // Validar la opción ingresada
        if (opcion != 'L' && opcion != 'M' && opcion != 'W' && opcion != 'J' && opcion != 'V') {
            cout << "Opción inválida. Por favor, seleccione una opción (L - M - W - J - V)." << endl;
        }
    } while (opcion != 'L' && opcion != 'M' && opcion != 'W' && opcion != 'J' && opcion != 'V');

    // Retornar la opción seleccionada
    return opcion;
}

int registrarHorarios(int codigo) {
    char diaUno;
    int horaInicio=0, horaFinal=0;
    char diaDos;
    char opcion = 'x';
    while(opcion != 'n'){
        cout << "\n______________________________________________________\n"<<endl;
        cout <<"Seleccione el primer día: ";
        diaUno = asignarHorarios();
        while(horaInicio == horaFinal || (horaFinal - horaInicio) < 2
              || horaInicio > 20 || horaInicio < 6 || horaFinal > 22)
        {
            cout << "\n______________________________________________________\n"<<endl;
            cout<<"!RECUERDE UTILIZAR EL FORMATO MILIA¡ 0 - 24 horas"<<endl;
            cout <<"Ingrese hora de Inicio: ";
            cin >> horaInicio;
            horaFinal = horaInicio + 2;
        }
        cout <<"Horario: "<<horaInicio<<'-'<<horaFinal<<endl;

        cout <<"Seleccione el segundo día: ";
        diaDos = asignarHorarios();
        while(diaUno == diaDos){
            cout <<"¡Por Favor cambie el segundo día!"<<endl;
            cout <<"Seleccione el segundo día: ";
            diaDos = asignarHorarios();
        }

        // Abrir el archivo en modo de escritura y agregar
        ofstream archivo("horarios_disponibles.csv", ios::app);
        // Escribir el código,dia, Hora de Inicio, Hora Final separados por ';'
        archivo << '\n';
        archivo << codigo << ';' << diaUno << ';' << horaInicio
                <<'-'<<horaFinal<< ';' << diaDos << ';'
                << horaInicio <<'-'<<horaFinal<<endl;

        // Cerrar el archivo
        archivo.close();
        horaInicio=0, horaFinal=0;

        cout<<"\n\t¿Desea Registrar otro horario (s/n)?: ";
        cin>>opcion;
    }
    return 0;
}
int registrarCursos(){
    /* TODO: Excepciones cuando usurio ingresa caracteres en variable entero
     * try {
        cout << "Ingrese un numero entero: ";
        cin >> codigo;
        if (cin.fail()) {
            throw runtime_error("El valor ingresado no es un entero");
        }
        cout << "El numero ingresado es: " << codigo << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() <<endl;
    }
    */
    char opcion = 'x';
    int codigo=0;
    while(opcion != 'n'){
    // Nombre del Curso
    char *nombre = new char[10];
    // Horas Trabajo Docente
    int HTD;
    // Horas Trabajo Independientes
    int HTI;
    // Número de Créditos
    int NC;
    // Pedir al usuario que ingrese el código y el nombre del curso
    cout << "\n__________________________\
              ____________________________\n"<<endl;
    cout << "Ingrese el codigo del curso: ";
    cin >> codigo;
    cout << "Ingrese el nombre del curso: ";
    cin>>nombre;
    cout << "Ingrese las Horas trabajo docente: ";
    cin>>HTD;
    cout << "Ingrese las Horas trabajo independiente: ";
    cin>>HTI;
    cout << "Ingrese el número de créditos: ";
    cin>>NC;
    // Abrir el archivo en modo de escritura y agregar
    ofstream archivo("cursos_disponibles.csv", ios::app);
    // Escribir el código y el nombre del curso separados por ';'
    archivo << codigo << ";";
    for(int i=0;*(nombre+i) != '\0'; i++){
        archivo << *(nombre+i);
    }
    archivo << ';'<< HTD << ';' << HTI << ';' << NC << endl;
    // Cerrar el archivo
    archivo.close();

    registrarHorarios(codigo);
    delete[] nombre;

    cout<<"\n\t¿Desea Registrar otro curso (s/n)?: ";
    cin>>opcion;
    }
    return 0;
}

char*** cronograma(){
    int n = 10; // número de filas
    int m = 8; // número de columnas
    int charMax = 10; //

    char diasSemana[8][10] = { "        ",  "Lunes    ",
                               "Martes  ",  "Miercoles",
                               "Jueves  ",  "Viernes",
                               "Sabado  ",  "Domingo"};
    char bloquesDias[10][10] = { "    ",  "6-8",
                                 "8-10",  "10-12",
                                 "12-14", "14-16",
                                 "16-18", "18-20",
                                 "20-22", "22-24"};

    // crear un arreglo de punteros a char para representar las filas
    char*** matriz = new char**[n];

    /* crear un arreglo de char para cada fila y asignarlo
     * a cada puntero en la matriz */
    for (int i = 0; i < n; i++) {
        matriz[i] = new char*[m];
    }
    // llenar la matriz con valores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = new char[charMax];
        }
    }

    //Llenar cabecera con días de la semana
    for (int j = 0; j <= m; j++){
        matriz[0][j] = diasSemana[j];
    }

    //Llenar Columnas con bloques de días
    for (int j = 1; j <= m+1; j++){
        matriz[j][0] = bloquesDias[j];
    }

    //imprimir la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cout <<"\t"<<matriz[i][j];
            }
            cout << "\n______________________________________"
                    "________________________________________"
                    "________________________________________"
                    "________"<<endl;
            cout << endl;
        }

    return matriz;
    // liberar la memoria
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

char** MateriasDisponibles(){
    /*
     * TODO: Cambiar string por buffer de char.
     * TODO: Poner Argumento por valor de Rerencia
     *       a la matriz de materiasDisponibles.
     * TODO: Unificar función para leer por campos.
     */
    int materia = 0;
    char** MateriasDisponibles1 = new char*[10]; //Reservando memoria para 10 filas
    for(int i=0;i<10;i++){
       MateriasDisponibles1[i] = new char[10];
    }
    ifstream archivo("cursos_disponibles.csv");
    if (archivo){
        const int tamano_buffer = 400;
        char buffer[tamano_buffer];
        while (archivo.getline(buffer, tamano_buffer)){
            string linea(buffer);
            string codigo;
            stringstream ss(linea);
            getline(ss, codigo, ';');
            int caracter=0;
            while(codigo[caracter] != '\0')
            {
                MateriasDisponibles1[materia][caracter] = codigo[caracter];
                caracter++;
            }
            materia++;
      }
      archivo.close();
    }
    else {
      cout << "No se pudo abrir el archivo\n";
    }

    return MateriasDisponibles1;
    for (int i = 0; i < 10; i++) {
        delete[] MateriasDisponibles1[i];
    }
    delete[] MateriasDisponibles1;
}


char** HorariosDisponibles(int IntCodigo){
    /*
     * TODO: Cambiar string por buffer de char.
     * TODO: Poner Argumento por valor de Rerencia
     *       a la matriz de materiasDisponibles.
     * TODO: Unificar función para leer por campos.
     */
    int materia = 0;
    char** HorarioDisponibles1 = new char*[10]; //Reservando memoria para 10 filas
    for(int i=0;i<10;i++){
       HorarioDisponibles1[i] = new char[10];
    }
    ifstream archivo("horarios_disponibles.csv");
    if (archivo){
        const int tamano_buffer = 400;
        char buffer[tamano_buffer];
        while (archivo.getline(buffer, tamano_buffer)){
            string linea(buffer);
            string codigo, DiaUno, Horario1, DiaDos, Horario2;
            stringstream ss(linea);
            getline(ss, codigo, ';');
            getline(ss, DiaUno, ';');
            getline(ss, Horario1, ';');
            getline(ss, DiaDos, ';');
            getline(ss, Horario2, ';');
            int caracter=0;

            cout<< (codigo)<<endl;
            char* charcodigo = new char[10];
            charcodigo[] = "alejandro";
            while(codigo[caracter] != '\0' && codigo == enteroAChar(IntCodigo))
            {
                HorarioDisponibles1[materia][caracter] = codigo[caracter];
                caracter++;
            }
            materia++;
      }
      archivo.close();
    }
    else {
      cout << "No se pudo abrir el archivo\n";
    }
    return HorarioDisponibles1;
    for (int i = 0; i < 10; i++) {
        delete[] HorarioDisponibles1[i];
    }
    delete[] HorarioDisponibles1;
}

void imprimirMatriz(char** matriz){
    for (int i = 0; i < 10; i++) {
        cout << i << '-'  << matriz[i]<<endl;
    }
}
void ImprimirMateriasHorarios(){
    /*
     * TODO: Cambiar string por buffer de char.
     * TODO: Poner Argumento por valor de Rerencia
     *       a la matriz de materiasDisponibles.
     * TODO: Unificar función para leer por campos.
     */
    ifstream archivo("cursos_disponibles.csv");
    if (archivo) {
      const int tamano_buffer = 1024;
      char buffer[tamano_buffer];
      while (archivo.getline(buffer, tamano_buffer)) {
        string linea(buffer);
        string codigo, nombre, creditos, horas_clase, horas_lab;
        stringstream ss(linea);
        getline(ss, codigo, ';');
        getline(ss, nombre, ';');
        getline(ss, creditos, ';');
        getline(ss, horas_clase, ';');
        getline(ss, horas_lab, ';');

        cout << "\n______________________________________"
                "________________________________________"<<endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Creditos: " << creditos << endl;
        cout << "Horas de clase: " << horas_clase << endl;
        cout << "Horas de laboratorio: " << horas_lab << endl;
      }
      archivo.close();
    }
    else {
      cout << "No se pudo abrir el archivo "
              "para cursos disponibles\n";
    }
    ifstream archivo1("horarios_disponibles.csv");
    if (archivo1) {
      cout <<"\n------------HORARIOS------------\n";
      const int tamano_buffer = 1024;
      char buffer[tamano_buffer];
    while (archivo1.getline(buffer, tamano_buffer)) {
      string linea(buffer);
      string codigo, DiaUno, Horario1, DiaDos, Horario2;
      stringstream ss(linea);
      getline(ss, codigo, ';');
      getline(ss, DiaUno, ';');
      getline(ss, Horario1, ';');
      getline(ss, DiaDos, ';');
      getline(ss, Horario2, ';');
      cout << "\n______________________________________"
              "________________________________________"<<endl;
      cout << "Codigo: " << codigo << endl;
      cout << "Día Uno: " << DiaUno << endl;
      cout << "Horario: " << Horario1 << endl;
      cout << "Día Dos: " << DiaDos << endl;
      cout << "Día Dos: " << Horario2 << endl;
    }
    archivo.close();
    }
    else {
        cout << "No se pudo abrir el Base de datos "
                "Para Horarios disponibles\n";
  }
}

int* retornaArreglo(char dia) {
    int* horario = new int[2];

    switch (dia)
    {
    case 'L':{
        horario[0] = 1;
        break;
    }
    case 'M':{
        horario[0] = 2;
        break;
    }
    case 'W':{
        horario[0] = 3;
        break;
    }
    case 'J':{
        horario[0] = 4;
        break;
    }
    case 'V':{
        horario[0] = 5;
        break;
    }
    case 'S':{
        horario[0] = 6;
        break;
    }
    case 'D':{
        horario[0] = 7;
        break;
    }
    default:
        cout<<"opcion no valida"<<endl;
    }
    return horario;
}

char* enteroAChar(int numero) {
    char* cadena = new char[20]; // Se reserva memoria para la cadena (20 caracteres es un tamaño arbitrario)
    sprintf(cadena, "%d", numero); // Se convierte el número en una cadena de caracteres
    return cadena;
}

void Matricular(char*** cronograma, char** materiasDisponibles, char** AUXmateriasDisponibles){
    cout<<"RECUERDE LOS CODIGOS DISPONIBLES PARA MATRICULAR"<<endl;
    imprimirMatriz(materiasDisponibles);
    int numeroMaterias = 0;
    while(*(materiasDisponibles[numeroMaterias]) != '\0'){
        numeroMaterias++;
    }
    numeroMaterias = numeroMaterias - 1;
    cout<<"\nActualmente usted cuenta con: "<<numeroMaterias<<" Materias Disponibles."<<endl;
    bool matriculando = true;
    int codigo, horario;
    while(matriculando==true){
        codigo = 0; horario=0;
        while(codigo<1 || codigo>numeroMaterias){
        cout<<"Ingrese la posición del codigo a matricular (1-"<<numeroMaterias<<')'<<endl;
        cin>>codigo;}

        cout<<"Escoja un horario de las opciones disponibles"<<endl;
        cin>>horario;
    }
}


void search_by_code(char* filename, int code) {
    ifstream infile(filename);
    int c, r1s, r1e, r2s, r2e;
    char d1, d2, sep;
    while (infile >> c >> sep >> d1 >> sep >> r1s >> sep >> r1e >> sep >> d2 >> sep >> r2s >> sep >> r2e) {
        if (c == code) {
            cout<< c << ";" << d1 << ";" << r1s << "-" << r1e << ";" << d2 << ";" << r2s << "-" << r2e << std::endl;
        }
    }
}
void imprimirRecomendacionesEstudio(){
    /* TODO:
     * Leer archivo "recomendaciones de Estduio"
     * e imprimir para el usuario.
    */
}
#endif // FUNCIONES_H
