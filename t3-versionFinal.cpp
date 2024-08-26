#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
using namespace std;

void interfazPrincipal();
void ingresar();
void consultar();
void eliminar();
void buscar();
void modificar();
void ReporteTotal();
	
int main() {
	system("color 2e");
	interfazPrincipal();	
	return 0;
}


void interfazPrincipal(){
	fflush(stdin);	
	string r;
	do{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl;
		cout<<"		==================================================="<<endl;
		cout<<"				POLLERIA EXPRESS"<<endl;
		cout<<"		==================================================="<<endl<<endl<<endl;
		cout<<"		REGISTRAR venta 		---> [Marque 1]"<<endl;
		cout<<"		REPORTE de ventas		---> [Marque 2]"<<endl;
		cout<<"		ANULAR venta			---> [Marque 3]"<<endl;
		cout<<"		BUSQUEDA en el registro		---> [Marque 4]"<<endl;
		cout<<"		MODIFICAR dato de venta		---> [Marque 5]"<<endl;
		cout<<"		REPORTE de Ventas y Atenciones	---> [Marque 6]"<<endl;
		cout<<"		SALIR				---> [Marque 7]"<<endl;
		cout<<"		==================================================="<<endl<<endl<<endl;
		cout<<endl;
		cout<<"		ELIJA UNA OPCION [1 - 7] : ";
		cin>>r;
	} while(r!="1" and r!="2" and r!="3" and r!="4" and r!="5" and r!="6" and r!="7");
	
	int n=stoi(r.c_str()); 
	
	switch(n){
		case 1: ingresar();break;
		case 2: consultar();break;
		case 3: eliminar();break;
		case 4: buscar();break;
		case 5: modificar();break;
		case 6: ReporteTotal();break;
	}	
}
	
	void ingresar(){
		ofstream escritura;
		ifstream lectura;
		
		
		int costo, nlineas, nOp=0, nOpAux;
		string nCliente, nClienteAux; 
		int nPollos, nCpollos;

		
		system("cls");
		fflush(stdin);
		cout<<endl<<endl<<endl;
		cout<<"=================== POLLERIAS EXPRESS ==================="<<endl<<endl;
		escritura.open("RegistroVentas.txt",ios::app);
		lectura.open("RegistroVentas.txt",ios::in);
		if(escritura.is_open() && lectura.is_open()){
			cout<<"	Nombre del Cliente : ";
			getline(cin,nCliente);
			replace(nCliente.begin(),nCliente.end(),' ','|');
			nlineas = 0;
			while(!lectura.eof()){
				lectura>>nOp>>nClienteAux>>nCpollos>>nPollos>>costo;
				if(!nCliente.empty()) {
					nlineas++;
					nOp+=1;
				}			
			}
			cout<<endl;
			cout<<" 	Numero de Pedido : "<<nOp<<endl<<endl;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"	Precios : "<<endl;
			cout<<"	[1/4 pollo + papas + ensalada] = 20 soles"<<endl;
			cout<<"	[1 Pollo   + papas + ensalada] = 70 soles"<<endl;
			cout<<"--------------------------------------------------"<<endl<<endl;
			cout<<"	Cantidad de 1/4 de Pollo : ";
			cin>>nCpollos;
			cout<<"	Cantidad de Pollos       : ";
			cin>>nPollos;
			
			int nCpollosAux=(20*nCpollos);
			int nPollosAux=(70*nPollos);
			costo=(nCpollosAux+nPollosAux);
			
			cout<<endl<<endl<<"		Subtotal Cuartos de Pollo : S/. "<<nCpollosAux<<" soles"<<endl;
			cout<<"		Subtotal Pollos Completos : S/. "<<nPollosAux<<" soles"<<endl;
			cout<<endl<<"		Total a Pagar : S/. "<<costo<<" soles"<<endl<<endl;
			
			if(nlineas >= 1){
				escritura<<endl;
			}
							
			escritura<<nOp<<" "<<nCliente<<" "<<nCpollos<<" "<<nPollos<<" "<<costo;
		}else{
			cout<<"Error al intentar cargar archivo"<<endl;
		}
		escritura.close();
		lectura.close();
		system("pause");
		interfazPrincipal();
	}
		
void consultar(){
	fflush(stdin);
	ifstream lectura; 
	int costo, nOp, nPollos, nCpollos;
	string nCliente, nClienteAux; 
	//int nPollos, nCpollos;
	
	system("cls");
	fflush(stdin);
	//cout<<"********************INGRESO DE ESTUDIANTES********************"<<endl<<endl;
	lectura.open("RegistroVentas.txt", ios::in);
	if(lectura.is_open()){
		while(!lectura.eof()){
			cout<<"-----------------------------------------------------------------------------"<<endl;
			
			lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
			replace(nCliente.begin(), nCliente.end(), '|',' ');
			
			cout<<"Numero Pedido			-> "<<nOp<<endl;
			cout<<"Cliente				: "<<nCliente<<endl;
			cout<<"Cantidad de 1/4 de pollo	: "<<nCpollos<<endl;
			cout<<"Cantidad de Pollo(s) 		: "<<nPollos<<endl;
			cout<<"TOTAL A PAGAR 			: S/. "<<costo<<" soles"<<endl;
		}
	getch();	
	}
	else{
		cout<<"Error al abrir archivo...";
	}
	lectura.close();
	system("pause");
	interfazPrincipal();
}


void eliminar(){
	ofstream auxiliar;
	ifstream lectura;	
	
	int costo, nOp, opEliminar, nPollos, nCpollos;;
	string nCliente;
	
	bool escribio = false, elimino = false;
		
	system("cls");
	fflush(stdin);
	cout<<"********************ANULAR PEDIDO********************"<<endl<<endl;
	
	auxiliar.open("auxReg.txt", ios::out); //desde el inicio se creara con out
	lectura.open("RegistroVentas.txt", ios::in);
	
	if(auxiliar.is_open() && lectura.is_open()){
		cout<<"Ingrese el numero de pedido a eliminar: ";
		cin>>opEliminar;
		
		while(!lectura.eof()){
			
			lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
			if(nOp != opEliminar){
				if(escribio==true){
					auxiliar<<endl;
				}
				
				auxiliar<<nOp<<" "<<nCliente<<" "<<nCpollos<<" "<<nPollos<<" "<<costo;
				escribio=true;
			}
			else{
				cout<<"Op             :" <<nOp<<endl;
				cout<<"Cliente        :" <<nCliente<<endl;
				cout<<"1/4 de pollo   : "<<nCpollos<<endl;
				cout<<"Pollos pedidos : "<<nPollos<<endl;
				elimino=true;
			}
		}
	}
	else{
		cout<<"Error al abrir archivo...";
	}
	auxiliar.close();
	lectura.close();	
	if(elimino==true){		
		cout<<endl<<"....Eliminado exitosamente..."<<endl<<endl;		
		remove("RegistroVentas.txt");
		rename("auxReg.txt", "RegistroVentas.txt");

	}
	else{
		remove("auxReg.txt");
		cout<<"Numero de Pedido No Existe..."<<endl;
	}
	system("pause");
	interfazPrincipal();
}
	
void buscar(){
	ifstream lectura; 
	
	int costo, nOp, nPollos, nCpollos, auxOp;
	string nCliente;
	bool encontrado=false;
	system("cls");
	fflush(stdin);
	lectura.open("RegistroVentas.txt", ios::in);
	//int unidPed=0;
	
	if(lectura.is_open()){
		cout<<">>>>> Ingrese Numero de Operacion : ";
		cin>>auxOp;
		while(!lectura.eof()){
			
			lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
			if (auxOp==nOp){
			system("cls");	
			encontrado=true;
			cout<<"-----------------------------------------------------------------------------"<<endl;
			replace(nCliente.begin(), nCliente.end(), '|',' ');
			cout<<endl<<endl<<":::::::::::::::::: RESULTADOS DE LA BUSQUEDA ::::::::::::::::::"<<endl;
			cout<<"Numero Pedido			-> "<<nOp<<endl;
			cout<<"Cliente				: "<<nCliente<<endl;
			cout<<"Cantidad de 1/4 de pollo	: "<<nCpollos<<endl;
			cout<<"Cantidad de Pollo(s) 		: "<<nPollos<<endl;
			cout<<"TOTAL A PAGAR 			: S/. "<<costo<<" soles"<<endl;
			//unidPed=nPollos+nCpollos;
			//cout<<endl<<"unidades pedidas : "<<unidPed<<endl;
			getch();
			}
			if(encontrado==false){
				system("cls");
				cout<<"No hay registros de venta con el numero : "<<auxOp<<endl;
			}
			
		}
	}
	else{
		cout<<"Error al abrir archivo...";
	}
	lectura.close();
	system("pause");
	interfazPrincipal();
}
	
void modificar(){
	ofstream auxiliar;
	ifstream lectura;
	bool encontrado=false;
	
	
	
	int costo, nlineas, nOp, nOpAux;
		string nCliente, nClienteAux; 
		int nPollos, nCpollos;
		
	system("cls");
	fflush(stdin);	
		
	auxiliar.open("auxiliar.txt", ios::app);
	lectura.open("RegistroVentas.txt", ios::in);
	if(auxiliar.is_open() && lectura.is_open()){
		cout<<"Ingresar numero de operacion para modificar: ";
		cin>>nOpAux;
		//lectura>>nOp;
		
		while(!lectura.eof()){
			lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
			
			if (nOpAux!=nOp){
				auxiliar<<nOp<<" "<<nCliente<<" "<<nCpollos<<" "<<nPollos<<" "<<costo<<endl;
			}
			if	(nOpAux==nOp){
				encontrado=true;
				cout<<"Mostrando Datos de la Venta : "<<endl;
				cout<<"Nro. Operacion : "<<nOpAux<<endl;
				cout<<"Cliente : "<<nCliente<<endl;
				cout<<"Cantidad de 1/4 de Pollo      : "<<nCpollos<<endl;
				cout<<"Cantidad de Pollos a la Brasa : "<<nPollos<<endl;
				cout<<"Total a Pagar :               S/. "<<costo<<" soles"<<endl;
				cout<<"--------------------------------------------------------"<<endl;
				cout<<"	Cantidad de 1/4 de Pollo : ";
				int aux1c, aux1p;
				cin>>aux1c;
				cout<<"	Cantidad de Pollos       : ";
				cin>>aux1p;				
				int nCpollosAux=(20*aux1c);
				int nPollosAux=(70*aux1p);
				int Ncosto=(nCpollosAux+nPollosAux);
				auxiliar<<nOpAux<<" "<<nCliente<<" "<<aux1c<<" "<<aux1p<<" "<<Ncosto<<endl;				
			}
			//lectura>>nOp;
			//lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
		}
		
	}else{
		cout<<" No pudo abrirse el archivo..."<<endl;
	}
	if (encontrado==false){
		cout<<"No se encontro ningun registro de venta con dicho numero..."<<endl;
	}
	fflush(stdin);
	auxiliar.close();
	lectura.close();
	remove("RegistroVentas.txt");
	rename("auxiliar.txt", "RegistroVentas.txt");
	system("pause");
	interfazPrincipal();
}
								
void ReporteTotal(){
	ifstream lectura; 
	
	int costo, nOp, nPollos, nCpollos, auxOp;
	string nCliente;
	bool encontrado=false;
	system("cls");
	fflush(stdin);
	lectura.open("RegistroVentas.txt", ios::in);
	if(lectura.is_open()){
		int tVentas=0, nAten=0, cuartos=0, polloE=0;
		while(!lectura.eof()){			
			lectura>>nOp>>nCliente>>nCpollos>>nPollos>>costo;
			tVentas+=costo;
			nAten+=1;
			cuartos+=nCpollos;
			polloE+=nPollos;
		}
		
		cout<<endl<<"	>>>> REPORTE TOTAL DE INGRESOS Y NUMERO DE ATENCIONES TOTALES <<<< "<<endl<<endl;
		
		cout<<"	-> Total de Ingresos por Ventas  		: S/. "<<tVentas<<".00 Soles"<<endl;
		cout<<"	-> Total de Numero de Atenciones 		: "<<nAten<<" Operaciones"<<endl<<endl;
		cout<<"	-> Numero de Cuartos de Pollo Vendidos		: "<<cuartos<<endl;
		cout<<"	-> Ingresos por de Cuartos de Pollo Vendidos	: S/."<<(cuartos*20)<<" soles"<<endl<<endl;
		cout<<"	-> Numero de Pollos Completos Vendidos		: "<<polloE<<endl;
		cout<<"	-> Ingresos por de Pollos Completos Vendidos	: S/."<<(polloE*70)<<" soles"<<endl<<endl;
		getch();
	}
	else{
		cout<<"Error al abrir archivo...";
	}
	lectura.close();
	system("pause");
	interfazPrincipal();
}			
