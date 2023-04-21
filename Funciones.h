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
int* retornaHorario(char dia, int hora);
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
        cout<<"\t2. Para ver cronograma #2."<<endl;
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

    char diasSemana[8][10] = { "Hora/Dia",  "Lunes",
                               "Martes",  "Miercoles",
                               "Jueves",  "Viernes",
                               "Sabado",  "Domingo"};
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
}
void imprimirMatriz(char** matriz){
    for (int i = 0; i < 10; i++) {
        cout << i << '-' << matriz[i]<<endl;
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
        cout << "Horas de tabajo Independiente: " << horas_lab << endl;
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
int* retornaHorario(char dia, int hora){
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

    switch (hora)
    {
    case 6:{
        horario[1] = 1;
        break;
    }
    case 8:{
        horario[1] = 2;
        break;
    }
    case 10:{
        horario[1] = 3;
        break;
    }
    case 12:{
        horario[1] = 4;
        break;
    }
    case 14:{
        horario[1] = 5;
        break;
    }
    case 16:{
        horario[1] = 6;
        break;
    }
    case 18:{
        horario[1] = 7;
        break;
    }
    case 20:{
        horario[1] = 8;
        break;
    }
    case 22:{
        horario[1] = 9;
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
void Matricular(char*** cronograma, char** materiasDisponibles){
    cout<<"RECUERDE LOS CODIGOS DISPONIBLES PARA MATRICULAR"<<endl;
    imprimirMatriz(materiasDisponibles);
    int numeroMaterias = 0 ;

    while(*(materiasDisponibles[numeroMaterias]) != '\0'){
        numeroMaterias++;
    }
    numeroMaterias = numeroMaterias - 1;
    cout<<"\nActualmente usted cuenta con: "<<numeroMaterias<<" Materias Disponibles."<<endl;
    bool matriculando = true;
    char matricular = '0';
    int codigo;

    while(matriculando==true)
    {
        codigo = 0;
        while(codigo<1 || codigo>numeroMaterias)
        {
            cout<<"Ingrese la posición del codigo a matricular (1-"<<numeroMaterias<<')'<<endl;
            cin>>codigo;
        }

        char* toMatricular = new char[10];
        toMatricular = materiasDisponibles[codigo];
        cout << "El codigo a Matricukar"<<toMatricular<<endl;

        /* TODO: Crear función */
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
                if(toMatricular == codigo){
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
                    do {
                        cout << "¿DESEA MATRICULAR ESTA MATERIA? (s/n)";
                        cin >> matricular;
                    }while(matricular != 's' && matricular !='n');
                    if(matricular=='s'){
                        cout<< "Este es el dia uno: "<<DiaUno[0]<<endl;
                        int* horario1 = new int[2];
                        int* horario2 = new int[2];
                        char diaUno = DiaUno[0];
                        char diaDos = DiaDos[0];
                        int hora = int(Horario1[0]-48);
                        horario1 = retornaHorario(diaUno, hora);
                        horario2 = retornaHorario(diaDos, hora);
                        cronograma[*(horario1+1)][*horario1] = toMatricular;
                        cronograma[*(horario2+1)][*horario2] = toMatricular;

                        /* TODO: Imprimir esta matriz
                       *  se puede convertir en una función.*/
                        int n = 10; // número de filas
                        int m = 8; // número de columnas

                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++){
                                cout <<"\t"<<cronograma[i][j];
                            }
                            cout << "\n______________________________________"
                                    "________________________________________"
                                    "________________________________________"
                                    "________"<<endl;
                            cout << endl;
                        }
                    }else{
                        char continuar = 'x';
                        do{
                        cout<<"¿Desea continuar Matriculando? (s/n)"<<endl;
                        cin>>continuar;
                        }while(continuar != 's' && continuar!='n');
                        if(continuar == 'n'){
                            matriculando = false;
                        }
                    }
                }else{
                    continue;
                }
                matricular = 'x';
            }
        }archivo1.close();
    }
}
void mostrarRecomendaciones() {
    /* TODO:
     * Leer archivo "recomendaciones de Estduio"
     * e imprimir para el usuario.
     * TODO: Mover a buffer de char
    */
    ifstream archivo("recomendaciones_estudio.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea <<endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}



int sizeChar(char* word){
    /*Función que se encarga de retornar un entero
    cuyo valor es la longitud de un conjunto de
    caracteres*/
    bool condi = true;
    int i = 0;

    //Se itera mientras no se encuentre el caracter nulo.
    while(condi == true){
        if(word[i] != 0){
            i++;
        }else{condi = false;}
    }return i;
}

//bool isletter(char a){
//    /*Funcion qeu se encarga de verificar si el caracter
//    es una letra*/
//    if ((a >= 97 && a <= 122) || (a >= 65 && a <= 90))
//    {
//        return true;
//    }else{
//        return false;
//    }
//}
//bool isWord(char* word, int n){
//    bool palabra = true;
//    for(int i = 0; i<n; i++){
//        palabra = isletter(*(word + i));
//        if(palabra==false){
//            break;
//            return palabra;
//        }
//    }return palabra;
//}



//bool isnumber(char a){
//    /*Funcion que se encarga de verificar si el caracter
//    es un número*/
//    if (a>=48 && a<=57) return true;
//    else return false;
//}



//int tamano_arreglo_int(int entero){
//  bool ban = true;
//  int i=0, residuo=0;

//  while(entero > 0){
//    residuo = entero % 10;
//    entero = entero / 10;
//    i++;

//  }return i;
//}
//char* entero_to_caracter(int entero){
//  int sizeEntero = (tamano_arreglo_int(entero));
//  char* Cadena = new char[sizeEntero];

//  for(int i=0;i<sizeEntero;i++){
//    Cadena[sizeEntero-i] = (entero % 10)+48;
//    entero = entero / 10;
//  }return Cadena;
//}



//bool edit(char* word){
//    int size=sizeChar(word);
//    for (int i = 0; i < size; i++){
//        if (isletter(word[i]) == true){
//            if (i==0){
//                if (word[0] >= 97 && word[0] <= 122) word[i] -= 32;
//            }
//            else{
//                if (word[0] >= 65 && word[0] <= 90) word[i] +=32;
//            }
//        }
//        else word[i]=0;
//        return false;
//    }
//    return true;
//}

//void copiar(char **Origen, char **Destino, int n){
//  /*
//  Función que se encarga de copiar de un arreglo bidimensional a otro
//  */
//    for (int i = 0; i < n; ++i){
//        Destino[i] = new char[(sizeChar(Origen[i]))-1];
//        Destino[i] = Origen[i];
//    }

//    delete[] Origen;
//    Origen = nullptr;
//}

//bool check(char** Arreglo, int n, char* word){
//    if (n == 0){
//        return false;
//    }else{
//    int sizeWord = sizeChar(word), cont = 0;
//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j < (sizeChar(Arreglo[i])-1); j++){
//            if (Arreglo[i][j] == word[j]){
//                cont++;
//            }
//        }
//        if(cont == (sizeWord-1)){
//            return true;
//        }else {cont=0;}
//    }
//    }return false;
//}

//char** attach(char** Arreglo, char** Almacenar, int* n, char* word){
//    /* Función que permite agregar registros al arreglo
//     realizando una copia en otro arreglo bidimensional */
//    if (check(Arreglo,*n,word) == false){
//        Almacenar = new char*[*n];
//        copiar(Arreglo,Almacenar,*n);

//        *n = *n + 1;

//        Arreglo = new char*[*n];
//        copiar(Almacenar,Arreglo,*n-1);

//        Arreglo[*n-1] = new char[sizeChar(word)];
//        for (int i = 0; i < sizeChar(word); i++){
//            Arreglo[*n-1][i] = word[i];
//        }
//        Arreglo[*n-1][sizeChar(word)]=0;
//    }return Arreglo;
//}
#endif // FUNCIONES_H
