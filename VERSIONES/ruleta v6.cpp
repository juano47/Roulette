//ruleta v6  agrega "verColores"

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
void top36_funcion(int vector36[], int tl);
bool Salir();
void PantallaSalida();
void leerTodosLosNumeros(int vector[], int &tl);
void cargarVector36(int vector[], int vector36[], int inicio, int final);
void menuRangos(int tl, int vector36[], int vector[]);
void primerosXnumeros(int tl, int vector36[], int vector[], int &seleccion);
void ultimosXnumeros(int tl, int vector36[], int vector[], int &seleccion);
void desdeHasta( int tl, int vector36[], int vector[], int &seleccion, int &hasta);
void vecesQueSalioUnNumero(int vector36[]);
void verGrafica(int vector36[]);
void menuPrincipalConRangoSeleccionado(int tl, int vector36[], int desde, int hasta);
void verColores(int vector[], int tl);

int main() {
	int tl=0;
	int vector[TAM];
	int vector36[TAM2];
	int entrar;
	bool continuarMenu=true;
	
	leerTodosLosNumeros(vector, tl);
	//system ("color F0" );
	
	do{
		do{	
			
			cout<<"\n\n\n\t\t\t\t                 ษออออออออออออออป"<<endl;
			cout<<"\t\t\t\t                 บMENU PRINCIPALบ"<<endl;
			cout<<"\t\t\t\t      ษออออออออออสออออออออออออออสออออออออออป"<<endl;
			cout<<"\t\t\t\t      บ1.TOP 10 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ2.TOP 20 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ3.TOP 36 - TODOS LOS NUMEROS        บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ4.RANGOS                            บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ5.VECES QUE SALIO UN NUMERO         บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ6.COLORES                           บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ7.PAR / IMPAR                       บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ8.DOCENAS                           บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ9.COLUMNAS                          บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ10.VER GRAFICA                      บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ11.SALIR                            บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar;
			cin.clear ();
			fflush(stdin);
			if(entrar<1||entrar>11) {
				system("cls");
				cout<<"\t\t\aError: la seleccion solo puede ser 1 a 11. Reingrese por favor"<<endl;
			}
			
		} while(entrar<1||entrar>11);
		
		switch (entrar){
		case 1: //TOP 10 - NUMEROS QUE MAS SALIERON 
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			top10_funcion(vector36,tl); 
			system("pause"); 
			system("cls"); 
			break;
		case 2: //TOP 20 - NUMEROS QUE MAS SALIERON
			system("cls"); 
			cargarVector36(vector, vector36, 0, tl);
			top20_funcion(vector36, tl); 
			system("pause"); 
			system("cls"); 
			break;
		case 3: //TOP 36 - TODOS LOS NUMEROS
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			top36_funcion(vector36, tl);
			system("pause");
			system("cls");
			break;
		case 4: //RANGOS 
			menuRangos(tl, vector36, vector);
			system("cls");
			break;
		case 5: //VECES QUE SALIO UN NUMERO
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			vecesQueSalioUnNumero(vector36);
			system("pause"); 
			system("cls"); 
			break;
		case 6: //COLORES
			system("cls");
			verColores(vector, tl);
			system("pause");
			system("cls");
			break;
		case 10: //VER GRAFICA
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			verGrafica(vector36);
			system("pause");
			system("cls");
			break;
		case 7: if (Salir()){ // si deseaSalir es verdadera, entonces no se debe continuar con la ejecucion del programa.
			continuarMenu = false;
		}
			break;
		}
		
	} while(continuarMenu);
	
	
	
	return 0;
}

void menuRangos(int tl, int vector36[], int vector[]){
	system("cls");
	int entrar2;
	int seleccion;
	do{
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
				cout<<"\t\t\aError: la seleccion solo puede ser 1 a 4. Reingrese por favor"<<endl;
			}
			
		} while(entrar2<1||entrar2>4);
		
		switch (entrar2){
		case 1: system("cls");
			primerosXnumeros(tl, vector36, vector, seleccion);
			menuPrincipalConRangoSeleccionado(tl, vector36, 0, seleccion);
			system("cls"); 
			break;
		case 2:{system("cls");
		
		ultimosXnumeros(tl, vector36, vector, seleccion);
		int seleccionAux=tl-seleccion;
		menuPrincipalConRangoSeleccionado(tl, vector36, seleccionAux, tl);
		system("cls"); 
		break;
		}
		case 3:{system("cls");
		int hasta;
		desdeHasta(tl, vector36, vector, seleccion, hasta);
		menuPrincipalConRangoSeleccionado(tl, vector36, seleccion, hasta);
		system("cls"); 
		}
		}
	}while(entrar2!=4);
	
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

void top36_funcion(int vector36[], int tl){
	int vector36Aux[TAM2];
	int top36[37];  //en realidad son 37 numeros teniendo en cuenta el cero.
	int maximo;
	//hacer una copia de vector36 en vector36Aux para completar top20
	for(int i=0; i<TAM2; i++)
		vector36Aux[i]=vector36[i];
	
	//completar vector top20
	int k;
	int posicionDeMaximo;
	for(int i=0; i<37; i++){
		maximo=-1;
		for(k=0; k<TAM2; k++){
			if(vector36Aux[k]>=maximo){
				maximo=vector36Aux[k];
				posicionDeMaximo=k;
			}
		}
		top36[i]=posicionDeMaximo;
		vector36Aux[posicionDeMaximo]=-2;
	}
	
	cout<<endl<<endl<<"2- TOP 36 - TODOS LOS NUMEROS QUE SALIERON"<<endl<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	cout<<"| NUMERO |"<<"\t\t| VECES QUE SALIO |"<<"\t| PORCENTAJE |"<<"\t| CANTIDAD / TOTAL |"<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	for(int i=0; i<37; i++)
		cout<<"   "<<top36[i]<<"\t\t\t  "<<vector36[top36[i]]<<" VECES\t\t  "<<vector36[top36[i]]*100.0/tl<<" %\t\t\t "<<vector36[top36[i]]<<" / "<<tl<<endl<<endl;
	
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

void cargarVector36(int vector[], int vector36[], int inicio, int final){
	//inicializar vector36 en 0
	for(int i=0; i<TAM2; i++)
		vector36[i]=0;
	
	//completar vector36 con la cantidad de veces que salio cada numero
	for(int i=0; i<TAM2;i++)
		for(int j=inicio; j<final; j++){
			if(vector[j]==i)
				vector36[i]++;
		}
}

void primerosXnumeros(int tl, int vector36[], int vector[], int &seleccion){
	
	
	do{
		cout<<"Elija desde donde mostrar"<<endl;
		cin>>seleccion;
		cin.clear ();
		fflush(stdin);
		if(seleccion>tl){
			system("cls");
			cout<<"\aError -> Hay menos de "<<tl<<" numeros ingresados. Ingrese un numero menor a este valor."<<endl<<endl;
		}
	}while(seleccion>tl);
	
	cargarVector36(vector, vector36, 0, seleccion);
}

void ultimosXnumeros(int tl, int vector36[], int vector[], int &seleccion){
	
	
	do{
		cout<<"Elija ultimos numeros a mostrar"<<endl;
		cin>>seleccion;
		cin.clear ();
		fflush(stdin);
		if(seleccion>tl){
			system("cls");
			cout<<"\aError -> Hay menos de "<<tl<<" numeros ingresados. Ingrese un numero menor a este valor."<<endl<<endl;
		}
	}while(seleccion>tl);
	int seleccion2=tl-seleccion;
	
	cargarVector36(vector, vector36, seleccion2, tl);
}

void desdeHasta( int tl, int vector36[], int vector[], int &seleccion, int &hasta){
	
	do{
		cout<<"Elija desde donde mostrar"<<endl;
		cin>>seleccion;
		cin.clear ();
		fflush(stdin);
		if(seleccion>tl-1){
			system("cls");
			cout<<"\aError -> Hay menos de "<<tl<<" numeros ingresados. Ingrese un numero menor a "<<tl-1<<"."<<endl<<endl;
		}
	}while(seleccion>tl-1);
	
	do{
		cout<<"Elija hasta donde mostrar"<<endl;
		cin>>hasta;
		cin.clear ();
		fflush(stdin);
		if(hasta>tl){
			system("cls");
			cout<<"\aError -> Hay menos de "<<tl<<" numeros ingresados. Ingrese un numero menor a este valor."<<endl<<endl;
		}
	}while(hasta>tl);
	
	
	cargarVector36(vector, vector36, seleccion, hasta);
}

void vecesQueSalioUnNumero(int vector36[]){
	int numero;
	do{
		cout<<"Ingrese un numero: "<<endl;
		cin>>numero;
		cin.clear ();
		fflush(stdin);
		if(numero>36||numero<0){
			system("cls");
			cout<<"\aError -> El numero ingresado debe ser mayor que 0 y menor que 36."<<endl<<"Reingrese por favor";
		}
	}while(numero>36||numero<0);
	system("cls");
	cout<<endl<<"El numero "<<numero<<" salio "<<vector36[numero]<<" veces."<<endl<<endl;
}

void verGrafica(int vector36[]){
	
	int A=vector36[0];
	int B=vector36[32];
	int C=vector36[15];
	int D=vector36[19];
	int E=vector36[4];
	int F=vector36[21];
	int G=vector36[2];
	int H=vector36[25];
	int I=vector36[17];
	int J=vector36[34];
	int K=vector36[6];
	int L=vector36[27];
	int M=vector36[13];
	int N=vector36[36];
	int O=vector36[11];
	int P=vector36[30];
	int Q=vector36[8];
	int R=vector36[23];
	int S=vector36[10];
	int T=vector36[5];
	int U=vector36[24];
	int V=vector36[16];
	int W=vector36[33];
	int X=vector36[1];
	int Y=vector36[20];
	int Z=vector36[14];
	int ZA=vector36[31];
	int ZB=vector36[9];
	int ZC=vector36[22];
	int ZD=vector36[18];
	int ZE=vector36[29];
	int ZF=vector36[7];
	int ZG=vector36[28];
	int ZH=vector36[12];
	int ZI=vector36[35];
	int ZJ=vector36[3];
	int ZK=vector36[26];
	
	cout<<"                              "<<A<<"										"<<endl;
	cout<<"                       "<<ZK<<"             "<<B<<"              	 		"<<endl;
	cout<<"                  "<<ZJ<<"           0           "<<C<<"      				"<<endl;
	cout<<"             "<<ZI<<"          26        32           "<<D<<"      			"<<endl;
	cout<<"                     3                 15            						"<<endl;
	cout<<"                35                          19           					"<<endl;
	cout<<"        "<<ZH<<"                                            "<<E<<"			"<<endl;
	cout<<"            12                                   4       					"<<endl;
	cout<<"     "<<ZG<<"                                            	"<<F<<"			"<<endl;
	cout<<"         28                                        21    					"<<endl;
	cout<<"   "<<ZF<<"                                             	  "<<G<<"				"<<endl;
	cout<<"       7                                              2          			"<<endl;
	cout<<" "<<ZE<<"                                                	   				"<<endl;
	cout<<"     29                                                25   "<<H<<"			"<<endl;
	cout<<"                                                  	        				"<<endl;
	cout<<"                                              	                			"<<endl;
	cout<<""<<ZD<<"  18                                                    17  "<<I<<"	"<<endl;
	cout<<"                                                                 			"<<endl;
	cout<<""<<ZC<<" 22                                                     				"<<endl;
	cout<<"                                                          34  "<<J<<"			"<<endl;
	cout<<""<<ZB<<" 9                                                        			"<<endl;
	cout<<"      	                                                  					"<<endl;
	cout<<""<<ZA<<"  31                                                      6  	"<<endl;
	cout<<"                                                              "<<K<<"		"<<endl;
	cout<<" "<<Z<<"  14                                                  			"<<endl;
	cout<<"  	                                            	 27  				"<<endl;
	cout<<"     20                                                      "<<L<<"				"<<endl;
	cout<<"  "<<Y<<"                                                    13  				"<<endl;
	cout<<"       1                                          	  "<<M<<"   				"<<endl;
	cout<<"    "<<X<<"                                                36    				"<<endl;
	cout<<"         33                                    	            				"<<endl;
	cout<<"      "<<W<<"                                           11      "<<N<<" 		"<<endl;
	cout<<"            16                             	        						"<<endl;
	cout<<"         "<<V<<"                                   30     "<<O<<"      		"<<endl;
	cout<<"                  24                      8       	     					"<<endl;
	cout<<"                       5           23           "<<P<<"   					"<<endl;
	cout<<"               "<<U<<"            10             "<<Q<<"   					"<<endl;
	cout<<"                    "<<T<<"               "<<R<<"           					"<<endl;
	cout<<"                             "<<S<<"											"<<endl;
	
	
}

void menuPrincipalConRangoSeleccionado(int tl, int vector36[], int desde, int hasta){
	int entrar;
	tl=hasta-desde;
	do{
		do{	
			
			cout<<"\n\n\n\t\t\t\t       ษออออออออออออออออออออออออออออออออออป"<<endl;
			cout<<"\t\t\t\t       บRANGO SELECCIONADO:  "<<desde<<" - "<<hasta<<"	  บ"<<endl;
			cout<<"\t\t\t\t      ษสออออออออออออออออออออออออออออออออออสป"<<endl;
			cout<<"\t\t\t\t      บ1.TOP 10 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ2.TOP 20 - NUMEROS QUE MAS SALIERON บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ3.TOP 36 - TODOS LOS NUMEROS        บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ4.VECES QUE SALIO UN NUMERO         บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ5.VER GRAFICA                       บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ6.VOLVER                            บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar;
			cin.clear ();
			fflush(stdin);
			if(entrar<1||entrar>6) {
				system("cls");
				cout<<"\t\t\aError: la seleccion solo puede ser 1 a 6. Reingrese por favor"<<endl;
			}
			
		} while(entrar<1||entrar>7);
		
		switch (entrar){
		case 1: system("cls");
			top10_funcion(vector36,tl); 
			system("pause"); 
			system("cls"); 
			break;
		case 2: system("cls"); 
			top20_funcion(vector36, tl); 
			system("pause"); 
			system("cls"); 
			break;
		case 3: system("cls");
			top36_funcion(vector36, tl);
			system("pause");
			system("cls");
			break;
		case 4:system("cls");
			vecesQueSalioUnNumero(vector36);
			system("pause"); 
			system("cls"); 
			break;
		case 5:system("cls");
			verGrafica(vector36);
			system("pause");
			system("cls");
			break;
			
		}
		
	} while(entrar!=6);
}

void verColores(int vector[], int tl){
	int cantRojos=0;
	int cantNegros=0;
	int cantCero=0;
	
	for(int i=0; i<tl; i++){
		if(vector[i]==1||vector[i]==3||vector[i]==5||vector[i]==7||vector[i]==9||vector[i]==12||vector[i]==14||vector[i]==16||vector[i]==18||vector[i]==19||vector[i]==21||vector[i]==23||vector[i]==25||vector[i]==27||vector[i]==30||vector[i]==32||vector[i]==34||vector[i]==36)
			cantRojos++;
		else if(vector[i]==0)
			cantCero++;
		else
			cantNegros++;
	}
	cout<<"CANTIDAD DE VECES QUE SALIO:		ROJO	NEGRO	CERO"<<endl<<endl;
	cout<<"\t\t\t\t\t "<<cantRojos<<"\t "<<cantNegros<<"\t "<<cantCero<<endl<<endl;
	
	system("pause");
	system("cls");
	
	cout<<"ROJOS	NEGROS	CERO"<<endl<<endl;
	
	for(int i=0; i<tl; i++){
		int contador=0;
		if(vector[i]==1||vector[i]==3||vector[i]==5||vector[i]==7||vector[i]==9||vector[i]==12||vector[i]==14||vector[i]==16||vector[i]==18||vector[i]==19||vector[i]==21||vector[i]==23||vector[i]==25||vector[i]==27||vector[i]==30||vector[i]==32||vector[i]==34||vector[i]==36){
			contador++;
			for(int j=1; j<50; j++){
				if(vector[i-j]>=0){
					if(vector[i-j]==1||vector[i-j]==3||vector[i-j]==5||vector[i-j]==7||vector[i-j]==9||vector[i-j]==12||vector[i-j]==14||vector[i-j]==16||vector[i-j]==18||vector[i-j]==19||vector[i-j]==21||vector[i-j]==23||vector[i-j]==25||vector[i-j]==27||vector[i-j]==30||vector[i-j]==32||vector[i-j]==34||vector[i-j]==36)
						contador++;
					else
						j=50;
				}
			}
			cout<<contador<<" บ R บ   บ"<<endl;
			if(vector[i+1]!=0&&vector[i+1]!=1&&vector[i+1]!=3&&vector[i+1]!=5&&vector[i+1]!=7&&vector[i+1]!=9&&vector[i+1]!=12&&vector[i+1]!=14&&vector[i+1]!=16&&vector[i+1]!=18&&vector[i+1]!=19&&vector[i+1]!=21&&vector[i+1]!=23&&vector[i+1]!=25&&vector[i+1]!=27&&vector[i+1]!=30&&vector[i+1]!=32&&vector[i+1]!=34&&vector[i+1]!=36)
				cout<<"-----------"<<endl;
		}
		else if(vector[i]==0)
			cout<<"+ บ   บ   บ 0"<<endl;
		else{
			contador++;
			for(int j=1; j<50; j++){
				if(vector[i-j]>=0){
					if(vector[i-j]!=0&&vector[i-j]!=1&&vector[i-j]!=3&&vector[i-j]!=5&&vector[i-j]!=7&&vector[i-j]!=9&&vector[i-j]!=12&&vector[i-j]!=14&&vector[i-j]!=16&&vector[i-j]!=18&&vector[i-j]!=19&&vector[i-j]!=21&&vector[i-j]!=23&&vector[i-j]!=25&&vector[i-j]!=27&&vector[i-j]!=30&&vector[i-j]!=32&&vector[i-j]!=34&&vector[i-j]!=36)
						contador++;
					else
						j=50;
				}
			}
			cout<<contador<<" บ   บ N บ"<<endl;
			
		}
			
	}
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
