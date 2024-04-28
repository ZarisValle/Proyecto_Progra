#include <iostream>
#include <string.h> 
using namespace std;
int main()
{
    int op, x1;
    string n1,n2, n3;
    string X, O;
    
        

  cout << "\t\t\t\t\t\t\t Bienvenido al juego Tres en Raya"<<endl;
  cout <<"Elija el modo de juego"<<endl;
  cout << "1. Jugador Vs Jugador"<< endl;
  cout<< "2. Jugador Vs Computadora"<<endl;
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
          cout<< "Empecemos!"<<endl;
          break;
      }
      default:
      cout<<"Opción no valida, intente de nuevo"<<endl;
      return main();
  }
  
    
    return 0;
}