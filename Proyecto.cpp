#include <iostream>
#include <string.h> 
#include <windows.h>
using namespace std;

char tablero [3][3]; 

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
                     cout << " " << tablero [x][y] << " ";
                     y++;

                } else  {
                    cout << "   ";
                }
 
            }
            if (j < 2){
                cout<< "|";
            }
        }
        y=0; 
        if (i % 2 == 0){
            x++;
        }
cout<< endl;
    }

}

int main(){    
 
    

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    int op, x1;
    string n1,n2, n3;
    string X, O;
    
        
    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);

  cout << "\t\t\t\t\t\t\t JUGUEMOS TOTITO"<<endl;
      SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);


 
  cout <<"Elija el modo de juego"<<endl;
  cout << "1. Jugador Vs Jugador"<< endl;
  cout<< "2. Jugador Vs Computadora"<<"\n";
  cin>> op;
  
  switch(op){
      case 1:{
          cout <<"Elegiste Jugador vs Jugador"<<endl;
          cout<< "Ingrese nombre del primer jugador"<<endl;
          cin>> n1;
          cout << "Ingrese nombre del segundo jugador"<< endl;
          cin>> n2;
          
          cout <<n1 <<" elije el simbolo a jugar X y O  "<<endl;
          cout<< "1. X"<<endl;
          cout << "2. O"<<endl;
          cout<< "\n \n";
          cin>> x1; 
          if (x1 == 1){
               cout<<n2<< " Te toca O"<<endl;
          }
              else n2= O;
          cout<< "Empecemos!"<<endl;
SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);

    tablero[0][0] = '1';
    tablero[0][1] = '2';
    tablero[0][2] = '3';
    tablero[1][0] = '4';
    tablero[1][1] = '5';
    tablero[1][2] = '6';
    tablero[2][0] = '7';
    tablero[2][1] = '8';
    tablero[2][2] = '9';
    imprimirtablero();
    system ("pause");
            
          
          break;
      }
      case 2:{
          cout <<"Elegiste Jugador vs Computadora\n"<<endl;
          cout<< "Ingrese nombre del Jugador \n"<<endl;
          cin>> n3; 
          cout <<n3 <<" elije el simbolo a jugar X y O \n "<<endl;
          cout<< "1. X"<<endl;
          cout << "2. O"<<endl;
          cout<< "\n \n";
          cin>> x1; 
          if (x1 == 1){
              cout<< "\n \n";
               cout<< " Computadora te toca O"<<endl;
          }
          else{
            if(x1 == 2){
cout<< " Computadora te toca X"<<endl;
            }
            
          }
          cout<< "Empecemos!"<<endl;

          tablero[0][0] = '1';
    tablero[0][1] = '2';
    tablero[0][2] = '3';
    tablero[1][0] = '4';
    tablero[1][1] = '5';
    tablero[1][2] = '6';
    tablero[2][0] = '7';
    tablero[2][1] = '8';
    tablero[2][2] = '9';
    imprimirtablero();
    system ("pause");
         
          break;
      }
      default:
      cout<<"Opción no valida, intente de nuevo"<<endl;
      return main();
  }

    
    return 0;
}



  

  