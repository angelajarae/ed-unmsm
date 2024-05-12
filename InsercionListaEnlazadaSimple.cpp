#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
};

typedef struct nodo *TpLista;//Crea tipo de dato struct nodo


//Funciones de lista enlazada simple
TpLista CrearNodo(int numero){
	TpLista q=NULL;

	q = new(struct nodo);
	q->nro = numero;
	q->sgte=NULL;

	return q;
}
void InsertarInicio(TpLista &lista, TpLista nodo){
	TpLista q=nodo;
	q->sgte = lista;
	lista=q;
}
void InsertarFinal(TpLista &lista, TpLista nodo){
	TpLista q=nodo, p=lista;

	if(lista==NULL){
		lista=q;
	}
	else{
		while(p->sgte != NULL){
			p=p->sgte;
		}
		p->sgte=q;
	}
}
void VerLista(TpLista lista)
{
	int i=0;
	while(lista != NULL){
		cout<< " "<<i+1<<")  "<<lista->nro<< endl;
		lista=lista->sgte;
		i++;
	}

}
//


//Opciones de menú
void insertarNodo(TpLista &lista){
    int numeroAl = -99 + (rand() % (99 - (-99) + 1));

    if(numeroAl>0){
        InsertarFinal(lista,CrearNodo(numeroAl));
    }
    else{
        InsertarInicio(lista,CrearNodo(numeroAl));
    }
}
void VerLista(TpLista lista){
    int nNodos=0;
    int mayor = lista->nro, menor = lista->nro, posMayor = 1, posMenor = 1, suma = 0;

    while(lista != NULL){
        if(lista->nro>mayor){
            mayor=lista->nro;
            posMayor=nNodos+1;
        }
        if(lista->nro<menor){
            menor=lista->nro;
            posMenor=nNodos+1;
        }

        suma=suma+lista->nro;
		lista=lista->sgte;
		nNodos++;
	}

	cout<<"Numero de nodos: "<<nNodos<<endl;
	cout<<"Promedio de valores: "<<suma/nNodos<<endl;
	cout<<"Mayor: "<<mayor<<endl;
	cout<<"Posicion mayor: "<<posMayor<<endl;
	cout<<"Menor: "<<menor<<endl;
	cout<<"Posicion menor: "<<posMenor<<endl;
}
//


void menu(){
	system("CLS");
	cout<<"\nLAB 2: Inserta nodo al inicio o final segun signo.\n\n";

	cout<<"1.- Insertar nodo "<<endl;
	cout<<"2.- Mostrar lista "<<endl;
	cout<<"0.- Salir "<<endl<<endl;

	cout<<"Ingresar Opcion--->  "<<endl;
}


int main() {
	TpLista lista=NULL;
    srand(static_cast<unsigned int>(time(0)));
	int opc;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
                insertarNodo(lista);
				VerLista(lista);
                system("pause");
				break;
				}

			case 2:{
			    VerLista(lista);
                VerLista(lista);
                system("pause");
				break;
				}
		}

	}while(opc !=0);
	system("pause");

	return 0;
}


