//ruleta v1.1 JUGADAS CONSECUTIVAS DESDE CUALQUIER MOMENTO CON CONDICIONES ESPECIALES PARA EMPEZAR A APOSTAR

#include <iostream>
#include <fstream>
#define TAM 10000
#include <cstdlib>
#define TAM2 37

using namespace std;

int main() {
	int tl=0;
	int vector[TAM];
	
	
	
	
	//-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.
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
		if(bandera)
			cout<<"CUIDADO! HAY NUMEROS MAYORES QUE 36"<<endl<<endl;
	}
	archivoLectura.close();
	//-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.
	int vectorAux[TAM];
	for(int i=0; i<tl; i++)
		vectorAux[i]=vector[i];
	
	int maximoNegativo1_general=0;
	int maximoNegativo2_general=0;
	int cantidadTiros1_general=0;
	int cantidadTiros2_general=0;
	
	//SE JUEGA AL *NEGRO* CONTINUAMENTE
	cout<<"SE JUEGA AL NEGRO CONTINUAMENTE"<<endl<<endl;
	
	int maximoNegativo1=0;
	int maximoNegativo2=0;
	int positivo1;		//suma 1 si salio un negro y resta 1 en otro caso. para un for interior
	int positivo2;	
	int cantidad=0;		//cuenta cuantos negros seguidos salieron
	int cantidadTiros;  //cantidad de jugadas antes de lograr ganancias
	
	int cantidadEsperada=7;	//elige la cantidad de por ejemplo cuantos rojos seguidos esperar antes de empezar a apostar al negro
	
	for(int contador=0; contador<tl; contador++){
		//si es negro
		if(vectorAux[contador]==2||vectorAux[contador]==4||vectorAux[contador]==6||vectorAux[contador]==8||vectorAux[contador]==10||vectorAux[contador]==11||vectorAux[contador]==13||vectorAux[contador]==15||vectorAux[contador]==17||vectorAux[contador]==20||vectorAux[contador]==22||vectorAux[contador]==24||vectorAux[contador]==26||vectorAux[contador]==28||vectorAux[contador]==29||vectorAux[contador]==31||vectorAux[contador]==33||vectorAux[contador]==35){
			
			cantidad=0; //resetea la cantidad de rojos seguidos que salen si sale un negro en el medio
			
		}
		else{
			cantidad++;	//suma 1 por cada ROJO consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vectorAux[i]==2||vectorAux[i]==4||vectorAux[i]==6||vectorAux[i]==8||vectorAux[i]==10||vectorAux[i]==11||vectorAux[i]==13||vectorAux[i]==15||vectorAux[i]==17||vectorAux[i]==20||vectorAux[i]==22||vectorAux[i]==24||vectorAux[i]==26||vectorAux[i]==28||vectorAux[i]==29||vectorAux[i]==31||vectorAux[i]==33||vectorAux[i]==35)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vectorAux[i]==2||vectorAux[i]==4||vectorAux[i]==6||vectorAux[i]==8||vectorAux[i]==10||vectorAux[i]==11||vectorAux[i]==13||vectorAux[i]==15||vectorAux[i]==17||vectorAux[i]==20||vectorAux[i]==22||vectorAux[i]==24||vectorAux[i]==26||vectorAux[i]==28||vectorAux[i]==29||vectorAux[i]==31||vectorAux[i]==33||vectorAux[i]==35)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl;
	
	
	//SE JUEGA AL *ROJO* CONTINUAMENTE
	cout<<endl<<endl<<"SE JUEGA AL ROJO CONTINUAMENTE"<<endl<<endl;
	
	maximoNegativo1=0;
	maximoNegativo2=0;
	cantidad=0;	
	
	for(int contador=0; contador<tl; contador++){
		//si es rojo
		if(vectorAux[contador]==1||vectorAux[contador]==3||vectorAux[contador]==5||vectorAux[contador]==7||vectorAux[contador]==9||vectorAux[contador]==12||vectorAux[contador]==14||vectorAux[contador]==16||vectorAux[contador]==18||vectorAux[contador]==19||vectorAux[contador]==21||vectorAux[contador]==23||vectorAux[contador]==25||vectorAux[contador]==27||vectorAux[contador]==30||vectorAux[contador]==32||vectorAux[contador]==34||vectorAux[contador]==36){
			cantidad=0; //resetea la cantidad de negros seguidos que salen si sale un rojo en el medio
		}
		else{
			cantidad++;	//suma 1 por cada NEGRO consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vectorAux[i]==1||vectorAux[i]==3||vectorAux[i]==5||vectorAux[i]==7||vectorAux[i]==9||vectorAux[i]==12||vectorAux[i]==14||vectorAux[i]==16||vectorAux[i]==18||vectorAux[i]==19||vectorAux[i]==21||vectorAux[i]==23||vectorAux[i]==25||vectorAux[i]==27||vectorAux[i]==30||vectorAux[i]==32||vectorAux[i]==34||vectorAux[i]==36)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vectorAux[i]==1||vectorAux[i]==3||vectorAux[i]==5||vectorAux[i]==7||vectorAux[i]==9||vectorAux[i]==12||vectorAux[i]==14||vectorAux[i]==16||vectorAux[i]==18||vectorAux[i]==19||vectorAux[i]==21||vectorAux[i]==23||vectorAux[i]==25||vectorAux[i]==27||vectorAux[i]==30||vectorAux[i]==32||vectorAux[i]==34||vectorAux[i]==36)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl;
	
	cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
	
	//SE JUEGA A *PAR* CONTINUAMENTE
	cout<<endl<<endl<<"SE JUEGA A PAR CONTINUAMENTE"<<endl<<endl;
	
	maximoNegativo1=0;
	maximoNegativo2=0;
	cantidad=0;	
	
	for(int contador=0; contador<tl; contador++){
		//si es par
		if(vector[contador]%2==0&&vector[contador]!=0){
			cantidad=0; //resetea la cantidad de impares seguidos que salen si sale un par en el medio
		}
		else{
			cantidad++;	//suma 1 por cada IMPAR consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]%2==0&&vector[i]!=0)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]%2==0&&vector[i]!=0)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl;
	
	
	//SE JUEGA A *IMPAR* CONTINUAMENTE
	cout<<endl<<endl<<"SE JUEGA A IMPAR CONTINUAMENTE"<<endl<<endl;
	maximoNegativo1=0;
	maximoNegativo2=0;
	cantidad=0;	
	
	for(int contador=0; contador<tl; contador++){
		
		//si es impar
		if(vector[contador]%2!=0){
			cantidad=0; //resetea la cantidad de pares seguidos que salen si sale un impar en el medio
		}
		else{
			cantidad++;	//suma 1 por cada PAR consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]%2!=0)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]%2!=0)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl;
	
	cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
	
	//SE JUEGA A *MENOR* CONTINUAMENTE
	cout<<endl<<endl<<"SE JUEGA A MENOR CONTINUAMENTE"<<endl<<endl;
	
	maximoNegativo1=0;
	maximoNegativo2=0;
	cantidad=0;	
	
	for(int contador=0; contador<tl; contador++){
		
		//si es menor
		if(vector[contador]<=18 && vector[contador]!=0){
			cantidad=0; //resetea la cantidad de mayores seguidos que salen si sale un menor en el medio
		}
		else{
			cantidad++;	//suma 1 por cada MAYOR consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]<=18 && vector[i]!=0)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]<=18 && vector[i]!=0)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl;
	
	
	//SE JUEGA A *MAYOR* CONTINUAMENTE
	cout<<endl<<endl<<"SE JUEGA A MAYOR CONTINUAMENTE"<<endl<<endl;
	maximoNegativo1=0;
	maximoNegativo2=0;
	cantidad=0;	
	
	for(int contador=0; contador<tl; contador++){
		
		//si es mayor
		if(vector[contador]>18){
			cantidad=0; //resetea la cantidad de menores seguidos que salen si sale un mayor en el medio
		}
		else{
			cantidad++;	//suma 1 por cada MENOR consecutivo
			
		}
		if(cantidad==cantidadEsperada){
			positivo1=0;
			positivo2=0;
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]>18)
				{
					positivo1++;
					
				}
				else
					positivo1--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 1 ganancia
				if(positivo1<maximoNegativo1)
					maximoNegativo1=positivo1;
				//fijo maxima perdida GENERAL para 1 ganancia
				if(positivo1<maximoNegativo1_general)
					maximoNegativo1_general=positivo1;
				
				//fijo cantidad de tiros GENERAL para 1 ganancia
				if(cantidadTiros>cantidadTiros1_general)
					cantidadTiros1_general=cantidadTiros;
				
				if(positivo1==1){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 1 ganancia: "<<cantidadTiros<<endl;
				}
			}
			
			
			cantidadTiros=0;
			for(int i=contador+1; i<tl; i++){
				if(vector[i]>18)
				{
					positivo2++;
				}
				else
					positivo2--;
				cantidadTiros++;
				
				//fijo maxima perdida general apostando a 2 ganancia
				if(positivo2<maximoNegativo2)
					maximoNegativo2=positivo2;
				//fijo maxima perdida GENERAL para 2 ganancias
				if(positivo2<maximoNegativo2_general)
					maximoNegativo2_general=positivo2;
				
				//fijo cantidad de tiros GENERAL para 2 ganancias
				if(cantidadTiros>cantidadTiros2_general)
					cantidadTiros2_general=cantidadTiros;
				
				if(positivo2==2){
					i=tl; //sale del for
					cout<<"Cantidad de tiros para 2 ganancia: "<<cantidadTiros<<endl<<endl;
				}
			}
			
		}
		
	}
	cout<<endl<<endl<<"MAXIMO NEGATIVO PARA 1 GANANCIA: "<<maximoNegativo1<<endl<<endl;
	cout<<"MAXIMO NEGATIVO PARA 2 GANANCIA: "<<maximoNegativo2<<endl<<endl<<endl;
	
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<endl<<"MAXIMA CANTIDAD DE TIROS PARA 1 GANANCIA: "<<cantidadTiros1_general<<endl;
	cout<<endl<<"MAXIMA CANTIDAD DE TIROS PARA 2 GANANCIAS: "<<cantidadTiros2_general<<endl;
	cout<<endl<<endl<<"MAXIMO NEGATIVO GENERAL PARA 1 GANANCIA: "<<maximoNegativo1_general<<endl<<endl;
	cout<<"MAXIMO NEGATIVO GENERAL PARA 2 GANANCIAS: "<<maximoNegativo2_general<<endl<<endl;
	
	/*
	//vimos que los maximos negativos son altisimos por lo que no tiene sentido analizar docenas y columnas
	
	//SE JUEGA A *1 DOCENA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 1 docena
	if(vector[contador]>0&&vector[contador]<=12){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 1 DOCENA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *2 DOCENA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 2 docena
	if(vector[contador]>12&&vector[contador]<=24){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 2 DOCENA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *3 DOCENA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 3 docena
	if(vector[contador]>24){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 3 DOCENA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *1 COLUMNA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 1 columna
	if(vector[contador]%3==1){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 1 COLUMNA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *2 COLUMNA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 2 columna
	if(vector[contador]%3==2){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 2 COLUMNA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *3 COLUMNA* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
	//si es 3 columna
	if(vector[contador]%3==0&&vector[contador]!=0){
	ganancia++;
	if(ganancia>maximoPositivo)
	maximoPositivo=ganancia;
	}
	else{
	ganancia--;
	if(ganancia<maximoNegativo)
	maximoNegativo=ganancia;
	}
	}
	cout<<endl<<endl<<"SE JUEGA A 3 COLUMNA CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	*/
	
	system("pause");
	return 0;
}

