#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#define TAM 10000
#include <cstdlib>
#define TAM2 37
using namespace std;

void top10_funcion(int vector36[], int tl);
void top20_funcion(int vector36[], int tl);
bool Salir();
void PantallaSalida();
void leerTodosLosNumeros(int vector[], int &tl);
void cargarVector36_conTodosLosNumeros(int vector[], int vector36[], int tl);
void menuRangos();
void primerosXnumeros();

int main() {
	int tl=0;
	int vector[TAM];
	int vector36[TAM2];
	int entrar;
	bool continuarMenu=true;
	
	leerTodosLosNumeros(vector, tl);
	
	cout<<"\t\t\tBIENVENIDOS"<<endl<<endl;
	do{
		do{	
			
			cout<<"\n\n\n\t\t\t\t                 ษออออออออออออออป"<<endl;
			cout<<"\t\t\t\t                 บMENU PRINCIPALบ"<<endl;
			cout<<"\t\t\t\t      ษออออออออออสออออออออออออออสออออออออออป"<<endl;
			cout<<"\t\t\t\t      บ1.TOP 10 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ2.TOP 20 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ3.RANGOS                            บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ4.SALIR                             บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar;
			cin.clear ();
			fflush(stdin);
			if(entrar<1||entrar>4) {
				system("cls");
				cout<<"\t\tError: la seleccion solo puede ser 1 a 4. Reingrese por favor"<<endl;
			}
			
		} while(entrar<1||entrar>4);
	
	switch (entrar){
	case 1: system("cls");
		cargarVector36_conTodosLosNumeros(vector, vector36, tl);
		top10_funcion(vector36,tl); 
		system("pause"); 
		system("cls"); 
		break;
	case 2: system("cls"); 
		cargarVector36_conTodosLosNumeros(vector, vector36, tl);
		top20_funcion(vector36, tl); 
		system("pause"); 
		system("cls"); 
		break;
	case 3: menuRangos();
		system("cls");
		break;
	case 4: if (Salir()){ // si deseaSalir es verdadera, entonces no se debe continuar con la ejecucion del programa.
			continuarMenu = false;
		}
		break;
	}

	} while(continuarMenu);
	
	

	return 0;
}

void menuRangos(){
	system("cls");
	int entrar2;

		do{	
			
			cout<<"\n\n\n\t\t\t\t                 ษออออออออออออออป"<<endl;
			cout<<"\t\t\t\t                 บ  MENU RANGOS บ"<<endl;
			cout<<"\t\t\t\t      ษออออออออออสออออออออออออออสออออออออออป"<<endl;
			cout<<"\t\t\t\t      บ1.PRIMEROS ""X"" NUMEROS                บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ2.ULTIMOS ""X"" NUMEROS                 บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ3.DESDE - HASTA                     บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ4.REGRESAR                          บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar2;
			cin.clear ();
			fflush(stdin);
			if(entrar2<1||entrar2>4) {
				system("cls");
				cout<<"\t\tError: la seleccion solo puede ser 1 a 4. Reingrese por favor"<<endl;
			}
			
		} while(entrar2<1||entrar2>4);
		
		switch (entrar2){
		case 1: system("cls");
			primerosXnumeros();
			break;
			
		}
	
}
void top10_funcion(int vector36[], int tl){
	int vector36Aux[TAM2];
	int top10[10];
	int maximo;
	//hacer una copia de vector36 en vector36Aux
	for(int i=0; i<TAM2; i++)
		vector36Aux[i]=vector36[i];
	
	//completar vector top10
	int k;
	int posicionDeMaximo;
	
	for(int i=0; i<10; i++){
		maximo=-1;
		for(k=0; k<TAM2; k++){
			if(vector36Aux[k]>=maximo){
				maximo=vector36Aux[k];
				posicionDeMaximo=k;
			}
		}
		top10[i]=posicionDeMaximo;
		vector36Aux[posicionDeMaximo]=-2;
	}
	
	cout<<endl<<endl<<"1- TOP 10 - NUMEROS QUE MAS SALIERON"<<endl<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	cout<<"| NUMERO |"<<"\t\t| VECES QUE SALIO |"<<"\t| PORCENTAJE |"<<"\t| CANTIDAD / TOTAL |"<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	for(int i=0; i<10; i++)
		cout<<"   "<<top10[i]<<"\t\t\t  "<<vector36[top10[i]]<<" VECES\t\t  "<<vector36[top10[i]]*100.0/tl<<" %\t\t\t "<<vector36[top10[i]]<<" / "<<tl<<endl<<endl;
	
}
void top20_funcion(int vector36[], int tl){
	int vector36Aux[TAM2];
	int top20[20];
	int maximo;
	//hacer una copia de vector36 en vector36Aux para completar top20
	for(int i=0; i<TAM2; i++)
		vector36Aux[i]=vector36[i];
	
	//completar vector top20
	int k;
	int posicionDeMaximo;
	for(int i=0; i<20; i++){
		maximo=-1;
		for(k=0; k<TAM2; k++){
			if(vector36Aux[k]>=maximo){
				maximo=vector36Aux[k];
				posicionDeMaximo=k;
			}
		}
		top20[i]=posicionDeMaximo;
		vector36Aux[posicionDeMaximo]=-2;
	}

	cout<<endl<<endl<<"2- TOP 20 - NUMEROS QUE MAS SALIERON"<<endl<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	cout<<"| NUMERO |"<<"\t\t| VECES QUE SALIO |"<<"\t| PORCENTAJE |"<<"\t| CANTIDAD / TOTAL |"<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	for(int i=0; i<20; i++)
		cout<<"   "<<top20[i]<<"\t\t\t  "<<vector36[top20[i]]<<" VECES\t\t  "<<vector36[top20[i]]*100.0/tl<<" %\t\t\t "<<vector36[top20[i]]<<" / "<<tl<<endl<<endl;
	
}


void leerTodosLosNumeros(int vector[], int &tl){
	ifstream archivoLectura;
	char a[100];
	archivoLectura.open("numeros.txt");
	if(archivoLectura.fail()){
		cout << "Error al abrir el archivo para lectura: numeros.txt" << endl;
	}
	else{
		bool bandera=false;
		while(!archivoLectura.eof()){
			archivoLectura.getline(a,99,'\n');
			
			vector[tl]=atof (a);
			if(atof(a)>36)
				bandera=true;
			tl++;
		}
		if(bandera){
			cout<<"CUIDADO! HAY NUMEROS MAYORES QUE 36"<<endl<<endl;
			for(int i=0; i<4; i++){
				cout<<"\a";
				
				
			}
			system("pause");
			system("cls");
		}
	}
	archivoLectura.close();
	
}

void cargarVector36_conTodosLosNumeros(int vector[], int vector36[], int tl){
	//inicializar vector36 en 0
	for(int i=0; i<TAM2; i++)
		vector36[i]=0;
	
	//completar vector36 con la cantidad de veces que salio cada numero
	for(int i=0; i<TAM2;i++)
		for(int j=0; j<tl; j++){
			if(vector[j]==i)
				vector36[i]++;
		}
}

void primerosXnumeros(){
	
}
bool Salir(){
	bool quiereSalir;
	bool error=false;
	char opcion;
	system("cls");
	
	do
		{
			if (error) cout << "\a";
			cout << "\n\n\n\n\n\n		    Esta seguro que desea salir? < S o N >";
			opcion=getch();
			system ("cls");
			error=true;
		}
	while (opcion != 'S' && opcion != 's' && opcion != 'n' && opcion!= 'N'); 
	if (opcion == 's' || opcion == 'S'){
		quiereSalir=true; //si desea salir, Salir pasa a ser verdadero
		PantallaSalida();	
	}
	else quiereSalir=false; //si no quiere salir, quiere salir es falso
	return quiereSalir;
}

void PantallaSalida(){
	cout<<"\n\t\t\tGracias por usar el software de estadisticas"<<endl<<endl;
	cout<<"\n\t\t\t  CREATED BY ELISEO DE LA IGLESIA  ";
	
	getch();
}
