#include <iostream> 
#include <conio.h>

using namespace std;
char tablero [3][3]; 
char jugada;
int turno =0; 
string jugador1  = "Zara";

    void imprimirtablero(){
      int x = 0;
      int y = 0; 
    for (int i = 0; i < 6; i++){
        for (int j =0; j < 3; j ++){
            if ( i < 5 && i % 2 == 1){
cout << "___";
            } 
            else {
                 if (i < 5){
                cout << " " << tablero[x][y]<< " ";
                y++; // este aumenta ya que empiezan en 0 ambas pero en la siguiente Y tiene que aumentar ya que va a estar en la posicion siguiente
                }else {
                    cout<< "   ";
                }
                
                }
 
            
            if (j < 2){
                cout<< "|";
            }
    }
    y=0; // termina el bucle y empieza nuevamente en 0
    if (i % 2  == 0){ // si es impar va a sumar la X, cuando es impar dibuja la lines cuando es par muestra 
x++; // x solo tiene que sumar cuando el valor sea impar 
    } 
cout<<endl;
}
}
 
 char posiblesjugadas(){
 cout<< "Opciones a jugar "<<endl;
 int contador =0;
 string opciones = "123456789";
 for (int i =0; i<3; i++){
for (int j =0; j<3; j++){
    cout<<opciones [contador]<<") [ "<< i << "," << j << " ]"<<endl;
    if ( tablero [i][j] != NULL){
        cout<< " Posicion ocupada, elije otra"; 
    }
    cout<< endl;
    contador++;
    }
   }
   char jugada; 
 cout<<"Elije una jugada: "<<endl; 
  return getch(); //no se necesita el enter para poder mandar lo que se digito
 }
 void actuaalizarturno(int x, int y){
    if (turno %2 == 0){
       tablero [x][y]= 'x';  
    } else {
        tablero [x][y]= 'o';   
    }
    turno++;
} 

int verificarjugada ( char jugada){  // nos validara si la jugada esta en el rango 1 a 9  y disponble posicion
if (jugada>= '1' && jugada <= '9' ){ // rango de 1 a 9
switch (jugada){ // disponibilidad de posicion

    case '1':
    if ( tablero[0][0] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(0, 0);
        return 1;
    }
    break;

    case '2':
    if ( tablero[0][1] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(0, 1);
        return 1;
    }
    break;

    case '3':
    if ( tablero[0][2] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(0, 2);
        return 1;
    }
    break;

    case '4':
    if ( tablero[1][0] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(1, 0);
        return 1;
    }
    break;

    case '5':
    if ( tablero[1][1] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(1, 1);
        return 1;
    }
    break;

    case '6':
    if ( tablero[1][2] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(1, 2);
        return 1;
    }
    break;

    case '7':
    if ( tablero[2][0] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(2, 0);
        return 1;
    }
    break;

    case '8':
    if ( tablero[2][1] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(2, 1);
        return 1;
    }
    break;

    case '9':
    if ( tablero[2][2] == NULL){ // si tablero en la posicion 0,0 esta vacia, retorna x 
    actuaalizarturno(2, 2);
        return 1;
    }
    break;
   }
}
return 0; 
}

int verificarganador(){
    if (tablero [0][0] != NULL && tablero [0][0] == tablero [0][1] && tablero [0][0] == tablero [0][2]){
       return 1;
    }
    if (tablero [1][0] != NULL && tablero [1][0] == tablero [1][1] && tablero [1][0] == tablero [1][2]){
       return 1;
       }
        if (tablero [2][0] != NULL && tablero [2][0] == tablero [2][1] && tablero [2][0] == tablero [2][2]){
       return 1;
       } if (tablero [0][0] != NULL && tablero [0][0] == tablero [1][0] && tablero [0][0] == tablero [2][0]){
       return 1;
       } if (tablero [0][1] != NULL && tablero [0][1] == tablero [1][1] && tablero [0][1] == tablero [0][2]){
       return 1;
       } if (tablero [0][2] != NULL && tablero [0][2] == tablero [1][2] && tablero [0][2] == tablero [2][2]){
       return 1;
       }
        if (tablero [0][0] != NULL && tablero [0][0] == tablero [1][1] && tablero [0][0] == tablero [2][2]){
       return 1;
       } if (tablero [0][2] != NULL && tablero [0][2] == tablero [1][1] && tablero [0][2] == tablero [2][2]){
       return 1;
       } 
    return 0; 
}
void identificarganador (int turnoant ){
    cout << "Felicitaciones "; 
if (turnoant %2 ==0 ){
    cout << "El ganador es: " << jugador1 << "[ X ]";  
} else {
    cout<< "El ganador es: jugador 2"<< "[ O ]";
 
}
}
int main (){ 
   int numturnos = 0;
   int banderaturno = 0;
   int ganadorband = 0;
   while (numturnos < 9 && ganadorband == 0) {
    system ("cls");
    imprimirtablero(); // construimos el tablero
    cout << verificarjugada(posiblesjugadas()); // jugamos y verificamos la jugada 
    if (banderaturno ==1){
        ganadorband = verificarganador();
numturnos ++; 
    }
   
   }
   cout <<endl; 
   imprimirtablero (); 
if (ganadorband ==1){
    identificarganador(numturnos -1);
} else{
    cout << "EMPATE"; 
}
    system ("pause");
    return 0;
}