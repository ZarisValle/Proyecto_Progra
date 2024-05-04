#include <iostream>
#include <string.h> 
#include <windows.h>
#include <conio.h>
#include <cstdlib> // Genera numeros aleatorios
#include <ctime>   // libreria para inicializar los numeros aleatorios
using namespace std;
char tablero[3][3];
int turno = 0;
string jugador1 = "";
string jugador2 = "";

void inicializartablero() {  //  inicializa todas las casillas del tablero con espacios en blanco al comienzo del juego. Esto se hace mediante un for anidado que recorre todas las filas y columnas.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' '; // Inicializamos todas las casillas con espacio en blanco
        }
    }
}

void imprimirtablero() { //  imprimir el estado actual del tablero en la consola. Utiliza un par de for anidados para recorrer todas las casillas del tablero y mostrar su contenido, imprime las lineas para que se vea agradable
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if (j < 2) { // si j es menor que dos imprime |
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) { // i es menor que dos imprime la linea que divide 
            cout << "-----------" << endl;
        }
    }
}
char seleccionarficha()
{
    char ficha;
    cout << "Seleccione la ficha que desea usar (X/O): ";
    cin >> ficha;
    if (ficha == 'X' || ficha == 'O') 
    {
        return ficha;
    }
    else
    {
        cout << "Ficha no válida. Seleccione 'X' o 'O'." << endl;
        return seleccionarficha();
    }
}

char posiblesjugadas() { // aca me muestra las opciones que tiene el jugador y cuando ya se hayan usado muestra que estan ocupadas
    cout << "Opciones a jugar:  " << endl;
    cout << "\n"; 
    int contador = 0;
    string opciones = "123456789"; // muestra las opciones que podemos colocar 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << opciones[contador] << ") [ " << i << "," << j << " ]" << endl; // muestra las coordenadas que se pueden usar en el tablero. 
            if (tablero[i][j] != ' ') { // i y j es diferente a nulo o espacio en blanco esta ocupado, sino contador suma  
                cout << " Posicion ocupada, elije otra";
            }
            cout << endl;
            contador++;
        }
    }
    cout<<endl;
     if ( turno % 2 == 0){
        cout<< jugador1;
     } else{
cout << jugador2;
     }
     cout<< endl;
     cout<< endl;
    cout << "Elije una jugada: " << endl;
    return getch(); // para no usar el enter cada vez que se agrega una ficha
}

void actuaalizarturno(int x, int y) { // actualiza el tablero junto  a la jugada cada vez que se coloca una ficha 
    if (turno % 2 == 0) { // si turno se divide y el residuo es = 0 sera la jugada de x y por siguiente la siguiente jugada es O
        tablero[x][y] = 'X';
    } else {
        tablero[x][y] = 'O';
    }
    turno++;
}
void actuaalizarturno(int x, int y, char ficha)
{
    tablero[x][y] = ficha;
    turno++;
}
int verificarganador() { // verifica si hay un ganador en todas las jugadas que se realicen, se recorre lo vertial, horizontal y diagonal 
    for (int i = 0; i < 3; i++) { // iteramos en las filas ya que se tienen menos 3 porque solo hay 3
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2]) { // espacios en blanco son los nulos, si tienen el simbolo y no estan vacias, si se cumple tiene que devoler 1 y hay ganador sino 0 y se sigue jugando
            return 1;
        }
        if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i]) { // lo mismo que las filas solo que en las columnas si se cumple la condicion devuelve 1 sino 0 
            return 1;
        }
    }
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) { //diagonales valida que las casillas no esten vacias y si se cumple la condicion devuleve 1
        return 1;
    }
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]) { 
        return 1;
    }
    return 0; // devuelve 0 significa que no se cumple lo anterior y sigue jugando 
}
int verificarjugada(char jugada) { // validamos si la casilla esta libre u ocupada  realiza el juego llamando a la funcion de actualizartuno 
    int posicion = jugada - '1'; // Convertimos el carácter de la jugada a un índice
    int x = posicion / 3; // Calculamos la fila
    int y = posicion % 3; // Calculamos la columna
    if (tablero[x][y] == ' ') { // Verificamos si la casilla está vacía
        actuaalizarturno(x, y);
        return verificarganador();
    } else {
        cout << "Posicion ocupada, elije otra." << endl;
        return 0; // Indicador de jugada no válida
    }
}
int verificarjugada(char jugada, char ficha)
{
    int posicion = jugada - '1'; // Convertimos el carácter de la jugada a un índice
    if (posicion >= 0 && posicion <= 8)
    { // Verificamos que la posición esté en el rango correcto
        int x = posicion / 3; // Calculamos la fila
        int y = posicion % 3; // Calculamos la columna
        if (tablero[x][y] == ' ')
        { // Verificamos si la casilla está vacía
            actuaalizarturno(x, y, ficha);
            return verificarganador();
        }
        else
        {
            cout << "Posicion ocupada, elije otra." << endl;
            return 0; // Indicador de jugada no válida y regresa 
        }
    }
    else
    {
        cout << "Jugada no válida. Elije una opción del 1 al 9." << endl;
        return -1; // Indicador de jugada no válida
    }
}



void identificarganador(int turnoant) {
    if (turnoant % 2 == 0) {
        cout << "El ganador es: " << jugador1 << " [X] ";
    } else {
        cout << "El ganador es Computadora"<< " [O] ";
    }
}
int movimientocomputadora(char ficha)
{
    // Generamos un número aleatorio entre 1 y 9 para seleccionar una casilla vacía
    int posicion;
    do
    {
        posicion = rand() % 9;
    } while (tablero[posicion / 3][posicion % 3] != ' '); // Verificamos si la casilla está ocupada
    actuaalizarturno(posicion / 3, posicion % 3, ficha);
    return verificarganador();
}

int main(){    
 

    int op, x1;
    string  n3;
    string X, O;
    int v1;
    int v2;
    
cout<< "X---------------------------------------------------O"<<endl;
cout<< "O              Bienvenidos al juego                 X"<<endl;
cout<< "X                                                   O"<<endl;
cout<< "O                                                   X"<<endl;
cout<< "X                      TOTITO                       O"<<endl;
cout<< "O                                 Por: Zara Valle   X"<<endl;
cout<< "X---------------------------------------------------O"<<endl;
cin.ignore();    


  
    
  cout <<"Elija el modo de juego"<<endl;
  cout << "1. Jugador Vs Jugador"<< endl;
  cout<< "2. Jugador Vs Computadora"<<endl;
  cin>> op;
  
  switch(op){
      case 1:{
          cout <<"Elegiste Jugador vs Jugador"<<endl;
          cout<< "Ingrese nombre del primer jugador"<<endl;
          cin>> jugador1;
          cout << "Ingrese nombre del segundo jugador"<< endl;
          cin>> jugador2;
          
          cout <<jugador1 <<" elije el simbolo a jugar X y O  "<<endl;
          cout<< "1. X"<<endl;
          cout << "2. O"<<endl;
          cout<< "\n \n";
          cin>> x1; 
          if (x1 == 1){
               cout<<jugador2<< " Te toca O"<<endl;
          }
              else jugador2= O;
              system("cls");
          cout<< "Empecemos!"<<endl;
          cout<< "\n";
         



    inicializartablero();
    int numturnos = 0;
    int ganadorband = 0;
    while (numturnos < 9 && ganadorband == 0) {
        system("cls");
        imprimirtablero();
        char jugada = posiblesjugadas(); // llama a la función y devuelve la casiila que selecciona el jugador 
        ganadorband = verificarjugada(jugada); // llama a la funcion verificar para ver si la casilla es valida, si esta ocupada o si hay ganador o sigue jugando 
        if (ganadorband == -1) { // Si la jugada no es válida, no incrementamos el número de turnos
                 return 0;  // sino es valida y esta ocupada regresa al ciclo. 
        } else {
            numturnos++;
        }
         // si es valida aumenta 
    }
    cout << endl;
    imprimirtablero(); // muestra el tablero una vez que se haya ganado 
    if (ganadorband == 1) {
        identificarganador(numturnos - 1); // llama la funcion para que identifiquemos quien gano 
    } else {
        cout << "EMPATE"<< endl;
    }
    system("pause");
            
          
          break;
      }
      case 2:{
          cout <<"Elegiste Jugador vs Computadora\n"<<endl;
          cout<< "Ingrese nombre del Jugador \n"<<endl;
          cin>> jugador1; 
          
          cout<< "Empecemos!"<<endl;
        srand(time(NULL)); // Inicializamos con numero aleatorios
    inicializartablero();
    char ficha_jugador = seleccionarficha();
    char ficha_computadora = (ficha_jugador == 'X') ? 'O' : 'X';
    int numturnos = 0;
    int ganadorband = 0;
    while (numturnos < 9 && ganadorband == 0)
    {
        system("cls");
        imprimirtablero();
        if (numturnos % 2 == 0)
        {
            char jugada = posiblesjugadas(); // muestra las casillas disponibles y nos muestra la jugada
            ganadorband = verificarjugada(jugada, ficha_jugador); // valida la jugada si es valida y ve si hay un ganador
        }
        else
        {
            ganadorband = movimientocomputadora(ficha_computadora); // Realiza el movimiento de la computadora seleccionando una casilla aleatoria válida y la coloca.
        }
        if (ganadorband == -1)
        { // Si la jugada no es válida, no incrementamos el número de turnos
            continue;
        }
        numturnos++;
    }
    cout << endl;
    imprimirtablero();
    if (ganadorband == 1)
    {
        identificarganador(numturnos - 1);
    }
    else
    {
        cout << "EMPATE"<< endl;
    }
    system("pause");
    break;
}
 
  }

    cout<< " ¿Deseas continuar...?"<<endl; 
    cout<< "1. Si"<< endl;
    cout<< " 2. No"<< endl;
    cin>>  v1; 
    if (v1 == 1){
        return main();
}else{ 
    cout<< "Gracias por jugar, hasta la proxima"<<endl;
}

 return 0;   
}





  

  