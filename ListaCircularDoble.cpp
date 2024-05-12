#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

struct nodo{
	int nro;
	string codigo;
	struct nodo *ant;
	struct nodo *sgte;

};

typedef struct nodo *TpLista;// crear tipo de dato struct nodo

void menu(){
	system("CLS");
	cout<<"\n\t LISTA CIRCULARES DOBLES\n\n";
	cout<<"1.- Insertar nodo a lista doblemente enlazada"<<endl;
	cout<<"2.- Extraer nodos"<<endl;
	cout<<"0.- Salir "<<endl<<endl;

	cout<<"Ingresar Opcion--->  "<<endl;
}

//**************GENERACION DE RANDOMS *************
// Function to convert an integer to a string
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Function to generate a random code
string generarCodigo() {
    return "C" + intToString(rand() % 99 + 1);
}

int generarNumero() {
    return rand() % 201 + 100;
}


//**************************************************

//*************LISTA ENLAZADA DOBLE****************

 TpLista CrearNodo(){
 		TpLista nuevo=NULL;
 		nuevo=new(struct nodo);
 		nuevo->nro=generarNumero();
		nuevo->codigo=generarCodigo();

		nuevo->sgte=nuevo;
		nuevo->ant=nuevo;

 		return nuevo;
  }

 void InsertarInicio_DoblementeEnlazada(TpLista &lista){
 	TpLista q=NULL;
	 q = CrearNodo();
	if(lista == NULL){
		lista=q;
		lista->sgte = lista;
		lista->ant= lista;
	}
	else{
		lista->ant->sgte= q;
		q->ant=lista->ant;
		q->sgte=lista;
		lista->ant=q;
		lista=q;
	}
	
  }



void mostrarLista_DoblementeEnlazada(TpLista lista)
{
	if(lista==NULL){
		cout<< "Lista esta vacia."<< endl;
	}

	int i=0;
	TpLista t=lista, q=NULL;
	cout<<"\n Lista de IDA"<<endl<<endl;

	

	do{
		cout<< " "<<i+1<<")  "<<t->codigo<<" - "<<t->nro<< endl;
		q=t;
		t=t->sgte;
		i++;

	}while( t != lista );


	cout<<"************";
	i=0;
	cout<<"\n Lista de REGRESO"<<endl<<endl;
	t=q;

	do{
		cout<< " "<<i+1<<")  "<<t->codigo<<" - "<<t->nro<< endl;
		q=t;
		t=t->ant;
		i++;

	}while( t != lista->ant );


}
void EliminarInicio(TpLista &lista){
	TpLista t=lista;
	if(lista ==NULL){
		cout<<"\nERROR: Lista vacia, no permite esta opcion"<<endl;
	}
	else if(lista->sgte==lista){
		lista=NULL;
		cout<<"\nNodo eliminado Codigo: "<<t->codigo<<"Nr. "<<t->nro<<endl<<endl;
	}
	else{
		lista->ant->sgte= lista->sgte;
		lista->sgte->ant= lista->ant;
		lista=lista->sgte;
		t->sgte=NULL;
		t->ant=NULL;
		cout<<"\nNodo eliminado Codigo: "<<t->codigo<<"Nr. "<<t->nro<<endl<<endl;
	}
	return;
}

void EliminarPosicion(TpLista &lista, int pos){
	TpLista p=lista;
	int x=1;
	bool flag=false;

	if(lista ==NULL){
		cout<<"\nERROR: Lista vacia, no permite esta opcion"<<endl;
	}
	if(pos==1){
		EliminarInicio(lista);
		return;
	}

	while(p->sgte != NULL && x != pos){
		p=p->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag==true){
		p->ant->sgte= p->sgte;
		p->sgte->ant=p->ant;
		p->sgte=NULL;
		p->ant=NULL;
	 	cout<<"\nNodo eliminado Codigo: "<<p->codigo<<"Nr. "<<p->nro<<endl<<endl;
	}
	else{
		cout<<"ERROR: Posicion No Existe en la Lista"<<endl;
	}



}

//***************************************************************


//*************LISTA ENLAZADA SIMPLE****************************
 void InsertarInicio_SimpleEnlazada(TpLista &lista, TpLista q){
	q->sgte = lista;
	lista=q;

 }

 void mostrarLista_SimpleEnlazada(TpLista lista){
	TpLista t=lista;
	while(t != NULL ){
		cout<<"codigo = "<<t->codigo<<" nro= "<<t->nro<<" --> ";
		t=t->sgte;
	}
	cout<<" NULL"<<endl;
}

//************************************************************



//*************OPCIONES****************************

void extraerNodos(TpLista &listaDoble, TpLista& lista){
    
    int pos;
    int ciclo=0;
	TpLista t=listaDoble;

    while(listaDoble!=NULL){
        ciclo++;
		cout<<"\n\n\tCICLO "<<ciclo<<endl;

		//resta -50 a cada nodo
        do{
            t->nro=t->nro -50;
            t=t->sgte;   
        }while( t!= listaDoble);
		

		cout<<"\n\nLISTA INICIO"<<endl<<endl;
		mostrarLista_DoblementeEnlazada(listaDoble);

		cout<<"\n\nLISTA EXTRAIDOS"<<endl<<endl;
		mostrarLista_SimpleEnlazada(lista);


		
		//revisa si hay elementos <=0
		bool flag;
		do{
			t=listaDoble;
			pos=1;
			flag=false;
			do{
				
				if(t->nro<=0){
					EliminarPosicion(listaDoble,pos);
					InsertarInicio_SimpleEnlazada(lista,t);

					flag=true;
					break;
				}
				t=t->sgte;
				pos++;	
			}while( t!= listaDoble);

		}while(flag==true&&listaDoble!=NULL);
    }

}

//************************************************************




int main() {
    srand(time(0));
	int opc;
	TpLista listaDoble=NULL, lista=NULL;// variable gusrada el inicio de la lista

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
			    cout<<"\n\nLISTA INICIO"<<endl<<endl;
				InsertarInicio_DoblementeEnlazada(listaDoble);

				mostrarLista_DoblementeEnlazada(listaDoble);

				cout<<"\n\nLISTA EXTRAIDOS"<<endl<<endl;
				mostrarLista_SimpleEnlazada(lista);
				system("pause");
				break;
				}

			case 2:{
                cout<<"\n\nLISTA INICIO"<<endl<<endl;
                mostrarLista_DoblementeEnlazada(listaDoble);
                cout<<"\n\nLISTA EXTRAIDOS"<<endl<<endl;
				mostrarLista_SimpleEnlazada(lista);

				extraerNodos(listaDoble,lista);
				
				cout<<"\n\nLISTA INICIO"<<endl<<endl;
				if(listaDoble!=NULL){
                	mostrarLista_DoblementeEnlazada(listaDoble);
				}
				else{
				cout<<"Lista esta vacia.";
				}
                cout<<"\n\nLISTA EXTRAIDOS"<<endl<<endl;
				mostrarLista_SimpleEnlazada(lista);

				system("pause");
				break;
				}
		}

	}while(opc !=0);
	system("pause");

	return 0;
}

