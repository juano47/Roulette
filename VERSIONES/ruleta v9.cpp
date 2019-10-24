//ruleta v9  agrega DOCENAS / DOCENAS INVERSO

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
#include <string>
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
void zonasOptimas(int vector36[]);
void analisisManual(int vector36[], int vector[], int tl);
void analisisAutomatico(int vector36[], int vector[], int tl);
void analisisAutomaticoAux(int vector36[], int vector[], int tl, int cantNumeros, int cantJugadas, int vecesQsale);
void docenas(int vector[], int tl);

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
			cout<<"\t\t\t\t      บ9.DOCENAS INVERSO                   บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ10.COLUMNAS                         บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ11.VER GRAFICA                      บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ12.ZONAS OPTIMAS                    บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ13.ANALISIS MANUAL                  บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ14.ANALISIS AUTOMATICO              บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ15.SALIR                            บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar;
			cin.clear ();
			fflush(stdin);
			if(entrar<1||entrar>15) {
				system("cls");
				cout<<"\t\t\aError: la seleccion solo puede ser 1 a 15. Reingrese por favor"<<endl;
			}
			
		} while(entrar<1||entrar>15);
		
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
		case 8:  //DOCENAS
			system("cls");
			docenas(vector, tl);
			system("pause");
			system("cls");
			break;
		case 11: //VER GRAFICA
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			verGrafica(vector36);
			system("pause");
			system("cls");
			break;
		case 12: //ZONAS OPTIMAS
			system("cls");
			cargarVector36(vector, vector36, 0, tl);
			zonasOptimas(vector36);
			system("pause");
			system("cls");
			break;
		case 13: //ANALISIS MANUAL
			system("cls");
			analisisManual(vector36, vector, tl);
			system("cls");
			break;
		case 14: //ANALISIS AUTOMATICO
			system("cls");
			analisisAutomatico(vector36, vector, tl);
			system("pause");
			system("cls");
			break;
		case 15: if (Salir()){ // si deseaSalir es verdadera, entonces no se debe continuar con la ejecucion del programa.
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

void zonasOptimas(int vector36[]){
	
	int seleccion;
	int vectorOrdenadoRuleta[TAM2];  //vector ordenado segun la ubicacion de los numeros en la ruleta.
	int vectorZonasOptimas[TAM2];

	string stringZonas[TAM2];
	string stringRuleta[]={"0","32","15","19","4","21","2","25","17","34","6","27","13","36","11","30","8","23","10","5","24","16","33","1","20","14","31","9","22","18","29","7","28","12","35","3","26"};
		
	do{
		cout<<"DEFINA EL TAMANIO DE ZONA OPTIMA: ";
		cin>>seleccion;
		cin.clear ();
		fflush(stdin);
		if(seleccion>37){
			system("cls");
			cout<<"\aError -> El numero ingresado debe ser menor a 37. Ingrese un numero menor a este valor."<<endl<<endl;
		}
	}while(seleccion>37);
	
	//completar vectorOrdenadoRuleta con los valores de vector36
	
	vectorOrdenadoRuleta[0]=vector36[0];
	vectorOrdenadoRuleta[1]=vector36[32];
	vectorOrdenadoRuleta[2]=vector36[15];
	vectorOrdenadoRuleta[3]=vector36[19];
	vectorOrdenadoRuleta[4]=vector36[4];
	vectorOrdenadoRuleta[5]=vector36[21];
	vectorOrdenadoRuleta[6]=vector36[2];
	vectorOrdenadoRuleta[7]=vector36[25];
	vectorOrdenadoRuleta[8]=vector36[17];
	vectorOrdenadoRuleta[9]=vector36[34];
	vectorOrdenadoRuleta[10]=vector36[6];
	vectorOrdenadoRuleta[11]=vector36[27];
	vectorOrdenadoRuleta[12]=vector36[13];
	vectorOrdenadoRuleta[13]=vector36[36];
	vectorOrdenadoRuleta[14]=vector36[11];
	vectorOrdenadoRuleta[15]=vector36[30];
	vectorOrdenadoRuleta[16]=vector36[8];
	vectorOrdenadoRuleta[17]=vector36[23];
	vectorOrdenadoRuleta[18]=vector36[10];
	vectorOrdenadoRuleta[19]=vector36[5];
	vectorOrdenadoRuleta[20]=vector36[24];
	vectorOrdenadoRuleta[21]=vector36[16];
	vectorOrdenadoRuleta[22]=vector36[33];
	vectorOrdenadoRuleta[23]=vector36[1];
	vectorOrdenadoRuleta[24]=vector36[20];
	vectorOrdenadoRuleta[25]=vector36[14];
	vectorOrdenadoRuleta[26]=vector36[31];
	vectorOrdenadoRuleta[27]=vector36[9];
	vectorOrdenadoRuleta[28]=vector36[22];
	vectorOrdenadoRuleta[29]=vector36[18];
	vectorOrdenadoRuleta[30]=vector36[29];
	vectorOrdenadoRuleta[31]=vector36[7];
	vectorOrdenadoRuleta[32]=vector36[28];
	vectorOrdenadoRuleta[33]=vector36[12];
	vectorOrdenadoRuleta[34]=vector36[35];
	vectorOrdenadoRuleta[35]=vector36[3];
	vectorOrdenadoRuleta[36]=vector36[26];
	
	
	int contador=seleccion;
	int posicionEnVector=0; //posicion que se usa para moverse en vectorOrdenadoRuleta
	int pos=0; //posicion que se usa para ir colocando las sumas de las zonas en vectorZonasOptimas
	
	//no importa que tama๑o tenga cada zona optima, siempre van a ser 37 zonas.
	
	for(int i=0; i<(37-seleccion+1); i++){	//37-seleccion+1 son las sublistas posibles con vector no ciclico
		int suma=0;
		string zona= "";
		zona=zona + stringRuleta[posicionEnVector];
		for(contador; contador!=0; contador--){
			suma=suma + vectorOrdenadoRuleta[posicionEnVector];
			
			posicionEnVector++;
			if(contador!=1)
			zona=zona + " - " + stringRuleta[posicionEnVector];
		}
		vectorZonasOptimas[pos]=suma;
		pos++;
		posicionEnVector= pos;
		contador=seleccion;
		stringZonas[i]=zona;
	}
	
	int iteraciones=1;
	//completamos las zonas que se obtienen uniendo los extremos del vectorOrdenadoRuleta
	for(pos; pos <37; pos++){
		int suma=0;
		string zona= "";
		posicionEnVector=pos;
		
		while(posicionEnVector!=37){
			suma=suma+vectorOrdenadoRuleta[posicionEnVector];
			posicionEnVector++;
		}
		
		for(int i=0; i<iteraciones; i++){
			suma=suma+vectorOrdenadoRuleta[i];
		}
		iteraciones++;
		vectorZonasOptimas[pos]=suma;
		
	}
	
	cout<<"ZONAS OPTIMAS"<<endl<<endl;
	for(int i=0; i<37; i++){
		cout<<vectorZonasOptimas[i]<<endl;
		cout<< stringZonas[i]<<endl;
	}
}

void analisisManual(int vector36[], int vector[], int tl){
	
	//vector tiene cargados todos los numeros del archivo txt
	int vecesQsalioRealVector[100];
	int tlQ;
	int cantNumeros, cantJugadas, vecesQsale, hasta, bandera, max, cantInicial, ganancia, vecesQsalioReal, 
		posUltimaSalida, gananciaTotal, cantCero, cantUno, cantDos, cantTres, cantCuatro,cantCinco,cantSeis,cantSiete,
		vecesQsalioCuentaTotal,vecesQsalioSumaTotal;
	
	cout<<"Indique la cantidad de numeros a analizar: ";
	cin>>cantNumeros;
	cout<<"Indique la cantidad de jugadas a apostar: ";
	cin>>cantJugadas;
	cout<<"Indique cuantas veces espera que salga el numero: ";
	cin>>vecesQsale;
	
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	cout<<"| NUMERO |"<<"\t\t| CANTIDAD INICIAL |"<<"\t| VECES QUE SALIO |"<<"\t| GANANCIA |"<<endl;
	cout<<"+--------+--------------+-----------------+-----+------------+--+------------------+"<<endl;
	
	int contador=0;
	gananciaTotal=0;
	cantCero=0;
	cantUno=0;
	cantDos=0;
	cantTres=0;
	cantCuatro=0;
	cantCinco=0;
	cantSeis=0;
	cantSiete=0;
	vecesQsalioSumaTotal=0;
	
	while((cantNumeros+contador+cantJugadas)<=tl){
		hasta= contador+cantNumeros;
		cargarVector36(vector, vector36, contador, hasta);
		int maximo=-1;
		for(int k=0; k<TAM2; k++){
			if(vector36[k]>=maximo){
				maximo=vector36[k];
				max=k;
				
			}
		}
		contador++;
		cantInicial=vector36[max];
		cargarVector36(vector,vector36,hasta,(hasta+cantJugadas+1));
		
		bandera=0;
		vecesQsalioReal=0;
		vecesQsalioCuentaTotal=0;
		posUltimaSalida=cantJugadas;		//valor maximo que puede tomar, perdida total, se inicializa previniendo que no se entre al if mas abajo
		
		ganancia=0;
		tlQ=0;
		//--------CUENTA CUANTAS VECES SALIO MAX----------
		for(int i=(hasta); i<(hasta+1+cantJugadas);i++){
			if(vector[i]==max){
				vecesQsalioReal++;
				if((i-hasta)<=36){
					vecesQsalioRealVector[tlQ]=36;
					tlQ++;
				}
				else if((i-hasta)>36 && (i-hasta)<=54){
					vecesQsalioRealVector[tlQ]=54;
					tlQ++;
				}
				else if((i-hasta)>54 && (i-hasta)<=66){
					vecesQsalioRealVector[tlQ]=66;
					tlQ++;
				}
				else{
					vecesQsalioRealVector[tlQ]=75;
					tlQ++;
				}
				if(vecesQsalioReal==vecesQsale){ //solo cuenta hasta "vecesQsale"
					posUltimaSalida=i-hasta;
					i=hasta+1+cantJugadas+1;	//salida forzada del for
				}
			}
		}
		//cuenta de nuevo para completar "CANTIDAD DE.."
		for(int i=(hasta); i<(hasta+1+cantJugadas);i++)
			if(vector[i]==max)
				vecesQsalioCuentaTotal++;
		//----------------------------------------------
		
		//-----------CALCULO DE GANANCIAS---------------
		for(int i=0; i<tlQ; i++){
			if(vecesQsalioRealVector[i]==36){
				ganancia=ganancia+36;
			}
			else if(vecesQsalioRealVector[i]==54)
				ganancia=ganancia+72;
			else if(vecesQsalioRealVector[i]==66)
				ganancia=ganancia+108;
			else
				ganancia=ganancia+144;
		}
		if(posUltimaSalida<=36)
			ganancia=36*vecesQsalioReal-posUltimaSalida;
		else if(posUltimaSalida>36 && posUltimaSalida<=54)
			ganancia=ganancia-36-(posUltimaSalida-36)*2;
		else if(posUltimaSalida>54 && posUltimaSalida<=66)
			ganancia=ganancia-72-(posUltimaSalida-54)*3;
		else
			ganancia=ganancia-108-(posUltimaSalida-66)*4;
		//--------------------------------------------------
		
		gananciaTotal= gananciaTotal+ganancia;
		vecesQsalioSumaTotal=vecesQsalioSumaTotal+vecesQsalioCuentaTotal;
		cout<<"  "<<max<<"\t\t\t\t"<<cantInicial<<"\t\t\t"<<vector36[max]<<"\t\t\t"<<ganancia<<endl; 
	
		switch(vecesQsalioCuentaTotal){
		case 0: cantCero++; break;
		case 1: cantUno++; break;
		case 2: cantDos++; break;
		case 3: cantTres++; break;
		case 4: cantCuatro++; break;
		case 5: cantCinco++; break;
		case 6: cantSeis++; break;
		case 7: cantSiete++; break;
		}
	}
	system("pause");
	cout<<endl<<endl<<"GANANCIA TOTAL -> "<<gananciaTotal<<endl<<endl;
	cout<<"CANTIDAD DE CEROS ->\t"<<cantCero<<"\t"<<cantCero*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE UNOS ->\t"<<cantUno<<"\t"<<cantUno*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE DOS ->\t"<<cantDos<<"\t"<<cantDos*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE TRES ->\t"<<cantTres<<"\t"<<cantTres*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE CUATRO ->\t"<<cantCuatro<<"\t"<<cantCuatro*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE CINCO ->\t"<<cantCinco<<"\t"<<cantCinco*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE SEIS ->\t"<<cantSeis<<"\t"<<cantSeis*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE SIETE ->\t"<<cantSiete<<"\t"<<cantSiete*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	Sleep(1500);
	system("pause");
}
void analisisAutomatico(int vector36[], int vector[], int tl){
	int cantNumeros, cantJugadas, vecesQsale;
	
	cout<<endl<<"\t\t-----ANALISIS AUTOMATICO-----"<<endl<<endl;
	cantJugadas=36;
	
		for(cantNumeros=100; cantNumeros<300; cantNumeros=cantNumeros+100){
			for(vecesQsale=1; vecesQsale<=3; vecesQsale++){
				cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - "<<vecesQsale<<" APUESTAS GANADORAS"<<endl;
				cout<<"-------------------------------------------------------------------------------"<<endl;
				analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, vecesQsale);
			}
			cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - 10 APUESTAS GANADORAS"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, 10);
		}
		
		cantJugadas=54;
		
		for(cantNumeros=100; cantNumeros<300; cantNumeros=cantNumeros+100){
			for(vecesQsale=1; vecesQsale<=3; vecesQsale++){
				cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - "<<vecesQsale<<" APUESTAS GANADORAS"<<endl;
				cout<<"-------------------------------------------------------------------------------"<<endl;
				analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, vecesQsale);
			}
			cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - 10 APUESTAS GANADORAS"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, 10);
		}
		
		cantJugadas=66;
		
		for(cantNumeros=100; cantNumeros<300; cantNumeros=cantNumeros+100){
			for(vecesQsale=1; vecesQsale<=3; vecesQsale++){
				cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - "<<vecesQsale<<" APUESTAS GANADORAS"<<endl;
				cout<<"-------------------------------------------------------------------------------"<<endl;
				analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, vecesQsale);
			}
			cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - 10 APUESTAS GANADORAS"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, 10);
		}
	
		cantJugadas=75;
		
		for(cantNumeros=100; cantNumeros<300; cantNumeros=cantNumeros+100){
			for(vecesQsale=1; vecesQsale<=3; vecesQsale++){
				cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - "<<vecesQsale<<" APUESTAS GANADORAS"<<endl;
				cout<<"-------------------------------------------------------------------------------"<<endl;
				analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, vecesQsale);
			}
			cout<<endl<<"ANALISIS PARA: "<<cantNumeros<<" TIROS - "<<cantJugadas<<" APUESTAS A REALIZAR - 10 APUESTAS GANADORAS"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			analisisAutomaticoAux(vector36, vector, tl, cantNumeros, cantJugadas, 10);
		}
		system("pause");
		Sleep(1500);
		system("pause");
}
void analisisAutomaticoAux(int vector36[], int vector[], int tl, int cantNumeros, int cantJugadas, int vecesQsale){
	
	//vector tiene cargados todos los numeros del archivo txt
	int vecesQsalioRealVector[100];
	int tlQ;
	int hasta, bandera, max, cantInicial, ganancia, vecesQsalioReal, 
		posUltimaSalida, gananciaTotal, cantCero, cantUno, cantDos, cantTres, cantCuatro,cantCinco,cantSeis,cantSiete,
		vecesQsalioCuentaTotal,vecesQsalioSumaTotal;
	
	int contador=0;
	gananciaTotal=0;
	cantCero=0;
	cantUno=0;
	cantDos=0;
	cantTres=0;
	cantCuatro=0;
	cantCinco=0;
	cantSeis=0;
	cantSiete=0;
	vecesQsalioSumaTotal=0;
	
	while((cantNumeros+contador+cantJugadas)<=tl){
		hasta= contador+cantNumeros;
		cargarVector36(vector, vector36, contador, hasta);
		int maximo=-1;
		for(int k=0; k<TAM2; k++){
			if(vector36[k]>=maximo){
				maximo=vector36[k];
				max=k;
				
			}
		}
		contador++;
		cantInicial=vector36[max];
		cargarVector36(vector,vector36,hasta,(hasta+cantJugadas+1));
		
		bandera=0;
		vecesQsalioReal=0;
		vecesQsalioCuentaTotal=0;
		posUltimaSalida=cantJugadas;		//valor maximo que puede tomar, perdida total, se inicializa previniendo que no se entre al if mas abajo
		
		ganancia=0;
		tlQ=0;
		//--------CUENTA CUANTAS VECES SALIO MAX----------
		for(int i=(hasta); i<(hasta+1+cantJugadas);i++){
			if(vector[i]==max){
				vecesQsalioReal++;
				if((i-hasta)<=36){
					vecesQsalioRealVector[tlQ]=36;
					tlQ++;
				}
				else if((i-hasta)>36 && (i-hasta)<=54){
					vecesQsalioRealVector[tlQ]=54;
					tlQ++;
				}
				else if((i-hasta)>54 && (i-hasta)<=66){
					vecesQsalioRealVector[tlQ]=66;
					tlQ++;
				}
				else{
					vecesQsalioRealVector[tlQ]=75;
					tlQ++;
				}
				if(vecesQsalioReal==vecesQsale){ //solo cuenta hasta "vecesQsale"
					posUltimaSalida=i-hasta;
					i=hasta+1+cantJugadas+1;	//salida forzada del for
				}
			}
		}
		//cuenta de nuevo para completar "CANTIDAD DE.."
		for(int i=(hasta); i<(hasta+1+cantJugadas);i++)
			if(vector[i]==max)
			vecesQsalioCuentaTotal++;
		//----------------------------------------------
		
		//-----------CALCULO DE GANANCIAS---------------
		for(int i=0; i<tlQ; i++){
			if(vecesQsalioRealVector[i]==36){
				ganancia=ganancia+36;
			}
			else if(vecesQsalioRealVector[i]==54)
				ganancia=ganancia+72;
			else if(vecesQsalioRealVector[i]==66)
				ganancia=ganancia+108;
			else
				ganancia=ganancia+144;
		}
		if(posUltimaSalida<=36)
			ganancia=36*vecesQsalioReal-posUltimaSalida;
		else if(posUltimaSalida>36 && posUltimaSalida<=54)
			ganancia=ganancia-36-(posUltimaSalida-36)*2;
		else if(posUltimaSalida>54 && posUltimaSalida<=66)
			ganancia=ganancia-72-(posUltimaSalida-54)*3;
		else
			ganancia=ganancia-108-(posUltimaSalida-66)*4;
		//--------------------------------------------------
		
		gananciaTotal= gananciaTotal+ganancia;
		vecesQsalioSumaTotal=vecesQsalioSumaTotal+vecesQsalioCuentaTotal;
		
		switch(vecesQsalioCuentaTotal){
		case 0: cantCero++; break;
		case 1: cantUno++; break;
		case 2: cantDos++; break;
		case 3: cantTres++; break;
		case 4: cantCuatro++; break;
		case 5: cantCinco++; break;
		case 6: cantSeis++; break;
		case 7: cantSiete++; break;
		}
	}
	
	cout<<endl<<endl<<"GANANCIA TOTAL -> "<<gananciaTotal<<endl<<endl;
	cout<<"CANTIDAD DE CEROS ->\t"<<cantCero<<"\t"<<cantCero*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE UNOS ->\t"<<cantUno<<"\t"<<cantUno*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE DOS ->\t"<<cantDos<<"\t"<<cantDos*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE TRES ->\t"<<cantTres<<"\t"<<cantTres*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE CUATRO ->\t"<<cantCuatro<<"\t"<<cantCuatro*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE CINCO ->\t"<<cantCinco<<"\t"<<cantCinco*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE SEIS ->\t"<<cantSeis<<"\t"<<cantSeis*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
	cout<<"CANTIDAD DE SIETE ->\t"<<cantSiete<<"\t"<<cantSiete*100.0/(vecesQsalioSumaTotal+cantCero)<<" %"<<endl<<endl;
}
void docenas(int vector[], int tl){
	int docena1=0;
	int docena2=0;
	int docena3=0;
	int cero=0;
	
	for(int i=0; i<tl; i++){
		if(vector[i]>0&&vector[i]<=12)
			docena1++;
		else if(vector[i]>12&&vector[i]<=24)
			docena2++;
		else if(vector[i]>24)
			docena3++;
		else
			cero++;
	}
	cout<<"CANTIDAD DE VECES QUE SALIO:		1 DOCENA	2 DOCENA	3 DOCENA	CERO"<<endl<<endl;
	cout<<"\t\t\t\t\t "<<docena1<<"\t\t "<<docena2<<"\t\t "<<docena3<<"\t\t "<<cero<<endl<<endl;
	
	system("pause");
	cout<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"1 DOCENA	2 DOCENA	3 DOCENA	CERO"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	//hacemos una copia de vector para no modificar el original
	int vectorAux[TAM];
	for(int i=0; i<tl; i++)
		vectorAux[i]=vector[i];
	
	bool bandera;
	int contador;
	
	while(tl>0){
		bandera= true;
		contador=0;
		while(bandera){
			if(contador<tl){
				if(vectorAux[contador]>0&& vectorAux[contador]<=12)
					contador++;
				else
					bandera=false;
			}
			else
				bandera=false;
		}
		//mostramos el contador para 1 DOCENA
		if(contador!=0){
			cout<<" "<<contador<<endl;
			//borramos las primeras posiciones que fueron contabilizadas
			for(int k=0; k<contador; k++){
				for(int j=0; j<tl-1; j++)
					vectorAux[j]=vectorAux[j+1];
				tl--;
			}
			
		}
		
		//si el contador=0 significa que se encontro con otra docena (2 o 3 docena)
		else{
			//cout<<"entramos joder!"<<endl;
			bandera=true;
			while(bandera){
				if(contador<tl){
					if(vectorAux[contador]>12&& vectorAux[contador]<=24)
						contador++;
					else
						bandera=false;
				}
				else
					bandera=false;
			}
			//mostramos el contador para 2 DOCENA
			if(contador!=0){
				cout<<"\t\t "<<contador<<endl;
				//borramos las primeras posiciones que fueron contabilizadas
				for(int k=0; k<contador; k++)
					for(int j=0; j<tl-1; j++)
						vectorAux[j]=vectorAux[j+1];
				tl=tl-contador;
			}
			//si el contador=0 se encontro con la 3 docena
			else{
				bandera=true;
				while(bandera){
					if(contador<tl){
						if(vectorAux[contador]>24)
							contador++;
						else
							bandera=false;
					}
					else
						bandera=false;
				}
				//mostramos el contador para 3 DOCENA
				if(contador!=0){
					cout<<"\t\t\t\t "<<contador<<endl;
					//borramos las primeras posiciones que fueron contabilizadas
					for(int k=0; k<contador; k++)
						for(int j=0; j<tl-1; j++)
							vectorAux[j]=vectorAux[j+1];
					tl=tl-contador;
				}
				//si el contador=0 se encontro con un cero
				else{
					bandera=true;
					while(bandera){
						if(contador<tl){
							if(vectorAux[contador]==0)
								contador++;
							else
								bandera=false;
						}
						else
							bandera=false;
					}
					//mostramos el contador para el CERO
					if(contador!=0){
						cout<<"\t\t\t\t\t\t "<<contador<<endl;
						//borramos las primeras posiciones que fueron contabilizadas
						for(int k=0; k<contador; k++)
							for(int j=0; j<tl-1; j++)
								vectorAux[j]=vectorAux[j+1];
						tl=tl-contador;
					}
				}
			}
		}
		cout<<"----------------------------------------------------"<<endl;
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
