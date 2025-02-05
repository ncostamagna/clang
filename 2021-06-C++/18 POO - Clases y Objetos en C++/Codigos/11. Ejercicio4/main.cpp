/*Ejercicio 4: Construir un programa que dada una serie de veh�culos caracterizados por
su marca, modelo y precio, imprima las propiedades del veh�culo m�s barato. Para ello, 
se deber�n leer por teclado las caracter�sticas de cada veh�culo y crear un clase que 
represente a cada uno de ellos.*/

#include <iostream>
#include "Vehiculo.h"
using namespace std;

int main(int argc, char** argv) {
	Vehiculo* coches;
	int numeroVehiculos,indiceBarato;
	string marca,modelo;
	float precio;
	
	cout<<"Digite el numero de vehiculos: ";
	cin>>numeroVehiculos;
	
	coches = new Vehiculo[numeroVehiculos]; //Arreglo de objetos
	
	for(int i=0;i<numeroVehiculos;i++){
		cout<<"\nDigite los datos del Vehiculo "<<(i+1)<<": "<<endl;
		cin.ignore();
		cout<<"Digite la marca: ";
		getline(cin,marca);
		cout<<"Digite el modelo: ";
		getline(cin,modelo);
		cout<<"Digite el precio: ";
		cin>>precio;
		
		coches[i] = Vehiculo(marca,modelo,precio);
	}
	
	indiceBarato = Vehiculo::indiceMBarato(coches,numeroVehiculos);
	
	cout<<"\nEl Vehiculo mas barato es: "<<endl;
	(coches+indiceBarato)->mostrarDatos();
	//coches[indiceBarato].mostrarDatos();
	
	delete[] coches;	
	return 0;
}
