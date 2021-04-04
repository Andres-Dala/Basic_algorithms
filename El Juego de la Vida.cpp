#include <iostream>
#include <windows.h>
using namespace std;
int main(){
	char regresar;
	int opcion;
	menu:
	cout<<"---------------------BIENVENIDOS---------------------\n";
	cout<<"|                 EL JUEVO DE LA VIDA               |\n\n";
	cout<<"|                        MENU                       |\n\n";
	cout<<"|       1)Breve explicacion del juego y codigo      |\n\n";
	cout<<"|                   2)Iniciar juego                 |\n\n";
	cout<<"|                      3)Salir                      |\n\n";
	cout<<"-----------------------------------------------------\n\n";
	ingresar:
	cout<<"Introduzca numero de opcion: ";
	cin>>opcion;
	
	if(opcion==1){
		system("CLS");
		cout<<"------------------------EXPLICACION DEL JUEGO----------------------------\n";
	cout<<"Se trata de un juego de cero jugadores, lo que quiere decir que su evolucion\n";
	cout<<"esta determinada por el estado inicial y no necesita ninguna entrada de datos\n";
	cout<<"posterior. El tablero de juego es una malla plana formada por cuadrados (las\n";
	cout<<"celulas) que se extiende en todas las direcciones. Por tanto, cada celula \n";
	cout<<"tiene 8 células vecinas, que son las que están proximas a ella, incluidas las\n";
	cout<<"diagonales. Las células tienen dos estados: están vivas o muertas (o encendidas\n";
	cout<<"y apagadas). El estado de las celulas evoluciona a lo largo de unidades de\n";
	cout<<"tiempo discretas (se podría decir que por turnos).El estado de las celulas\n";
	cout<<"se tiene en cuenta para calcular el estado de las mismas al turno siguiente.\n";
	cout<<"Todas las celulas se actualizan simultáneamente en cada turno, siguiendo estas\n";
	cout<<"reglas:1. Una célula muerta con exactamente 3 celulas vecinas vivas nace\n";
	cout<<"(es decir, al turno siguiente estara viva). 2.Una célula viva con 2 o 3 celulas\n";
	cout<<"vecinas vivas sigue viva, en otro caso muere (por soledad o superpoblacion).\n\n\n";
	
	cout<<"----------------------EXPLICACION DEL CODIGO------------------------------\n";
	cout<<"Al inicio del juego se solicita el tamaño n de la matriz nxn, luego se crea\n";
	cout<<"una matriz con ceros (osea celulas muertas) y se le pide al usuario escribir\n";
	cout<<"coordenadas que indique donde desea que el cero se convierta en una celula\n";
	cout<<"viva. Si el usuario en una de las coordenadas escribe [-1,-1] el juego lo\n";
	cout<<"tomara como finalizado el proceso de ingreso de coordenadas, iniciando el juego.\n";
	cout<<"El proceso de analisis de la matriz esta dividido en 3 bloques. El primer \n";
	cout<<"bloque analiza si la casilla donde se encuentra es alguna de las esquinas de\n";
	cout<<"la matriz, sino continua al siguiente bloque donde analiza si es alguna parte\n";
	cout<<"lateral por ultimo sino es ninguna de estas indica que es una casilla central.\n";
	cout<<"Una vez establecido el tipo de casilla, inicia un contador que determine la \n";
	cout<<"cantidad de vecinas vivas que tiene; si es una esquina analizara tres vecinas,\n";
	cout<<"si lateral analiza cinco casillas o si es central analizara las ocho vecinas.\n";
	cout<<"Una vez termine el conteo determina si la casilla vive o muere con las \n";
	cout<<"condiciones ya mencionadas. Cada nuevo valor de las casillas se va almacenando\n";
	cout<<"en una matriz temporal para no tener problemas al leer las siguientes casillas.\n";
	cout<<"Luego de terminar de leer cada casilla se indica que la nueva matriz(generacion\n";
	cout<<"siguiente) sea igual a la matriz final. Una vez terminada la nueva generacion\n";
	cout<<"se genera un contador de celulas vivas, sino hay entonces se finaliza el juego.\n\n";
	cout<<"INTRODUZCA LA LETRA r PARA REGRESAR AL MENU  ";
	cin>>regresar;
	if(regresar=='r'){
		system("CLS");
		goto menu;
	}

	}
	
	if(opcion==2){
		system("CLS");
		int tamano;
	int contador_tiempos=1;
	
	cout<<"Ingrese dimension de la matriz: ";
	cin>>tamano;
	
	char vida[tamano][tamano];
	char temporal[tamano][tamano];
	
	for(int i=0; i<tamano; i++){
		for(int j=0; j<tamano; j++){
			vida[i][j]= '\117';
		}
	}
		for(int i=0; i<tamano; i++){
	    	for(int j=0; j<tamano; j++){
			cout<<vida[i][j]<<" ";
	
		}
		
		cout<<"\n";
	}
	cout<<"\n";
		   cout<<"Ingrese coordenas de celulas vidas:\n";
		   int i,j;
		   
while(i!=-1&&j!=-1){
	aqui:
	cout<<"i: ";
	cin>>i;
	cout<<"\n";
	cout<<"j: ";
	cin>>j;
	cout<<"\n";
	if(j>=tamano||i>=tamano){
		   	cout<<"Escriba coordenadas dentro del rango\n";
		   	goto aqui;
		   }
	vida[i][j]='\333';
	
	system("CLS");
	for (int i = 0; i<tamano; i++) {
      for (int j = 0; j<tamano; j++)
         if ( vida[i][j] =='\333' ) 
            cout << "\333"<<" ";
         else
            cout <<"0"<<" ";
      cout << endl;
   }
   cout<<"\n";
   cout<<"["<<i<<","<<j<<"] \n\n";
	}
	Sleep(700);
	system("CLS");
	cout<<"Generacion 0\n\n";
for (int i = 0; i<tamano; i++) {
      for (int j = 0; j<tamano; j++)
         if ( vida[i][j] =='\333' ) 
            cout << "\333"<<" ";
         else
            cout <<" ";
      cout << endl;
   }
	Sleep(2000);
		system("CLS");
	de_nuevo:
	//Esquinas
	for(int i=0; i<tamano; i++){
		
		for(int j=0; j<tamano; j++){
			
			//Esquina 1
		
		if(i==0&&j==0){
			int contae=0;
			if(vida[0][1]=='\333'){
				contae++;}
					if(vida[1][1]=='\333'){
				contae++;
			}
					if(vida[1][0]=='\333'){
				contae++;
		}
			if(contae==2&&vida[0][0]=='\333'){
					temporal[0][0]='\333';	
			}else
			if(contae==3){
				temporal[0][0]='\333';
			}else temporal[0][0]=' ';
		
		}
		//Esquina 2	
	
		if(i==0&&j==tamano-1){
			int contae=0;
			if(vida[0][tamano-2]=='\333'){
				contae++;}
					if(vida[1][tamano-2]=='\333'){
				contae++;
			}
					if(vida[1][tamano-1]=='\333'){
				contae++;
			}
				if(contae==2&&vida[0][tamano-1]=='\333'){
					temporal[0][tamano-1]='\333';
			}else
			if(contae==3){
				temporal[0][tamano-1]='\333';
			}else temporal[0][tamano-1]=' ';
		
		}
		//Esquina 3
		
			if(i==tamano-1&&j==tamano-1){
			int contae=0;
			if(vida[tamano-1][tamano-2]=='\333'){
				contae++;}
					if(vida[tamano-2][tamano-2]=='\333'){
				contae++;
			}
					if(vida[tamano-2][tamano-1]=='\333'){
				contae++;
			}
			if(contae==2&&vida[tamano-1][tamano-1]=='\333'){
					temporal[tamano-1][tamano-1]='\333';	
			}else
			if(contae==3){
				temporal[tamano-1][tamano-1]='\333';
			}else temporal[tamano-1][tamano-1]=' ';
		
		}
		//Esquina 4
		
			if(i==tamano-1&&j==0){
			int contae=0;
			if(vida[tamano-2][0]=='\333'){
				contae++;}
					if(vida[tamano-2][1]=='\333'){
				contae++;
			}
					if(vida[tamano-1][1]=='\333'){
				contae++;
				
			}
			if(contae==2&&vida[tamano-1][0]=='\333'){
					temporal[tamano-1][0]='\333';
			}else
			if(contae==3){
				temporal[tamano-1][0]='\333';
			}else temporal[tamano-1][0]=' ';
		
		}
		
		//Laterales
		
		//Lateral 1
		
		if(i==0&&j!=0&&j!=tamano-1){
			int contal=0;
			if(vida[0][j-1]=='\333'){
				contal++;
			}
			if(vida[0][j+1]=='\333'){
				contal++;
			}
			if(vida[1][j-1]=='\333'){
				contal++;
			}
			if(vida[1][j]=='\333'){
				contal++;
			}
			if(vida[1][j+1]=='\333'){
				contal++;
			}
				if(contal==2&&vida[i][j]=='\333'){
					temporal[i][j]='\333';
			}else
			if(contal==3){
				temporal[i][j]='\333';
			}else temporal[i][j]=' ';
			
		}
		
		//Lateral 2
		
		
		if(i!=tamano-1&&i!=0&&j==tamano-1){
			int contal=0;
			if(vida[i-1][j]=='\333'){
				contal++;
			}
			if(vida[i-1][j-1]=='\333'){
				contal++;
			}
			if(vida[i][j-1]=='\333'){
				contal++;
			}
			if(vida[i+1][j-1]=='\333'){
				contal++;
			}
			if(vida[i+1][j]=='\333'){
				contal++;
			}
			if(contal==2&&vida[i][j]=='\333'){
					temporal[i][j]='\333';
			}else
			if(contal==3){
				temporal[i][j]='\333';
			}else temporal[i][j]=' ';
		}
		
		//Lateral 3
		
			if(i==tamano-1&&j!=0&&j!=tamano-1){
			int contal=0;
			if(vida[i][j-1]=='\333'){
				contal++;
			}
			if(vida[i-1][j-1]=='\333'){
				contal++;
			}
			if(vida[i-1][j]=='\333'){
				contal++;
			}
			if(vida[i-1][j+1]=='\333'){
				contal++;
			}
			if(vida[i][j+1]=='\333'){
				contal++;
			}
			if(contal==2&&vida[i][j]=='\333'){
					temporal[i][j]='\333';
			}else
			if(contal==3){
				temporal[i][j]='\333';
			}else temporal[i][j]=' ';
		}
		
		//Lateral 4
		
		if(i!=tamano-1&&i!=0&&j==0){
			int contal=0;
			if(vida[i-1][j]=='\333'){
				contal++;
			}
			if(vida[i-1][j+1]=='\333'){
				contal++;
			}
			if(vida[i][j+1]=='\333'){
				contal++;
			}
			if(vida[i+1][j+1]=='\333'){
				contal++;
			}
			if(vida[i+1][j]=='\333'){
				contal++;
			}
			if(contal==2&&vida[i][j]=='\333'){
					temporal[i][j]='\333';
			}else
			if(contal==3){
				temporal[i][j]='\333';
			}else temporal[i][j]=' ';
		}
		
		//Zona Central
		
		if(i!=0&&j!=tamano-1&&i!=tamano-1&&j!=0){
				int contal=0;
			if(vida[i-1][j-1]=='\333'){
				contal++;
			}
			if(vida[i-1][j]=='\333'){
				contal++;
			}
			if(vida[i-1][j+1]=='\333'){
				contal++;
			}
			if(vida[i][j+1]=='\333'){
				contal++;
			}
			if(vida[i+1][j+1]=='\333'){
				contal++;
			}
			if(vida[i+1][j]=='\333'){
				contal++;
			}
			if(vida[i+1][j-1]=='\333'){
				contal++;
			}
			if(vida[i][j-1]=='\333'){
				contal++;
			}
				if(contal==2&&vida[i][j]=='\333'){
					temporal[i][j]='\333';
			}else
			if(contal==3){
				temporal[i][j]='\333';
			}else temporal[i][j]=' ';
		}
	}
}

   for(int i=0; i<tamano;i++){
   	for(int j=0; j<tamano; j++){
   		vida[i][j]=temporal[i][j];
	   }
   }
//Fin de creacion de matriz
cout<<"Generacion: "<<contador_tiempos<<"\n\n";
			for(int i=0; i<tamano; i++){
	        	for(int j=0; j<tamano; j++){
			cout<<vida[i][j];
	
		}
		cout<<"\n";
	}
	cout<<"\n\n";
	
	int contador=0;
		for(int i=0; i<tamano;i++){
		  for(int j=0; j<tamano; j++){
		  	
		  	if(vida[i][j]=='\333'){
		  		contador++;
			  }
		  }
	}
	
	while(contador!=0){
		Sleep(200);
		system("CLS");
		contador_tiempos++;
		
		goto de_nuevo;
		
	}
	goto fin;
	}else
	if(opcion==4){
		goto fin;
	}
	if(opcion!=4){
	
	cout<<"Opcion invalida\n";
	goto ingresar;
}
	fin:
		
	return 0;
	}
	
