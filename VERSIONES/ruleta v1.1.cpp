//ruleta v1.1 JUGADAS CONSECUTIVAS DESDE CUALQUIER MOMENTO SIN CONDICIONES ESPECIALES

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
	
	//SE JUEGA AL *NEGRO* CONTINUAMENTE
	int maximoNegativo=0;
	int maximoPositivo=0;
	
	int ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es negro
		if(vectorAux[contador]==2||vectorAux[contador]==4||vectorAux[contador]==6||vectorAux[contador]==8||vectorAux[contador]==10||vectorAux[contador]==11||vectorAux[contador]==13||vectorAux[contador]==15||vectorAux[contador]==17||vectorAux[contador]==20||vectorAux[contador]==22||vectorAux[contador]==24||vectorAux[contador]==26||vectorAux[contador]==28||vectorAux[contador]==29||vectorAux[contador]==31||vectorAux[contador]==33||vectorAux[contador]==35){
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
	cout<<"SE JUEGA AL NEGRO CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	//SE JUEGA AL *ROJO* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es rojo
		if(vectorAux[contador]==1||vectorAux[contador]==3||vectorAux[contador]==5||vectorAux[contador]==7||vectorAux[contador]==9||vectorAux[contador]==12||vectorAux[contador]==14||vectorAux[contador]==16||vectorAux[contador]==18||vectorAux[contador]==19||vectorAux[contador]==21||vectorAux[contador]==23||vectorAux[contador]==25||vectorAux[contador]==27||vectorAux[contador]==30||vectorAux[contador]==32||vectorAux[contador]==34||vectorAux[contador]==36){
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
	cout<<endl<<endl<<"SE JUEGA AL ROJO CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	//SE JUEGA A *PAR* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es par
		if(vector[contador]%2==0&&vector[contador]!=0){
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
	cout<<endl<<endl<<"SE JUEGA A PAR CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *IMPAR* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es impar
		if(vector[contador]%2!=0){
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
	cout<<endl<<endl<<"SE JUEGA A IMPAR CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *MENOR* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es menor
		if(vector[contador]<=18 && vector[contador]!=0){
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
	cout<<endl<<endl<<"SE JUEGA A MENOR CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
	
	//SE JUEGA A *MAYOR* CONTINUAMENTE
	maximoNegativo=0;
	maximoPositivo=0;
	
	ganancia=0;
	
	for(int contador=0; contador<tl; contador++){
		//si es mayor
		if(vector[contador]>18){
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
	cout<<endl<<endl<<"SE JUEGA A MAYOR CONTINUAMENTE"<<endl<<endl;
	cout<<"MAXIMO NEGATIVO: "<<maximoNegativo<<"\t\t MAXIMO POSITIVO: "<<maximoPositivo<<endl;
	
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

