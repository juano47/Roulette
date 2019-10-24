//ruleta v5  agrega "TOP 36 - TODOS LOS NUMEROS"

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
void desdeHasta( int tl, int vector36[], int vector[], int &seleccion);
void vecesQueSalioUnNumero(int vector36[]);
void verGrafica(int vector36[]);

int main() {
	int tl=0;
	int vector[TAM];
	int vector36[TAM2];
	int entrar;
	bool continuarMenu=true;
	
	leerTodosLosNumeros(vector, tl);
	system ("color F0" );
	cout<<"\t\t\tBIENVENIDOS"<<endl<<endl;
	system("cls");
	cout<<"NTdhXrxxx.B$$$#d3xr.rrirr.r...irxxTTSz2zzYxr.....icr.rx......,        "<<endl;
	cout<<"GXjCrrrr...$$$B#IEz8T84Ujr.rrrxi.rlClCcrr...,,  ,rrr,...,,            "<<endl;
	cout<<"hTTxxY7rr..r$$$$$$$$BB$$$$B$$#$#NZI69U1T7r...,,,.xjrrr..,  .r       , "<<endl;
	cout<<"XjXllCicrrr,h$$$$$BB@I54EB$$$$$$$$$$$BRN43r.,,,,.ir.rriiriiI$T        "<<endl;
	cout<<"UfzXCrrrr..,.$$$$B$BBB$#@R##BB$BBB$$$$$$$#@4TirrxjT2#$$$$rx$$$6     , "<<endl;
	cout<<"2TTTjrrr.r.. T$$$$$B$BT@$$$$$$BB#@RB@9hRR##$$I4d6IN$$BTi..S$NN#h      "<<endl;
	cout<<"93l5zi:rrr...,Y$$$I$$$@#$$$$$$$$$$$$$##RRIE9B@Ndd9q464qRBI6x77z$$r    "<<endl;
	cout<<"Xz38T3rrrr....,r$$j1$$$$$$$B#B@I54S45hdN@##BB$B$B$$$$$BB#@dIN$I#$$f   "<<endl;
	cout<<"TT3jfjCrirr.r.r..q$$Z:3$$##RZ8TxYrr...rrrrrz$B@$$$$@3XXxY:S9XjN$$hr   "<<endl;
	cout<<"zz1Sz3ll7rrrric7.7$$$@BBRI61Xli:.rlS598fCXI$$$$B##IXcXXXTdd5d$$B      "<<endl;
	cout<<"8US3ST7jjiirYiXlrB$$$BI51ClxCi..q$$$$$$$$$$Br,$$@N8YXX3863R$$S        "<<endl;
	cout<<"hSGqT1133TllYC7xx$$$4XCTjjxx..C$$$B$$$$$$aTUr z$N9iXTS1ZB$$Y          "<<endl;
	cout<<"5T6851TjTljXTjTcT$$RCllirr..cB$$$$$$$$ai..Xdi SB@6Z@$$$$d.            "<<endl;
	cout<<"a45485TTTjxXlfTTxd$$$$BB@@R@$$$$$$N5r..rrrjNj X$@#N@3.             ,  "<<endl;
	cout<<"#qdU118TjjjjXzXxT:CzaRBB$$$$$BB91xr....rrr2Ia. ,, ,,.               , "<<endl;
	cout<<"9q643TjT73XjTTjjCjTfT38G9EhdINTjT8Z#Rqjjrr5#Zr .....r.                "<<endl;
	cout<<"@4h6a5GCxxzX3jll2151455S6qIIRZ2cjr:369ZTr.3#I. ,.rr...,         ,     "<<endl;
	cout<<"##RNGISqTT34zjTXxTU9UGSG6aEddIhXrr.rrxi:.rqBa. ,.r...r,               "<<endl;
	cout<<"RN$@Z6S9qXCTTcXCff2Tzf15q4IaIR#dIRI@NGS5Ed##RX.,.rr..r.             , "<<endl;
	cout<<"RI@##@9dGGTYTSjTjXiYj4R@IRI#BBB$$$$$$#aS9INBEY.,..rr,..,           ,  "<<endl;
	cout<<"@R@@B@@dI53XSTCYjT13aI@R#BBB$$$$$$$I$$di.,,,,,...rrr.,r,,             "<<endl;
	cout<<"@RIRd#BBNI5GfTjTT9IaRBB$#I4qRNR##$r BI ,,,,,,...rirrr..,              "<<endl;
	cout<<"B@@RRR#B$B#Rq5ZaUTT26aZNB@#R@@#N6dG,, ,,........rrrrr.r ,     ,     , "<<endl;
	cout<<"BBBBBBB$$$$$$$dI1TCjTzT2xz4IaZ97  ,.  ,........rrxrrr.r.   ,          "<<endl;
	cout<<"$$$$$$$$$$$TI$$IIIRT3zdBBaGU99IGjrrC  .........r:rr.r.,r, , ,     , , "<<endl;
	cout<<"$$$$$$$$$$3,  a$BB$B#B#$$$$$$$RjrX2r  .r.....rrrrrrrrr,..  , ,   ,    "<<endl;
	cout<<"$$$$$$$$$@rr.  $$$$$$$$$$$$$$BS.rjT  , .r.rrrrr.rrrrr.. . , , ,   ,   "<<endl;
	cout<<"$$$$$$$$$qY7,  q$B#$$$$$$$$$$#xr73, ..,,rrrrrr.rrrrrrr.,,, , , ,      "<<endl;
	cout<<"#@BB$$$$$Ii,   R$@@9c.xjEN#B4rYYX.  ... .irrrrr.rrrrrrr.  ,,,,, ,   , "<<endl;
	cout<<"RRN##$$$5.    ,$B#N#6i,.7a#Nr8Xr,    ..,,7rrrr...rrrrr..  ,,,,        "<<endl;
	cout<<"BB$$$#x,  ,,  c$#@@@ZTCTRB$T17.  ,,,,,., ri:irr.rrxrr.., ,,,,   ,   , "<<endl;
	cout<<"$$BU.    ,,,  C$NN@@q5TjI$dr.,  ,,,,,.,, .XTrr...:rrr.,, ,,,,  ,,, ,  "<<endl;
	cout<<"j.    ,,,,,,  #$@NB@6T5a4r,   ,,,,,,,,., .1Xcr..rrxrr., ,..,    ,,  , "<<endl;
	cout<<"   ,,,,,,,,, r$$#B#@R9C.    ,,,,,, ,,.,, ,7Cr..r.rrr..  ,.,  , ,,,    "<<endl;
	cout<<", ,,,,,,,,,  i$$$$$hY.    ,,,,,,,,,,,,.,, cTi....rirr,, .,  , ,,,,  , "<<endl;
	cout<<", ,,,,,,,,  .I$$$G.,   ,,,,,,,,,,,,,,..., .zr.....rr., ,,,,,,,,.,, ,  "<<endl;
	cout<<". ,,,,,,, ,.8Gi.    , ,,,,,,,,,,,,,,,,.,, .Xx.....rr.,  ,,,,,..., ,,, "<<endl;
	cout<<".,,,,,,,,..r.,  ,,,,,,,,..,,,,,,,,,,,,..,,,Xrr...rrr., r..,..r.. ,,,  "<<endl;
	cout<<". ......r..,,,,,,,,,,,,,,             ,,   ....,...,, ,r...,,,  ,,    "<<endl;
	system("pause");
	system("cls");
	system ("color 0F" );
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
			cout<<"\t\t\t\t      บ6.VER GRAFICA                       บ"<<endl;
			cout<<"\t\t\t\t      ฬออออออออออออออออออออออออออออออออออออน"<<endl;
			cout<<"\t\t\t\t      บ7.SALIR                             บ"<<endl;
			cout<<"\t\t\t\t      ศออออออออออออออออออออออออออออออออออออผ"<<endl;
			cout<<"\n\t\t\t\t        Ingrese una opcion: ";
			
			cin>>entrar;
			cin.clear ();
			fflush(stdin);
			if(entrar<1||entrar>7) {
				system("cls");
				cout<<"\t\t\aError: la seleccion solo puede ser 1 a 7. Reingrese por favor"<<endl;
			}
			
		} while(entrar<1||entrar>7);
	
	switch (entrar){
	case 1: system("cls");
		cargarVector36(vector, vector36, 0, tl);
		top10_funcion(vector36,tl); 
		system("pause"); 
		system("cls"); 
		break;
	case 2: system("cls"); 
		cargarVector36(vector, vector36, 0, tl);
		top20_funcion(vector36, tl); 
		system("pause"); 
		system("cls"); 
		break;
	case 3: system("cls");
		cargarVector36(vector, vector36, 0, tl);
			top36_funcion(vector36, tl);
			system("pause");
			system("cls");
			break;
	case 4: menuRangos(tl, vector36, vector);
		system("cls");
		break;
	case 5:system("cls");
		cargarVector36(vector, vector36, 0, tl);
		vecesQueSalioUnNumero(vector36);
		system("pause"); 
		system("cls"); 
		break;
	case 6:system("cls");
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
			top20_funcion(vector36, seleccion); 
			system("pause"); 
			system("cls"); 
			break;
		case 2:system("cls");
			ultimosXnumeros(tl, vector36, vector, seleccion);
			top20_funcion(vector36, seleccion); 
			system("pause"); 
			system("cls"); 
			break;
		case 3:system("cls");
			desdeHasta(tl, vector36, vector, seleccion);
			top20_funcion(vector36, seleccion); 
			system("pause"); 
			system("cls"); 
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

void desdeHasta( int tl, int vector36[], int vector[], int &seleccion){
	
	int hasta;
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
	seleccion=hasta-seleccion;
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
