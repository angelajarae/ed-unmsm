#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodo{
	int codigo;
	string tipoEnvio;
	struct nodo *sgte;
};

typedef struct nodo *TpLista; // Crear un nuevo tipo de dato de forma puntero



void menu(){

	system("CLS");
	cout<<"\n\t LAB 4\n\n";
	cout<<"1.- Registrar sobre"<<endl;
	cout<<"2.- Distribuir sobres"<<endl;
	cout<<"3.- Enviar sobre"<<endl;
	cout<<"4.- Mostrar listas"<<endl;
	cout<<"0.- Salir"<<endl<<endl;

	cout<<"Ingresar Opcion---> "<<endl;
}


void verLista(TpLista l){
	TpLista lista = l;
	int i=0;
	while(lista != NULL){
		cout<<" "<<i+1<<") "<<lista->codigo<<":"<<lista->tipoEnvio<<endl;
		lista=lista->sgte;
		i++;
	}

}


//**************FUNCIONES DE COLAS *************
// FUncion Insertar al FInal (ENCOLAR)
void encolar(TpLista &cola, TpLista nodo){
	TpLista nuevo=nodo, p=cola;
	//ir al final de la ista

	if(cola == NULL)
		cola = nuevo;
	else{
		while(p->sgte != NULL)
			p=p->sgte;
		p->sgte =nuevo;

	}
}
// FUncion DESENCOLAR elimina el primer elemento
void desencolar(TpLista &cola){
	TpLista t=cola;
	cola=cola->sgte;
	cout<<"\nNodo eliminado es "<<t->codigo<<":"<<t->tipoEnvio<<endl<<endl;
	delete(t);
}




//**************FUNCIONES DE PILAS *************
// POP extrae un nodo desde el inicio de una PILA
TpLista pop(TpLista &lista){
	TpLista t=lista;
	if(lista == NULL){
		cout<<"ERROR: Lista vacia.. no permite esta opcion"<<endl;
		system("pause");
		return t;
	}
	lista=lista->sgte;
	t->	sgte=NULL;
	return t;
}

void push(TpLista &lista, TpLista q){
	if(lista !=NULL){
		q->sgte=lista;
	}
	lista =q;

}

//**************GENERACION DE RANDOMS *************
string generarTipoEnvio() {
    srand(time(0));
    int n=rand() % 2 + 1;

    if(n==1){
    	return "Nacional";
	}
    else{
    	return "Internacional";
	}
}


int generarCodigo() {
    srand(time(0));
    return rand() % 99 + 1;
}

//**************OPCIONES *************
void registrarSobre(TpLista &pilaSobres,int &nSobresRecibidos){
	if(nSobresRecibidos<8){
		TpLista sobre=new(struct nodo);
		sobre->codigo=generarCodigo();
		sobre->tipoEnvio=generarTipoEnvio();
        sobre->sgte=NULL;
		push(pilaSobres,sobre);
	}
	else{
		cout<<"No se pueden recibir más sobres"<<endl;
	}

	nSobresRecibidos++;
}


void distribuirSobres(TpLista &pilaSobres,TpLista &colaNacionales,TpLista &colaInternacionales){
    while(pilaSobres!=NULL){
        TpLista sobre=pop(pilaSobres);

        if(sobre->tipoEnvio=="Nacional"){
            encolar(colaNacionales,sobre);
        }
        else{
            encolar(colaInternacionales,sobre);
        }
    }
}
void enviarSobre(TpLista &cola){
    desencolar(cola);
}

void mostrarListas(TpLista pilaSobres,TpLista colaNacionales,TpLista colaInternacionales){
	cout<<"*******SOBRES RECIBIDOS **********"<<endl<<endl;

    verLista(pilaSobres);



	cout<<"*******ENVIOS NACIONALES **********"<<endl<<endl;

    verLista(colaNacionales);


	cout<<"*******ENVIOS INTERNACIONALES  **********"<<endl<<endl;

    verLista(colaInternacionales);



}


int main(){

	TpLista pilaSobres=NULL,colaNacionales=NULL,colaInternacionales=NULL;
	int nSobresRecibidos=0;
	int opc;

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{

				registrarSobre(pilaSobres,nSobresRecibidos);
				mostrarListas(pilaSobres,colaNacionales,colaInternacionales);

				system("pause");
				break;
			}
			case 2:{
                distribuirSobres(pilaSobres,colaNacionales,colaInternacionales);
                mostrarListas(pilaSobres,colaNacionales,colaInternacionales);
				system("pause");
				break;
			}

			case 3:{
                string tipoEnvio;
                cout<<"Indicar tipo de sobre a enviar (nacional/internacional): ";
                cin>>tipoEnvio;

                if(tipoEnvio=="nacional"){
                    enviarSobre(colaNacionales);
                }
                else if(tipoEnvio=="internacional"){
                    enviarSobre(colaInternacionales);
                }

                mostrarListas(pilaSobres,colaNacionales,colaInternacionales);
				system("pause");
				break;
			}

			case 4:{
                mostrarListas(pilaSobres,colaNacionales,colaInternacionales);
				system("pause");
				break;
			}

		}//switch


	}while(opc != 0);


	return 0;
}
